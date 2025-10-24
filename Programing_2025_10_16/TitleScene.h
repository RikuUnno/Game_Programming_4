#pragma once
#include "SceneBase.h"

class TitleScene
	: public SceneBase
{
public: // コンストラクタ
	TitleScene();
	virtual ~TitleScene();

public: // 進行
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public: // 表示
	void Draw() override;
};