#pragma once
#include "SceneBase.h"

class TitleScene
	: public SceneBase
{
public: // �R���X�g���N�^
	TitleScene();
	virtual ~TitleScene();

public: // �i�s
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public: // �\��
	void Draw() override;
};