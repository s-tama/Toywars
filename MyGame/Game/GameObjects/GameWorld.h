//
// GameWorld.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -----------------------------------------------------------------------
namespace MyGame
{
	class Stage;
	class Player;
}


// クラスの定義 -----------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// ゲーム内クラス
	/// </summary>
	class GameWorld
	{
	public:

		// コンストラクタ
		GameWorld();

		// 初期化処理
		void Initialize();


	private:
	};
}
