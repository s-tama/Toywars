//
// EnemyAttack.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "EnemyAttack.h"

#include "../GameObjects/Mediator.h"
#include "../GameObjects/BulletManager.h"
#include "../GameObjects/Bullet.h"

#include "EnemyWaiting.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyAttack::EnemyAttack(AI* pAI):
	EnemyStrategy(pAI)
{
}

/// <summary>
/// 実行
/// </summary>
void EnemyAttack::Execute(float elapsedTime)
{
	if (m_pAI == nullptr) return;

	std::vector<Bullet*> pBullets = m_pAI->GetEnemy()->GetMediator()->GetBulletManager()->GetBullets();
	const int bulletSize = pBullets.size();
	for (int i = 0; i < bulletSize; i++)
	{
		// 弾が「非アクティブ」状態の場合
		if (pBullets[i]->IsActive() != true)
		{
			// 弾の回転を設定する
			pBullets[i]->GetTransform()->SetRotation(m_pAI->GetEnemy()->GetTransform()->GetRotation());
			// 回転情報をもとに弾の座標を設定する
			pBullets[i]->GetTransform()->SetPosition(m_pAI->GetEnemy()->GetTransform()->GetPosition());
			pBullets[i]->GetTransform()->Translate(-1.5f, 2, 1);
			// 弾の所有者を設定する
			pBullets[i]->SetOwner(m_pAI->GetEnemy());
			// 弾を「アクティブ」状態にする
			pBullets[i]->SetActive(true);
			break;
		}
	}
}
