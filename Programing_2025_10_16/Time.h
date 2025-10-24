#pragma once

class Time
{
private:
	double m_currentFrame; // ���݂̃t���[��
	double m_previousFrame; // �ߋ��̃t���[��
	double m_deltaTime; // �t���[���Ԃ̍���

private:
	// �R���X�g���N�^�E�R�s�[�֎~
	Time();                          // �O������new�ł��Ȃ�
	Time(const Time&) = delete;      // �R�s�[�֎~
	Time& operator=(const Time&) = delete; // ����֎~

public:
	virtual ~Time(); // �f�X�g���N�^

public:
	// �C���X�^���X
	static Time& GetInstance();
	
public:
	void Update(); // �X�V

public:

	double DeltaTime(); // �f���^�^�C���̎擾
};