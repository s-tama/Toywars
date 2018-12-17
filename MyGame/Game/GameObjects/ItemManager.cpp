//
// ItemManager.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "ItemManager.h"

#include "ItemBox.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
ItemManager::ItemManager():
	m_time(0)
{
	SetTag("ItemManager");
}

/// <summary>
/// 初期化処理
/// </summary>
void ItemManager::Initialize()
{
	ItemBox* pReflect = new ItemBox();
	pReflect->SetTag("Bullet_Reflect");
	pReflect->GetTransform()->SetPosition(ItemBox::APPEAR_POS[Math::GetRand(8)]);
	GetNodeManager()->AddNode(pReflect);
	m_pItems.push_back(pReflect);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ItemManager::Update(float elapsedTime)
{
	for (auto it : m_pItems)
	{
		if (it->IsActive() == false)
		{
			if (m_time > 10)
			{
				// アイテムボックスを再配置する
				it->GetTransform()->SetPosition(ItemBox::APPEAR_POS[Math::GetRand(8)]);
				// アイテムボックスを「アクティブ」状態にする
				it->SetActive(true);

				// タイマーをリセット
				m_time = 0;
			}
			m_time += elapsedTime;
		}
	}
}
