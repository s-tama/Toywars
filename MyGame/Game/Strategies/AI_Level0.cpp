//
// AI_Level0.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "AI_Level0.h"

#include "../GameObjects/Player.h"

#include "EnemyWaiting.h"
#include "EnemyAttack.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の実態を定義 ---------------------------------------------------
// 方向
const float AI_Level0::DIRECTION[4] = { 0, 90, 180, 270 };



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
	m_pTarget = NodeManager::FindGameObjectWithTag("Player");

	// 戦略を初期化する
	m_pCurrentStrategy = new EnemyWaiting(this);
}

/// <summary>
/// 思考
/// </summary>
void AI_Level0::Think(float elapsedTime)
{
	if (m_pEnemy == nullptr) return;

	// 一定の行動をとる
	Transform* pTrans = m_pEnemy->GetTransform();
	Vector3 axis = pTrans->GetUp();
	if (m_time % 300 == 0)
	{
		float dir = XMConvertToRadians(DIRECTION[Math::GetRand(0, 4)]);
		pTrans->SetRotation(Quaternion::CreateFromAxisAngle(axis, dir));
	}
	
	// 一定間隔で弾を発射する
	if (m_time % 60 == 0) ChangeStrategy(new EnemyAttack(this));
	else ChangeStrategy(new EnemyWaiting(this));

	// 現在の戦略を実行
	if (m_pCurrentStrategy != nullptr)
	{
		m_pCurrentStrategy->Execute(elapsedTime);
	}
	
	m_timef += elapsedTime;
	m_time++;
	m_time %= 1000;
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
