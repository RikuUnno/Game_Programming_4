#include "DxLib.h"
#include "SceneBase.h"
#include "TitleScene.h"

#include "KeyInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE); // �E�C���h�E���[�h�ŋN��

    SetGraphMode(1280, 720, 32); // ��ʃT�C�Y�̃Z�b�g

   // SetWaitVSyncFlag(FALSE); // �񐂒�������

    if (DxLib_Init() == -1)		// �c�w���C�u��������������
    {
        return -1;			// �G���[���N�����璼���ɏI��
    }
    
    SceneBase* pRootScene = new TitleScene;
    pRootScene->Start();




    // �`����ʂ𗠉�ʂɃZ�b�g
    SetDrawScreen(DX_SCREEN_BACK);

    // �L�[���������܂Ń��[�v
    while (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ProcessMessage() == 0)
    {
        clsDx();
        ClearDrawScreen();

        Time::GetInstance().Update(); // ���Ԋ֌W�̍X�V

        SceneBase* nextScene = pRootScene->Update();
        if (nextScene != pRootScene)
        {// �قȂ��Ă������ʑJ��
            pRootScene->End();
            delete pRootScene;

            pRootScene = nextScene;
            pRootScene->Start();
        }

        // �`��
        pRootScene->Draw();

        ScreenFlip();
    }

	return 0;				// �\�t�g�̏I�� 
}

