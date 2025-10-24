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
    {// Ø‚è‘Ö‚¦w¦

        // Scene‚©GameScene‚©”»’è‚Ì‚½‚ßdynamic_cast
        GameScene* scene = dynamic_cast<GameScene*>(nextScene);
        if (scene == nullptr)
        {// ‚±‚±‚Å‚Íˆ—‚Å‚«‚È‚¢‚Ì‚Å‚³‚ç‚Éã‚É•Ô‚·‚æB
            return nextScene;
        }

        // ŠÇ—‰º‚Å‚Ì‘JˆÚ
        m_scene->End();
        delete m_scene;

        // ‰æ–Ê•ÏX
        m_scene = nextScene;
        m_scene->Start();
    }

    return this;
}


void GameRoot::Draw()
{

    if (m_scene != nullptr) m_scene->Draw();
}