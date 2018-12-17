//
// PlayerInfoUI.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class Player;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 背景画像クラス
	/// </summary>
	class PlayerInfoUI : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		PlayerInfoUI();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:

		// エネミーマネージャーへのポインタ
		Player* m_pPlayer;
	};
}

