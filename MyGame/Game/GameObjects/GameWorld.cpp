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



// usingディレクティブ -----------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;



// メンバ関数の定義 --------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
GameWorld::GameWorld():
	m_pNodeManager(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void GameWorld::Initialize(NodeManager* pNodeManager)
{
	m_pNodeManager = pNodeManager;

	// 追加
	m_pNodeManager->AddNode(new Stage);			// ステージ
	m_pNodeManager->AddNode(new Player);		// プレイヤー
//	m_pNodeManager->AddNode(new ToyBox);		// おもちゃ箱

	// 障害物
	Obstacle* pBlocks[9] = { nullptr };
	for (int i = 0; i < 9; i++)
	{
		pBlocks[i] = new Obstacle();
		int x = (i % 3) * 30 - 30;
		int z = (i / 3) * 30 - 30;
		pBlocks[i]->GetTransform()->SetPosition(static_cast<float>(x), 0, static_cast<float>(z));
		m_pNodeManager->AddNode(pBlocks[i]);
	}
}
