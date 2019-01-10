//
// Mediator.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------
#include "Mediator.h"

#include "BulletManager.h"
#include "EffectFactory.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Mediator::Mediator():
	m_pBulletManager(nullptr)
{
	SetTag("Mediator");
}

/// <summary>
/// 初期化処理
/// </summary>
void Mediator::Initialize()
{
	// バレットマネージャーへのポインタを設定する
	GameObject* pBulletManager = NodeManager::FindGameObjectWithTag("BulletManager");
	m_pBulletManager = dynamic_cast<BulletManager*>(pBulletManager);

	// エフェクトファクトリーへのポインタを設定する
	GameObject* pEffectFactory = NodeManager::FindGameObjectWithTag("EffectFactory");
	m_pEffectFactory = dynamic_cast<MyGame::EffectFactory*>(pEffectFactory);
}

/// <summary>
/// バレットマネージャーのポインタを取得
/// </summary>
/// <returns>バレットマネージャーへのポインタ</returns>
BulletManager* MyGame::Mediator::GetBulletManager() const
{
	return m_pBulletManager;
}

/// <summary>
/// エフェクトファクトリーへのポインタを取得
/// </summary>
/// <returns></returns>
EffectFactory* MyGame::Mediator::GetEffectFactory() const
{
	return m_pEffectFactory;
}
