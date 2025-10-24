#pragma once
#include "SceneBase.h"

class GameRoot
	: public SceneBase
{
private:
	SceneBase* m_scene;

public:
	GameRoot();
	virtual ~GameRoot();

public:
	void Start() override;
	void End() override;

	SceneBase* Update() override;

public:
	void Draw() override;
};