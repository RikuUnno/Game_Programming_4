#include "KeyInput.h"
#include "DxLib.h"

KeyInput::KeyInput()
{
	m_currntKey = NULL;
	m_previousKey = NULL;
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

	CheckHitKey(KeyCode) ? m_currntKey = KeyCode : m_currntKey = NULL; // ���݂̉������̍X�V

	((m_currntKey != m_previousKey) && (m_currntKey != NULL)) ? flag = true : flag = false;

	m_previousKey = m_currntKey; // ���t���[���ׂ̈ɓ���ւ�

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

	CheckHitKey(KeyCode) ? m_currntKey = KeyCode : m_currntKey = NULL; // ���݂̉������̍X�V

	((m_previousKey == KeyCode) && (m_currntKey == NULL)) ? flag = true : flag = false;

	m_previousKey = m_currntKey; // ���t���[���ׂ̈ɓ���ւ�

#ifdef _DEBUG
    // �f�o�b�O�\��
    DrawFormatString(0, 75, 0xFFFFFF, "Flag: %d", flag);
#endif // _DEBUG

	return flag;
}

bool KeyInput::IsKeyInputRepeated(int KeyCode)
{
    if (!IsKeyInputON) return false;

    timer.Update(); // �f���^�^�C��  �X�V
    bool flag = false;

    // �L�[��������Ă���ꍇ
    if (CheckHitKey(KeyCode))
    {
        m_repeatedTimer += m_repeatedTime * timer.DeltaTime();

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
    DrawFormatString(0, 75, 0xFFFFFF, "DeltaTime: %f", timer.DeltaTime());
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