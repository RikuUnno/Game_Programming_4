// ���̃N���X���p������Ǝg����悤�ɂ���
// ���̂�
// �A��
// �����ꂽ
// �f���I

#pragma once
#include "Time.h"

class KeyInput // �L�[�̏���
{
private:
	int m_currntKey;		// ���݂̃L�[
	int m_previousKey;		// �ߋ��i�O�t���[���j�̃L�[
	bool IsKeyInputON;		// ���͂�����
	double m_repeatedTime;	// �J��Ԃ��Ԋu
	double m_repeatedTimer;  // �J��Ԃ����Ԃ𑪂���

private:
	Time timer;

public:
	KeyInput();
	virtual ~KeyInput();

public:
	bool IsKeyInputTrigger(int KeyCode);	// ���̂ݕԂ�
	bool IsKeyInputHeld(int KeyCode);		// �A�����ĕԂ�
	bool IsKeyInputReleased(int KeyCode);	// �����ꂽ��Ԃ�
	bool IsKeyInputRepeated(int KeyCode);	// ���܂������o�Œf���I�ɕԂ�

public:
	void SetInputRepeatedTime(float SetTime); // �f���I�ɕԂ��ꍇ�̎��ԃZ�b�^�[

public:
	void BeginKeyInput();
	void EndKeyInput();

};