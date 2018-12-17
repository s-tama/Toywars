//
// WinMain.cpp
//



// 定数の定義 -------------------------------------------------------------------------
#define STRICT					// 型チェックを厳密に行う
#define WIN32_LEAN_AND_MEAN		// ヘッダーからあまり使われない関数を省く
#define _WIN32_WINNT 0x600		// Windows Vista 以降対応アプリを指定

#define SAFE_RELEASE(x) { if(x) { (x)->Release(); (x) = nullptr; } }	// 開放用マクロ



// ヘッダーファイルのインクルード -----------------------------------------------------
#include <windows.h>

#include "Game/Game.h"



// 関数の定義 -------------------------------------------------------------------------
/// <summary>
/// ウィンドウズメイン関数
/// </summary>
/// <param name="hInstance">現在のインスタンスハンドル</param>
/// <param name="hPrevInstance">以前のインスタンスハンドル</param>
/// <param name="wParam">コマンドライン</param>
/// <param name="iCmdShow">表示状態</param>
/// <returns></returns>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	// フレームワークの作成
	std::unique_ptr<MyLibrary::Framework> pFramework = std::make_unique<Game>(hInstance, nCmdShow);

	pFramework->InitializeD3D();	// Direct3D初期化処理

	// ゲームのメインループ
	MSG msg = {};
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			pFramework->Tick();		// ゲームの基本ループ
		}
	}

	pFramework->FinalizeD3D();	// Direct3D終了処理
	pFramework.reset();			// 開放
	CoUninitialize();			// アプリケーション終了処理

	return (int)msg.wParam;		// 終了
}

/// <summary>
/// ゲームを終了させる
/// </summary>
void ExitGame()
{
	PostQuitMessage(0);
}