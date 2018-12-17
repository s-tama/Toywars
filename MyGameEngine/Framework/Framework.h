//
// Framework.cpp
//
#pragma once


// ライブラリの提示 --------------------------------------------------------------
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dsound.lib")


// ヘッダーファイルのインクルード ------------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <SpriteBatch.h>

#include <Keyboard.h>
#include <Mouse.h>

#include "../Common/DeviceResources.h"
#include "../Common/StepTimer.h"


// マクロの定義 ------------------------------------------------------------------
// 開放用マクロ
#define SAFE_RELEASE(x) { if(x) { (x)->Release(); (x) = nullptr; } }


// クラスの定義 ------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// フレームワーク
	/// </summary>
	class Framework : public IDeviceNotify
	{
	public:

		// コンストラクタ
		Framework(HINSTANCE hInstance, int nCmdShow, int width = 640, int height = 480);

		// ウィンドウプロシージャー
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		// Direct3D初期化処理
		void InitializeD3D();
		// Direct3D終了処理
		void FinalizeD3D();

		// ゲームの基本ループ処理
		void Tick();

		// デバイスインターフェース通知
		virtual void OnDeviceLost() override;
		virtual void OnDeviceRestored() override;

		// メッセージ
		void OnWindowMoved();
		void OnWindowSizeChanged(int width, int height);

		// プロパティ
		void GetDefaultSize(int& width, int& height) const;


	private:

		// Direct3D描画処理
		void RenderD3D();

		// 初期化処理
		virtual void Initialize() = 0;
		// 更新処理
		virtual void Update(StepTimer const& timer) = 0;
		// 描画処理
		virtual void Render() = 0;
		// 終了処理
		virtual void Finalize() = 0;
		
		// 画面をクリア
		void Clear();

		// デバイスの作成処理
		void CreateDeviceDependentResources();
		// ウィンドウの作成処理
		void CreateWindowSizeDependentResources();

		// アプリケーション名の設定
		void SetAppName(wchar_t* pAppName)
		{
			m_pAppName = pAppName;
		}


	protected:

		// ウィンドウハンドル
		HWND m_hWnd;

		// ステップタイマー
		StepTimer m_timer;

		// アプリケーション名
		wchar_t* m_pAppName;
		// 画面幅
		int m_screenWidth;
		// 画面高さ
		int m_screenHeight;
		// 画面色
		const float* m_screenColor;
	};
}
