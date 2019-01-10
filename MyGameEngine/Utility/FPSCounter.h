//
// FPSCounter.h
// 
#pragma once


// ライブラリの提示 --------------------------------------------------------------
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")
#pragma comment(lib, "dxguid.lib")


// ヘッダーファイルのインクルード ------------------------------------------------
#include <windows.h>
#include <timeapi.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <DirectXColors.h>


// クラスの定義 -----------------------------------------------------------------
namespace MyLibrary
{
	namespace Utility
	{
		/// <summary>
		/// FPS表示クラス
		/// </summary>
		class FPSCounter
		{
		public:

			static const float FONT_SIZE;	// フォントサイズ


		public:

			// コンストラクタ
			FPSCounter();
			// デストラクタ
			~FPSCounter();

			// 更新処理
			void Update();

			// フレームレートの取得
			int GetFrame() { return m_renderFrameCount; }


		private:

			int m_frameCount;		// フレームカウント
			int m_renderFrameCount;	// 描画フレームカウント
		};
	}
}
