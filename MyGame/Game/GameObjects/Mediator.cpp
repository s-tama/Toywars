//
// Mediator.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------
#include "Mediator.h"

#include "BulletManager.h"
#include "GameWorld.h"
#include "Player.h"
#include "Enemy.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Mediator::Mediator():
	m_pBulletManager(nullptr),
	m_pNodeManager(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Mediator::Initialize()
{
	GameObject* pPlayer = m_pNodeManager->GetNode()->FindGameObjectWithTag("Player");
	dynamic_cast<Player*>(pPlayer)->SetMediator(this);
	std::vector<GameObject*> pEnemy = m_pNodeManager->GetNode()->FindGameObjectsWithTag("Enemy");
	for (auto it : pEnemy)
	{
		dynamic_cast<Enemy*>(it)->SetMediator(this);
	}
}

/// <summary>
/// バレットマネージャーへのポインタを設定
/// </summary>
/// <param name="pBulletManager">バレットマネージャーへのポインタ</param>
void Mediator::SetBulletManager(BulletManager* pBulletManager)
{
	m_pBulletManager = pBulletManager;
}

/// <summary>
/// バレットマネージャーのポインタを取得
/// </summary>
/// <returns>バレットマネージャーへのポインタ</returns>
BulletManager* MyGame::Mediator::GetBulletManager()
{
	return m_pBulletManager;
}

/// <summary>
/// ノードマネージャーへのポインタを設定
/// </summary>
/// <param name="pNodeManager">ノードマネージャーへのポインタ</param>
void Mediator::SetNodeManager(NodeManager* pNodeManager)
{
	m_pNodeManager = pNodeManager;
}

/// <summary>
/// ノードマネージャーのポインタを取得
/// </summary>
/// <returns>ノードマネージャーへのポインタ</returns>
NodeManager* MyGame::Mediator::GetNodeManager()
{
	return m_pNodeManager;
}
