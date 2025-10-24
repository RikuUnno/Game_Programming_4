#include "LoadScene.h"
#include "MainGameScene.h"
#include "DxLib.h"

LoadScene::LoadScene()
{

}

LoadScene::~LoadScene()
{

}

void LoadScene::Start()
{

}

void LoadScene::End()
{

}

SceneBase* LoadScene::Update()
{
    _cnt++;
    if (_cnt > 300)
    {// ���t���[���o�߂������ʑJ��
        return new MainGameScene();
    }
    return this;
}

void LoadScene::Draw()
{
	DrawString(0, 0, "LOADING...", 0xFFFFFF);
}