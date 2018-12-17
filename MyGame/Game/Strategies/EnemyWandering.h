//
// EnemyWandering.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "EnemyStrategy.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 戦略無し状態
	/// </summary>
	class EnemyWandering : public EnemyStrategy
	{
	public:

		// コンストラクタ
		EnemyWandering(AI* pAI);

		// 実行
		void Execute(float elapsedTime) override;


	private:
	};
}

