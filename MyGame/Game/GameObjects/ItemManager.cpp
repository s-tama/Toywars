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

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ItemManager::Update(float elapsedTime)
{
	for (auto it : m_itemList)
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

/// <summary>
/// アイテムマネージャーにアイテムを登録する
/// </summary>
/// <param name="pItem">アイテムオブジェクトへのポインタ</param>
void ItemManager::EntryItem(ItemBox* pItem)
{
	pItem->GetTransform()->SetPosition(ItemBox::APPEAR_POS[Math::GetRand(8)]);
	m_itemList.push_back(pItem);
}

/// <summary>
/// アイテムリストを取得する
/// </summary>
/// <returns></returns>
inline std::list<ItemBox*> ItemManager::GetItemList()
{
	return m_itemList;
}
