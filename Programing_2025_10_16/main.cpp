#include "DxLib.h"
#include "SceneBase.h"
#include "TitleScene.h"

#include "KeyInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE); // �E�C���h�E���[�h�ŋN��

    SetGraphMode(1280, 720, 32); // ��ʃT�C�Y�̃Z�b�g

    SetWaitVSyncFlag(FALSE); // �񐂒�������

    if (DxLib_Init() == -1)		// �c�w���C�u��������������
    {
        return -1;			// �G���[���N�����璼���ɏI��
    }
    
    SceneBase* pRootScene = new TitleScene;
    pRootScene->Start();

    KeyInput key;

    // �`����ʂ𗠉�ʂɃZ�b�g
    SetDrawScreen(DX_SCREEN_BACK);

    // �L�[���������܂Ń��[�v
    while (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ProcessMessage() == 0)
    {
        clsDx();
        ClearDrawScreen();


        // ~~~�L�[�̃f�o�b�O~~~
        key.BeginKeyInput();

        key.SetInputRepeatedTime(0.4f);
        if (key.IsKeyInputRepeated(KEY_INPUT_D))
        {
            DrawString(0, 60, "INPUTtoD", 0xFFFFFF);
        }

        key.EndKeyInput();
        // ~~~~~~~~~~~~~~~~~~~

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

	//return 0;				// �\�t�g�̏I�� 
}