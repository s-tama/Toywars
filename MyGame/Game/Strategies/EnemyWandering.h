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
	private:

		// 方向
		static const float DIRECTION[4];


	public:

		// コンストラクタ
		EnemyWandering(AI* pAI);

		// 実行
		void Execute(float elapsedTime) override;


	private:

		int m_time;		// タイマー
	};
}

