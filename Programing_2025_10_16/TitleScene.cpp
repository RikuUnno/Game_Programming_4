#include "TitleScene.h"
#include "SettingScene.h"
#include "GameRoot.h"
#include "DxLib.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Start()
{

}

void TitleScene::End()
{

}

SceneBase* TitleScene::Update()
{
	BeginKeyInput();

	if (IsKeyInputTrigger(KEY_INPUT_X))
	{
		return new SettingScene();
	}
	else if (IsKeyInputTrigger(KEY_INPUT_Z))
	{
		return new GameRoot();
	}

	EndKeyInput();

	return this;
}

void TitleScene::Draw()
{
	DrawString(0, 0, "TITLE", 0xFFFFFF);
	DrawString(0, 20, "Z START", 0xFFFFFF);
	DrawString(0, 40, "X SETTING", 0xFFFFFF);
}
