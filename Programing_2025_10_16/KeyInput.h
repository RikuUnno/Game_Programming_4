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
	bool IsKeyInputON;			// ���͂�����
	char m_currntKey[256];		// ���݂̃L�[
	char m_previousKey[256];	// �ߋ��i�O�t���[���j�̃L�[
	double m_repeatedTime[256];		// �J��Ԃ��Ԋu
	double m_repeatedTimer[256];		// �J��Ԃ����Ԃ𑪂���

protected:

	KeyInput();
	virtual ~KeyInput();

public:
	bool IsKeyInputTrigger(int KeyCode);	// ���̂ݕԂ�
	bool IsKeyInputHeld(int KeyCode);		// �A�����ĕԂ�
	bool IsKeyInputReleased(int KeyCode);	// �����ꂽ��Ԃ�
	bool IsKeyInputRepeated(int KeyCode);	// ���܂������o�Œf���I�ɕԂ�

public:
	void SetInputRepeatedTime(int KeyCode, double SetTime); // �f���I�ɕԂ��ꍇ�̎��ԃZ�b�^�[

public:
	void BeginKeyInput();
	void EndKeyInput();

};

// �L�[�������ꂽ���ɔ͈̓`�F�b�N����ꂽ�ق������������炭0~255
// �V�[���J�ڂ������new�����̂őO���previons�̒l�������Ă��Ȃ��̂ł����炭���̕����łQ�x���������ƂɂȂ��Ă���Ǝv���