//
// EnemyManager.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "EnemyManager.h"

#include "Enemy.h"
#include "../Strategies/AI_Level0.h"



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
		m_pEnemies[i]->SetAI(new AI_Level0(m_pEnemies[i]));
		GetNodeManager()->AddNode(m_pEnemies[i]);
	}

	std::vector<int> already;
	
	for (int i = 0; i < m_pEnemies.size(); i++)
	{
		int num = Math::GetRand(0, 8);
		for (int j = 0; j < already.size(); j++)
		{
			if (already[j] != num)
			{
				m_pEnemies[i]->GetTransform()->SetPosition(Enemy::APPEAR_POS[num]);
				already.push_back(num);
				continue;
			}
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
