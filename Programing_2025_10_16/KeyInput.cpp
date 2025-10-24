#include "KeyInput.h"
#include "DxLib.h"
#include <algorithm>

KeyInput::KeyInput()
{
    std::fill(std::begin(m_currntKey), std::end(m_currntKey), 0);
    std::fill(std::begin(m_previousKey), std::end(m_previousKey), 0);
	IsKeyInputON = false;
	m_repeatedTime = 10.0f;
	m_repeatedTimer = m_repeatedTime;
}

KeyInput::~KeyInput()
{}

bool KeyInput::IsKeyInputTrigger(int KeyCode)
{
	if (!IsKeyInputON) return false;

	bool flag = false;

    GetHitKeyStateAll(m_currntKey); // ���݂̉������̍X�V

	((m_currntKey[KeyCode] != m_previousKey[KeyCode]) && (m_currntKey[KeyCode] != NULL)) ? flag = true : flag = false;

	m_previousKey[KeyCode] = m_currntKey[KeyCode]; // ���t���[���ׂ̈ɓ���ւ�

#ifdef _DEBUG
    // �f�o�b�O�\��
    DrawFormatString(0, 75, 0xFFFFFF, "RepeatFlag: %d", flag);
#endif // _DEBUG

	return flag;
}

bool KeyInput::IsKeyInputHeld(int KeyCode)
{
	if (!IsKeyInputON) return false;

	return CheckHitKey(KeyCode); // �A���ŕԂ�
}

bool KeyInput::IsKeyInputReleased(int KeyCode)
{
	if (!IsKeyInputON) return false;

	bool flag = false;

    GetHitKeyStateAll(m_currntKey); // ���݂̉������̍X�V

	((m_previousKey[KeyCode] == 1) && (m_currntKey[KeyCode] == NULL)) ? flag = true : flag = false;

	m_previousKey[KeyCode] = m_currntKey[KeyCode]; // ���t���[���ׂ̈ɓ���ւ�

#ifdef _DEBUG
    // �f�o�b�O�\��
    DrawFormatString(0, 75, 0xFFFFFF, "Flag: %d", flag);
#endif // _DEBUG

	return flag;
}

bool KeyInput::IsKeyInputRepeated(int KeyCode)
{
    if (!IsKeyInputON) return false;

    bool flag = false;

    GetHitKeyStateAll(m_currntKey);

    // �L�[��������Ă���ꍇ
    if (m_currntKey[KeyCode] == 1)
    {
        m_repeatedTimer += m_repeatedTime * Time::GetInstance().DeltaTime();

        // ��莞�Ԃ𒴂����烊�s�[�g����
        if (m_repeatedTimer >= m_repeatedTime)
        {
            flag = true;
            m_repeatedTimer = 0.0f; // �^�C�}�[���Z�b�g���Ď�
        }
    }
    else
    {
        // �L�[�������ꂽ�烊�Z�b�g
        m_repeatedTimer = m_repeatedTime;
    }

#ifdef _DEBUG
    // �f�o�b�O�\��
    DrawFormatString(0, 75, 0xFFFFFF, "DeltaTime: %f", Time::GetInstance().DeltaTime());
    DrawFormatString(0, 90, 0xFFFFFF, "m_repeatedTimer: %f", m_repeatedTimer);
    DrawFormatString(0, 105, 0xFFFFFF, "Flag: %d", flag);
#endif // _DEBUG

    return flag;
}

void KeyInput::SetInputRepeatedTime(float SetTime)
{
	m_repeatedTime = SetTime; // �������̐��l�ɕύX	
}

void KeyInput::BeginKeyInput()
{
    IsKeyInputON = true;
}

void KeyInput::EndKeyInput()
{
    IsKeyInputON = false;
}