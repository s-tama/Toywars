//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "EnemyInfoUI.h"

#include "EnemyManager.h"
#include "Enemy.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyInfoUI::EnemyInfoUI()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void EnemyInfoUI::Initialize()
{
	// エネミーマネージャーの作成
	GameObject* pObj = NodeManager::FindGameObjectWithTag("EnemyManager");
	m_pEnemyManager = dynamic_cast<EnemyManager*>(pObj);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void EnemyInfoUI::Update(float elapsedTime)
{
	int enemyNum = m_pEnemyManager->GetEnemyCount();
//	GameText::GetInstance()->AddText(Vector2(6, 10), Colors::Black, 2.1f, L"敵の数 %d", enemyNum);
//	GameText::GetInstance()->AddText(Vector2(10, 10), Colors::White, 2, L"敵の数 %d", enemyNum);
}
