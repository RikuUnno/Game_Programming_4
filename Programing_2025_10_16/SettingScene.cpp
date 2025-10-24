#include "SettingScene.h"
#include "TitleScene.h"
#include "DxLib.h"

SettingScene::SettingScene()
{

}

SettingScene::~SettingScene()
{

}

void SettingScene::Start()
{

}

void SettingScene::End()
{

}

SceneBase* SettingScene::Update()
{
    BeginKeyInput();

    if (IsKeyInputTrigger(KEY_INPUT_T))
    {
        return new TitleScene();
    }

    EndKeyInput();

    return this;
}

void SettingScene::Draw()
{
	DrawString(0, 0, "SETTING MENU", 0xFFFFFF);
	DrawString(0, 20, "T RETURN", 0xFFFFFF);

}
