//
// AI_Level1.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "AI_Level1.h"

#include "../GameObjects/Player.h"

#include "EnemyWaiting.h"
#include "EnemyAttack.h"
#include "EnemyWandering.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の実態を定義 ---------------------------------------------------
// 方向
const float AI_Level1::DIRECTION[4] = { 0, 90, 180, 270 };



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
AI_Level1::AI_Level1(Enemy* pEnemy) :
	AI(pEnemy),
	m_pTarget(nullptr),
	m_time(0),
	m_timef(0)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void AI_Level1::Initialize()
{
	// プレイヤーオブジェクトを取得する
	m_pTarget = m_pEnemy->GetNodeManager()->GetNode()->FindGameObjectWithTag("Player");

	// 戦略を初期化する
	m_pCurrentStrategy = new EnemyWaiting(this);
}

/// <summary>
/// 思考
/// </summary>
void AI_Level1::Think(float elapsedTime)
{
	if (m_pEnemy == nullptr) return;

	// 一定の行動をとる
	Transform* pTrans = m_pEnemy->GetTransform();
	Vector3 axis = pTrans->GetUp();
	if (m_time % 180 == 0)
	{
		// 向きを設定
		float dir = XMConvertToRadians(DIRECTION[Math::GetRand(0, 4)]);
		pTrans->SetRotation(Quaternion::CreateFromAxisAngle(axis, dir));
	}
	else
	{
		// 徘徊行動
		ChangeStrategy(new EnemyWandering(this));
	}

	m_timef += elapsedTime;
	m_time++;
	m_time %= 1000;
}