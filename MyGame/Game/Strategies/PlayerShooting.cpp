//
// PlayerShooting.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "PlayerShooting.h"

#include "../GameObjects/Mediator.h"
#include "../GameObjects/BulletManager.h"
#include "../GameObjects/Bullet.h"

#include "PlayerNone.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -------------------------------------------------------
std::unique_ptr<PlayerShooting> PlayerShooting::m_pInstance = nullptr;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
PlayerShooting::PlayerShooting():
	m_shootInterval(0)
{
}

/// <summary>
/// クラスのインスタンスを取得する
/// </summary>
/// <returns>インスタンス</returns>
PlayerShooting* PlayerShooting::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new PlayerShooting);
	return m_pInstance.get();
}

/// <summary>
/// 実行
/// </summary>
void PlayerShooting::Execute(float elapsedTime)
{
	if (m_pPlayer == nullptr) return;

	m_shootInterval++;
	m_shootInterval %= SHOOT_INTERVAL;
	/*if (m_shootInterval % SHOOT_INTERVAL == 0)
	{*/
		std::vector<Bullet*> pBullets = m_pPlayer->GetMediator()->GetBulletManager()->GetBullets();
		const int bulletSize = pBullets.size();
		for (int i = 0; i < bulletSize; i++)
		{
			// 弾が「非アクティブ」状態の場合
			if (pBullets[i]->IsActive() != true)
			{
				// 弾の回転を設定する
				pBullets[i]->GetTransform()->SetRotation(m_pPlayer->GetTransform()->GetRotation());
				// 回転情報をもとに弾の座標を設定する
				pBullets[i]->GetTransform()->SetPosition(m_pPlayer->GetTransform()->GetPosition());
				pBullets[i]->GetTransform()->Translate(-1.5f, 2, 1);
				// 弾の所有者を設定する
				pBullets[i]->SetOwner(m_pPlayer);
				// 弾を「アクティブ」状態にする
				pBullets[i]->SetActive(true);
				break;
			}
		}
	//}

	// プレイヤーの戦略を「無し」に変更
	m_pPlayer->ChangeStrategy(PlayerNone::GetInstance());
}
