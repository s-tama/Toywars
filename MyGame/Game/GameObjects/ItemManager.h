//
// ItemManager.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ---------------------------------------------------------
namespace MyGame
{
	class ItemBox;
}


// クラスの定義 ---------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 障害物クラス
	/// </summary>
	class ItemManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		ItemManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// アイテムマネージャーにアイテムを登録する
		void EntryItem(ItemBox* pItem);

		// アイテム配列を取得する
		inline std::list<ItemBox*> GetItemList();


	private:

		std::list<ItemBox*> m_itemList;		// アイテムリスト
		float m_time;						// タイマー
	};
}

