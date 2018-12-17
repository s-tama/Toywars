//
// AI_Level0.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "AI_Level0.h"

#include "EnemyStrategy.h"
#include "../GameObjects/Player.h"

#include "EnemyWaiting.h"
#include "EnemyAttack.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
AI_Level0::AI_Level0(Enemy* pEnemy):
	AI(pEnemy),
	m_pTarget(nullptr),
	m_time(0),
	m_timef(0)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void AI_Level0::Initialize()
{
	// プレイヤーオブジェクトを取得する
	m_pTarget = m_pEnemy->GetNodeManager()->GetNode()->FindGameObjectWithTag("Player");

	// 戦略リストを作成
	EnemyWaiting::GetInstance()->Initialize(this);
	EnemyAttack::GetInstance()->Initialize(this);

	// 戦略を初期化する
	m_pCurrentStrategy = EnemyWaiting::GetInstance();
}

/// <summary>
/// 思考
/// </summary>
void AI_Level0::Think(float elapsedTime)
{
	if (m_pEnemy == nullptr) return;

	Quaternion rot = m_pEnemy->GetTransform()->GetRotation();
	if ((m_time > 300) && (m_time < 600))
	{
		if (rot.y < Quaternion::CreateFromAxisAngle(m_pEnemy->GetTransform()->GetUp(), XMConvertToRadians(90)).y)
		{
			m_pEnemy->GetTransform()->Rotate(m_pEnemy->GetTransform()->GetUp(), 90 * elapsedTime);
		}
	}
	else if((m_time >= 600) && (m_time < 900))
	{
		if (rot.y < Quaternion::CreateFromAxisAngle(m_pEnemy->GetTransform()->GetUp(), XMConvertToRadians(90)).y)
		{
			m_pEnemy->GetTransform()->Rotate(m_pEnemy->GetTransform()->GetUp(), 90 * elapsedTime);
		}
	}

	// 一定間隔で弾を発射する
	if (m_time % 30 == 0)
	{
		ChangeStrategy(EnemyAttack::GetInstance());
	}
	else
	{
		ChangeStrategy(EnemyWaiting::GetInstance());
	}

	// 現在の戦略を実行
	if (m_pCurrentStrategy != nullptr)
	{
		m_pCurrentStrategy->Execute(elapsedTime);
	}
	
	m_timef += elapsedTime;
	m_time++;
	//m_time %= 10000;
}





// ターゲットが陣地内に入ってきたら攻撃する
//if (Math::Distance(m_pTarget->GetTransform()->GetPosition(), m_pEnemy->GetTransform()->GetPosition()) < 5)
//{
//	m_pStrategyList[0]->Flag().On(m_pStrategyList[0]->IS_START);
//}

//// 待機に移動
//{
//	for (auto it : m_pStrategyList)
//	{
//		if (it->Flag().Check(it->IS_START))
//		{
//			it->Execute(elapsedTime);
//		}
//	}
//}

/*if (Math::Distance(m_pTarget->GetTransform()->GetPosition(), m_pEnemy->GetTransform()->GetPosition()) < 5)
{
m_pStrategyList[0]->Flag().On(m_pStrategyList[0]->IS_START);
}*/

//	m_pEnemy->GetTransform()->Rotate(m_pEnemy->GetTransform()->GetUp(), Enemy::ROTATION_SPEED * elapsedTime);
