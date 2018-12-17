//
// AI.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"

#include "../GameObjects/Enemy.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class EnemyStrategy;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// AI抽象インターフェース
	/// </summary>
	class AI
	{
	public:

		// コンストラクタ
		AI(Enemy* pEnemy): m_pEnemy(pEnemy){}
		// 仮想デストラクタ
		virtual ~AI(){}

		// 初期化する
		virtual void Initialize(){}

		// 思考する
		virtual void Think(float elapsedTime) = 0;

		/// <summary>
		/// 戦略を変更
		/// </summary>
		/// <param name="pNextStrategy"></param>
		virtual void ChangeStrategy(EnemyStrategy* pNextStrategy) 
		{
			m_pCurrentStrategy = nullptr;
			m_pCurrentStrategy = pNextStrategy; 
		}

		// 敵情報を取得する
		Enemy* GetEnemy() { return m_pEnemy; }


	protected:

		Enemy* m_pEnemy;		// 敵へのポインタ
		EnemyStrategy* m_pCurrentStrategy;		// 現在の戦略
	};
}
