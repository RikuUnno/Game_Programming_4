#pragma once
#include "SceneBase.h"

class SettingScene
	: public SceneBase
{
public: // �R���X�g���N�^
	SettingScene();
	virtual ~SettingScene();

public: // �i�s
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public: // �\��
	void Draw() override;
};