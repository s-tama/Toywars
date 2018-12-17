//
// EnemyInfoUI.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class EnemyManager;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 背景画像クラス
	/// </summary>
	class EnemyInfoUI : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		EnemyInfoUI();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:

		// エネミーマネージャーへのポインタ
		EnemyManager* m_pEnemyManager;
	};
}
