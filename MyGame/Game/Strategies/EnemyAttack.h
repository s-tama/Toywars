//
// EnemyAttack.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "EnemyStrategy.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 「発射」戦略
	/// </summary>
	class EnemyAttack : public EnemyStrategy
	{
	public:

		// コンストラクタ
		EnemyAttack(AI* pAI);

		// 実行
		void Execute(float elapsedTime) override;


	private:
	};
}
