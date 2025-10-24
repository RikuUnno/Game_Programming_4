#pragma once
#include "SceneBase.h"

class SettingScene
	: public SceneBase
{
public: // コンストラクタ
	SettingScene();
	virtual ~SettingScene();

public: // 進行
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public: // 表示
	void Draw() override;
};