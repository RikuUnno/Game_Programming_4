#include "MainGameScene.h"
#include "TitleScene.h"
#include "DxLib.h"

MainGameScene::MainGameScene()
{

}

MainGameScene::~MainGameScene()
{

}

void MainGameScene::Start()
{

}

void MainGameScene::End()
{

}

SceneBase* MainGameScene::Update()
{
    BeginKeyInput();

    if (IsKeyInputTrigger(KEY_INPUT_Z))
    {
        return new TitleScene();
    }

    EndKeyInput();

	return this;
}

void MainGameScene::Draw()
{
	DrawString(0, 0, "MainGame!", 0xFFFFFF);
	DrawString(0, 20, "Z TITLE", 0xFFFFFF);
}