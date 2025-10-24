// このクラスを継承すると使えるようにする
// 一回のみ
// 連続
// 離された
// 断続的

#pragma once
#include "Time.h"

class KeyInput // キーの処理
{
private:
	char m_currntKey[256];		// 現在のキー
	char m_previousKey[256];	// 過去（前フレーム）のキー
	bool IsKeyInputON;			// 入力を許可
	double m_repeatedTime;		// 繰り返す間隔
	double m_repeatedTimer;		// 繰り返す時間を測るやつ

protected:

	KeyInput();
	virtual ~KeyInput();

public:
	bool IsKeyInputTrigger(int KeyCode);	// 一回のみ返す
	bool IsKeyInputHeld(int KeyCode);		// 連続して返す
	bool IsKeyInputReleased(int KeyCode);	// 離されたら返す
	bool IsKeyInputRepeated(int KeyCode);	// 決まった感覚で断続的に返す

public:
	void SetInputRepeatedTime(float SetTime); // 断続的に返す場合の時間セッター

public:
	void BeginKeyInput();
	void EndKeyInput();

};