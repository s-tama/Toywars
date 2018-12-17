//
// EnemyWaiting.h
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
	class EnemyWaiting : public EnemyStrategy
	{
	public:

		// コンストラクタ
		EnemyWaiting(AI* pAI);

		// 実行
		void Execute(float elapsedTime) override;


	private:
	};
}

