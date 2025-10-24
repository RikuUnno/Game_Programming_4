#include "DxLib.h"
#include "SceneBase.h"
#include "TitleScene.h"

#include "KeyInput.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE); // ウインドウモードで起動

    SetGraphMode(1280, 720, 32); // 画面サイズのセット

    SetWaitVSyncFlag(FALSE); // 非垂直同期化

    if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
    {
        return -1;			// エラーが起きたら直ちに終了
    }
    
    SceneBase* pRootScene = new TitleScene;
    pRootScene->Start();

    KeyInput key;

    // 描画先画面を裏画面にセット
    SetDrawScreen(DX_SCREEN_BACK);

    // キーが押されるまでループ
    while (CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ProcessMessage() == 0)
    {
        clsDx();
        ClearDrawScreen();


        // ~~~キーのデバッグ~~~
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
        {// 異なっていたら画面遷移
            pRootScene->End();
            delete pRootScene;

            pRootScene = nextScene;
            pRootScene->Start();
        }

        // 描画
        pRootScene->Draw();

        ScreenFlip();
    }

	//return 0;				// ソフトの終了 
}