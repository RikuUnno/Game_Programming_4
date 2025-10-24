#pragma once

class SceneBase
{
public:
	SceneBase() {}
	virtual ~SceneBase() {}

public:
	virtual void Start() = 0;
	virtual void End() = 0;

	virtual SceneBase* Update() = 0;

public:
	virtual void Draw() = 0;
};
