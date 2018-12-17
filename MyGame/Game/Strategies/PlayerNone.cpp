//
// PlayerNone.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "PlayerNone.h"

#include "PlayerShooting.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -------------------------------------------------------
std::unique_ptr<PlayerNone> PlayerNone::m_pInstance = nullptr;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// クラスのインスタンスを取得する
/// </summary>
/// <returns>インスタンス</returns>
PlayerNone* PlayerNone::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new PlayerNone);
	return m_pInstance.get();
}

/// <summary>
/// 実行
/// </summary>
void PlayerNone::Execute(float elapsedTime)
{
	// キーが押されたかの判定
	const bool isZ = (System::InputDevice::GetInstance()->GetKeyState().Z);
	const bool isL = (System::InputDevice::GetInstance()->GetKeyState().L);
	const bool isZ_trg = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::Z));
	const bool isL_trg = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::L));

	// 戦略を切り替える
	if (isL_trg)
	{
		// 弾発射
		m_pPlayer->ChangeStrategy(PlayerShooting::GetInstance());
	}
}
