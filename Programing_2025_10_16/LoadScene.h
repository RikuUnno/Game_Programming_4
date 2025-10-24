#pragma once
#include "GameScene.h"

class LoadScene
	: public GameScene
{
private:
	int _cnt = 0;

public:
	LoadScene();
	virtual ~LoadScene();

public:
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public:
	void Draw() override;
};