//
// ToyBox.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
}


// クラスの定義 ---------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// おもちゃ箱クラス
	/// </summary>
	class ToyBox : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		ToyBox();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;
	};
}

