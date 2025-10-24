#include "DxLib.h"
#include "GameRoot.h"
#include "SceneBase.h"

#include "LoadScene.h"

GameRoot::GameRoot()
{
    m_scene = new LoadScene();
}

GameRoot::~GameRoot()
{
    if (m_scene != nullptr)
    {
        delete m_scene;
        m_scene = nullptr;
    }
}


void GameRoot::Start()
{

}

void GameRoot::End()
{

}

SceneBase* GameRoot::Update()
{
    SceneBase* nextScene = m_scene->Update();
    if (nextScene != m_scene)
    {// �؂�ւ��w��

        // Scene��GameScene������̂���dynamic_cast
        GameScene* scene = dynamic_cast<GameScene*>(nextScene);
        if (scene == nullptr)
        {// �����ł͏����ł��Ȃ��̂ł���ɏ�ɕԂ���B
            return nextScene;
        }

        // �Ǘ����ł̑J��
        m_scene->End();
        delete m_scene;

        // ��ʕύX
        m_scene = nextScene;
        m_scene->Start();
    }

    return this;
}


void GameRoot::Draw()
{

    if (m_scene != nullptr) m_scene->Draw();
}