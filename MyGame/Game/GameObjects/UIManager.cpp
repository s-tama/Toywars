//
// UIManager.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "UIManager.h"

#include "EnemyInfoUI.h"
#include "PlayerInfoUI.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
UIManager::UIManager()
{
	SetTag("UIManager");
}

/// <summary>
/// 初期化処理
/// </summary>
void UIManager::Initialize()
{
	// 敵情報
	EnemyInfoUI* pEnemyInfoUI = new EnemyInfoUI();
	NodeManager::AddNode(pEnemyInfoUI);

	// プレイヤー情報
	PlayerInfoUI* pPlayerInfoUI = new PlayerInfoUI();
	NodeManager::AddNode(pPlayerInfoUI);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void UIManager::Update(float elapsedTime)
{
}
