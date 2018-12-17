//
// EnemyManager.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -----------------------------------------------------------------
namespace MyGame
{
	class Enemy;
	class Mediator;
}


// クラスの定義 -----------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 敵管理クラス
	/// </summary>
	class EnemyManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		EnemyManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// 的配列の取得
		std::vector<Enemy*> GetEnemies() { return m_pEnemies; }
		// 残り敵数の取得	
		int GetEnemyCount() { return m_enemyCount; }


	private:

		std::vector<Enemy*> m_pEnemies;		// 敵の配列
		int m_enemyCount;					// 敵の残り数
	};
}
