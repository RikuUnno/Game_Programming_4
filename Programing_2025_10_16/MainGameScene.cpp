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

    if (CheckHitKey(KEY_INPUT_T))
    {
        return new TitleScene();
    }

	return this;
}

void MainGameScene::Draw()
{
	DrawString(0, 0, "MainGame!", 0xFFFFFF);
	DrawString(0, 20, "T TITLE", 0xFFFFFF);
}