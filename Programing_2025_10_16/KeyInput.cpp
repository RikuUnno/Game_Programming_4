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

	CheckHitKey(KeyCode) ? m_currntKey = KeyCode : m_currntKey = NULL; // 現在の押下情報の更新

	((m_currntKey != m_previousKey) && (m_currntKey != NULL)) ? flag = true : flag = false;

	m_previousKey = m_currntKey; // 次フレームの為に入れ替え

#ifdef _DEBUG
    // デバッグ表示
    DrawFormatString(0, 75, 0xFFFFFF, "RepeatFlag: %d", flag);
#endif // _DEBUG

	return flag;
}

bool KeyInput::IsKeyInputHeld(int KeyCode)
{
	if (!IsKeyInputON) return false;

	return CheckHitKey(KeyCode); // 連続で返す
}

bool KeyInput::IsKeyInputReleased(int KeyCode)
{
	if (!IsKeyInputON) return false;

	bool flag = false;

	CheckHitKey(KeyCode) ? m_currntKey = KeyCode : m_currntKey = NULL; // 現在の押下情報の更新

	((m_previousKey == KeyCode) && (m_currntKey == NULL)) ? flag = true : flag = false;

	m_previousKey = m_currntKey; // 次フレームの為に入れ替え

#ifdef _DEBUG
    // デバッグ表示
    DrawFormatString(0, 75, 0xFFFFFF, "Flag: %d", flag);
#endif // _DEBUG

	return flag;
}

bool KeyInput::IsKeyInputRepeated(int KeyCode)
{
    if (!IsKeyInputON) return false;

    timer.Update(); // デルタタイム  更新
    bool flag = false;

    // キーが押されている場合
    if (CheckHitKey(KeyCode))
    {
        m_repeatedTimer += m_repeatedTime * timer.DeltaTime();

        // 一定時間を超えたらリピート判定
        if (m_repeatedTimer >= m_repeatedTime)
        {
            flag = true;
            m_repeatedTimer = 0.0f; // タイマーリセットして次
        }
    }
    else
    {
        // キーが離されたらリセット
        m_repeatedTimer = m_repeatedTime;
    }

#ifdef _DEBUG
    // デバッグ表示
    DrawFormatString(0, 75, 0xFFFFFF, "DeltaTime: %f", timer.DeltaTime());
    DrawFormatString(0, 90, 0xFFFFFF, "m_repeatedTimer: %f", m_repeatedTimer);
    DrawFormatString(0, 105, 0xFFFFFF, "Flag: %d", flag);
#endif // _DEBUG

    return flag;
}

void KeyInput::SetInputRepeatedTime(float SetTime)
{
	m_repeatedTime = SetTime; // 引数内の数値に変更	
}

void KeyInput::BeginKeyInput()
{
    IsKeyInputON = true;
}

void KeyInput::EndKeyInput()
{
    IsKeyInputON = false;
}