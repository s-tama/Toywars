//
// EnemyWandering.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "EnemyWandering.h"

#include "EnemyAttack.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyWandering::EnemyWandering(AI* pAI) :
	EnemyStrategy(pAI),
	m_time(0)
{
}

/// <summary>
/// 実行
/// </summary>
void EnemyWandering::Execute(float elapsedTime)
{
	// 徘徊する
	m_pAI->GetEnemy()->GetTransform()->Translate(0, 0, Enemy::ADVANCE_SPEED * elapsedTime);
}
