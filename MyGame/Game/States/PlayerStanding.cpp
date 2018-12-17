//
// PlayerStanding.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "PlayerStanding.h"

#include "PlayerMoving.h"
#include "../Strategies/PlayerShooting.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -------------------------------------------------------
std::unique_ptr<PlayerStanding> PlayerStanding::m_pInstance = nullptr;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// クラスのインスタンスを取得する
/// </summary>
/// <returns>インスタンス</returns>
PlayerStanding* PlayerStanding::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new PlayerStanding);
	return m_pInstance.get();
}

/// <summary>
/// 実行
/// </summary>
void PlayerStanding::Execute(float elapsedTime)
{
	if (m_pPlayer == nullptr) return;

	// キーが押されたかのフラグ定数
	const bool isUp = (System::InputDevice::GetInstance()->GetKeyState().W != false);
	const bool isDown = (System::InputDevice::GetInstance()->GetKeyState().S != false);
	const bool isRight = (System::InputDevice::GetInstance()->GetKeyState().D != false);
	const bool isLeft = (System::InputDevice::GetInstance()->GetKeyState().A != false);
	const bool isX = (System::InputDevice::GetInstance()->GetKeyState().X != false);
	const bool isC = (System::InputDevice::GetInstance()->GetKeyState().C != false);

	// 移動キーが押されたら、プレイヤーを「移動」状態に変更する
	if (isUp || isDown || isRight || isLeft || isX)
	{
		m_pPlayer->ChangeState(PlayerMoving::GetInstance());
	}
}
