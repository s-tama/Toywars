//
// InputDevice.h
// 作成者: 玉村柊希
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <Keyboard.h>
#include <Mouse.h>
#include <Xinput.h>


// クラスの定義 -------------------------------------------------------------------------
namespace MyLibrary
{
	namespace System
	{
		// 入力デバイスクラス
		class InputDevice
		{
		private:

			// コンストラクタ
			InputDevice();


		public:

			// クラスのインスタンスを取得
			static InputDevice* GetInstance();

			// マウスの状態の取得
			DirectX::Mouse::State GetMouseState();

			// マウストラッカーの取得
			DirectX::Mouse::ButtonStateTracker GetMouseTracker();

			// マウス座標の取得
			DirectX::SimpleMath::Vector2 GetMousePosition();

			// キーの状態の取得
			DirectX::Keyboard::State GetKeyState();

			// キーボードトラッカーの取得
			DirectX::Keyboard::KeyboardStateTracker GetKeyTracker();

			// ゲームパッド状態の取得
			XINPUT_STATE* GetXInputState();

			// 更新処理
			void Update();


		private:

			// インスタンス
			static std::unique_ptr<InputDevice> m_pInstance;

			// マウス
			std::unique_ptr<DirectX::Mouse> m_pMouse;

			// キーボード
			std::unique_ptr<DirectX::Keyboard> m_pKeyboard;

			// ゲームパッド
			std::unique_ptr<XINPUT_STATE> m_pXInputState;

			// マウストラッカー
			DirectX::Mouse::ButtonStateTracker m_mouseTracker;

			// キートラッカー
			DirectX::Keyboard::KeyboardStateTracker m_keyTracker;
		};
	}
}
