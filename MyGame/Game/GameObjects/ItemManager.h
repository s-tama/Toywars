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


	private:

		std::vector<ItemBox*> m_pItems;		// アイテム
	};
}

