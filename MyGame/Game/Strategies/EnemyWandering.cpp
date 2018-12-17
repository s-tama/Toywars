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
	Vector3 pos = m_pAI->GetEnemy()->GetTransform()->GetPosition();
	Vector3 trans = -m_pAI->GetEnemy()->GetTransform()->GetForward() * Enemy::ADVANCE_SPEED * elapsedTime;
	pos += trans;
	m_pAI->GetEnemy()->GetTransform()->SetPosition(pos);

	pos = m_pAI->GetEnemy()->GetTransform()->GetPosition();
	if (Math::Abs(pos.x) > 48)
	{
		pos.x -= trans.x;
		m_pAI->GetEnemy()->GetTransform()->SetPosition(pos);
	}
	pos = m_pAI->GetEnemy()->GetTransform()->GetPosition();
	if (Math::Abs(pos.z) > 48)
	{
		pos.z -= trans.z;
		m_pAI->GetEnemy()->GetTransform()->SetPosition(pos);
	}

	for (auto obstacles : m_pAI->GetEnemy()->GetObstacles())
	{
		Vector3 pPos = m_pAI->GetEnemy()->GetTransform()->GetPosition();
		Vector3 oPos = obstacles->GetTransform()->GetPosition();
		if ((Math::Distance(pPos.x, oPos.x) < 11)
			&& (Math::Distance(pPos.z, oPos.z) < 11))
		{
			pos -= trans;
			m_pAI->GetEnemy()->GetTransform()->SetPosition(pos);
		}
	}
}
