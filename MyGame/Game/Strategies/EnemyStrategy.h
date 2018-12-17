//
// EnemyStrategy.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------
#include "MyLibrary.h"

#include "AI.h"


// クラスの定義 --------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// プレイヤーの戦略クラス
	/// </summary>
	class EnemyStrategy
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="pAI">AIアルゴリズムへのポインタ</param>
		EnemyStrategy(AI* pAI): m_pAI(pAI){}

		// 実行
		virtual void Execute(float elapsedTime) = 0;


	protected:

		AI* m_pAI;		// プレイヤーへのポインタ
	};
}
