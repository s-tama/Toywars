//
// UIManager.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ---------------------------------------------------------
namespace MyGame
{
	class EnemyInfoUI;
}


// クラスの定義 ---------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 障害物クラス
	/// </summary>
	class UIManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		UIManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:
	};
}


