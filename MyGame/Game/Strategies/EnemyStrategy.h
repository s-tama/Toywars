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
		/// 初期化処理
		/// </summary>
		/// <param name="pPlayer">プレイヤーへのポインタ</param>
		virtual void Initialize(AI* pAI)
		{
			m_pAI = pAI;
		}

		// 実行
		virtual void Execute(float elapsedTime) = 0;


	protected:

		// プレイヤーへのポインタ
		AI* m_pAI;
	};
}
