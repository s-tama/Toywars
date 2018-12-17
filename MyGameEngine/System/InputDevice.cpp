//
// InputDevice.cpp
//

#include "InputDevice.h"

using namespace MyLibrary;
using namespace System;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// 静的メンバ変数の実態
std::unique_ptr<InputDevice> InputDevice::m_pInstance = nullptr;

/// <summary>
/// コンストラクタ
/// </summary>
InputDevice::InputDevice()
{
	// マウスの作成
	m_pMouse = std::make_unique<Mouse>();

	// キーボードの作成
	m_pKeyboard = std::make_unique<Keyboard>();

	// ゲームパッドの作成
	m_pXInputState = std::make_unique<XINPUT_STATE>();
}

/// <summary>
/// クラスのインスタンスを取得
/// </summary>
/// <returns></returns>
InputDevice* InputDevice::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new InputDevice());
	return m_pInstance.get();
}

/// <summary>
/// マウスの状態の取得
/// </summary>
/// <returns></returns>
Mouse::State InputDevice::GetMouseState()
{
	return m_pMouse->GetState();
}

/// <summary>
/// マウストラッカーの取得
/// </summary>
/// <returns></returns>
Mouse::ButtonStateTracker InputDevice::GetMouseTracker()
{
	return m_mouseTracker;
}

/// <summary>
/// マウス座標の取得
/// </summary>
/// <returns></returns>
Vector2 InputDevice::GetMousePosition()
{
	return DirectX::SimpleMath::Vector2();
}

/// <summary>
/// キーボードの状態の取得
/// </summary>
/// <returns></returns>
Keyboard::State InputDevice::GetKeyState()
{
	return m_pKeyboard->GetState();
}

/// <summary>
/// キートラッカーを取得
/// </summary>
/// <returns></returns>
Keyboard::KeyboardStateTracker InputDevice::GetKeyTracker()
{
	return m_keyTracker;
}

/// <summary>
/// ゲームパッドの状態を取得
/// </summary>
/// <returns>入力状態</returns>
XINPUT_STATE* InputDevice::GetXInputState()
{
	return m_pXInputState.get();
}

/// <summary>
/// 更新処理
/// </summary>
void InputDevice::Update()
{
	// マウスの更新
	DirectX::Mouse::State mouseState = GetMouseState();
	m_mouseTracker.Update(mouseState);

	// キーボードの更新
	DirectX::Keyboard::State keyState = GetKeyState();
	m_keyTracker.Update(keyState);

	// ゲームパッドの更新
	//XInputGetState(0, m_pXInputState.get());
}
