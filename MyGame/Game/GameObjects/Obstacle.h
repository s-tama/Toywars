//
// Obstacle.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


// クラスの定義 ---------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 障害物クラス
	/// </summary>
	class Obstacle : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Obstacle();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;
	};
}
