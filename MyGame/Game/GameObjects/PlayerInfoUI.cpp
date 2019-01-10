//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "PlayerInfoUI.h"

#include "Player.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
PlayerInfoUI::PlayerInfoUI()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void PlayerInfoUI::Initialize()
{
	// エネミーマネージャーの作成
	GameObject* pObj = NodeManager::FindGameObjectWithTag("Player");
	m_pPlayer = dynamic_cast<Player*>(pObj);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void PlayerInfoUI::Update(float elapsedTime)
{
	int num = m_pPlayer->PossessBulletNum();
//	GameText::GetInstance()->AddText(Vector2(6, 50), Colors::Black, 2.1f, L"弾数 %d", num);
//	GameText::GetInstance()->AddText(Vector2(10, 50), Colors::White, 2, L"弾数 %d", num);
}
