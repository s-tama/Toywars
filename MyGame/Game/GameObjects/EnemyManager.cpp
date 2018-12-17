//
// EnemyManager.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "EnemyManager.h"

#include "Enemy.h"
#include "Player.h"
#include "../Strategies/AI_Level0.h"
#include "../Strategies/AI_Level1.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyManager::EnemyManager():
	m_enemyCount(0)
{
	SetTag("EnemyManager");
}

/// <summary>
/// 初期化処理
/// </summary>
void EnemyManager::Initialize()
{
	m_pEnemies.resize(3);
	for (int i = 0; i < 3; i++)
	{
		m_pEnemies[i] = new Enemy();
		m_pEnemies[i]->GetTransform()->SetPosition(Enemy::APPEAR_POS[Math::GetRand(0, 8)]);
		GetNodeManager()->AddNode(m_pEnemies[i]);
	}
	// 敵のAIレベルを設定
	m_pEnemies[0]->SetAI(new AI_Level0(m_pEnemies[0]));
	m_pEnemies[1]->SetAI(new AI_Level1(m_pEnemies[1]));
	m_pEnemies[2]->SetAI(new AI_Level0(m_pEnemies[2]));

	
	for (int i = 0; i < m_pEnemies.size(); i++)
	{
		int num = Math::GetRand(0, 8);
		m_pEnemies[i]->GetTransform()->SetPosition(Enemy::APPEAR_POS[num]);
	}

	// 位置を再設定する
	GameObject* pObj = GetNodeManager()->GetNode()->FindGameObjectWithTag("Player");
	Player* pPlayer = dynamic_cast<Player*>(pObj);
	for (auto it1 : m_pEnemies)
	{
		for (auto it2 : m_pEnemies)
		{
			int num = Math::GetRand(0, 8);
			it1->GetTransform()->SetPosition(Enemy::APPEAR_POS[num]);

			if (it1->GetTransform()->GetPosition() == it2->GetTransform()->GetPosition())
				continue;
			if (it1->GetTransform()->GetPosition() == pPlayer->GetTransform()->GetPosition())
				continue;
			if (it2->GetTransform()->GetPosition() == pPlayer->GetTransform()->GetPosition())
				continue;
		}
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void EnemyManager::Update(float elapsedTime)
{
	m_enemyCount = 0;
	for (auto it : m_pEnemies)
	{
		if (it->IsActive() == true)
		{
			m_enemyCount++;
		}
	}
}
