#pragma once
#include "GameScene.h"

class MainGameScene
	: public GameScene
{
public:
	MainGameScene();
	virtual ~MainGameScene();

public:
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public:
	void Draw() override;
};