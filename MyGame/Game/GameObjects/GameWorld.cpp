//
// GameWorld.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------------
#include "GameWorld.h"

#include "Stage.h"
#include "Player.h"
#include "ToyBox.h"
#include "Obstacle.h"
#include "ItemBox.h"
#include "BulletManager.h"
#include "ItemManager.h"
#include "EnemyManager.h"



// usingディレクティブ -----------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 --------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
GameWorld::GameWorld()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void GameWorld::Initialize()
{
	// 追加
	NodeManager::AddNode(new Stage);			// ステージ
	NodeManager::AddNode(new Player);		// プレイヤー
//	m_pNodeManager->AddNode(new ToyBox);		// おもちゃ箱

	// 障害物
	std::vector<Obstacle*> pBlocks;
	pBlocks.resize(9);
	for (int i = 0; i < 9; i++)
	{
		pBlocks[i] = new Obstacle();
		int x = (i % 3) * 30 - 30;
		int z = (i / 3) * 30 - 30;
		Vector3 offset(static_cast<float>(x), 0, static_cast<float>(z));
		pBlocks[i]->GetTransform()->SetPosition(offset);
		NodeManager::AddNode(pBlocks[i]);
	}

	// 弾管理オブジェクトの追加
	NodeManager::AddNode(new BulletManager);

	// アイテム管理オブジェクトの追加
	NodeManager::AddNode(new ItemManager);

	// 敵管理オブジェクトの追加
	NodeManager::AddNode(new EnemyManager);
}
