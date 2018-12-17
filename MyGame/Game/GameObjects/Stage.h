//
// Stage.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
}


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// ステージクラス
	/// </summary>
	class Stage : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Stage();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;
	};
}