//
// AI.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"

#include "../GameObjects/Enemy.h"
#include "../Strategies/EnemyStrategy.h"


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
		AI(Enemy* pEnemy);
		// 仮想デストラクタ
		virtual ~AI();
		
		// 初期化する
		virtual void Initialize(){}

		// 思考する
		virtual void Think(float elapsedTime) = 0;

		// 戦略を変更
		virtual void ChangeStrategy(EnemyStrategy* pNextStrategy);

		// 敵情報を取得する
		Enemy* GetEnemy() { return m_pEnemy; }


	protected:

		Enemy* m_pEnemy;						// 敵へのポインタ
		EnemyStrategy* m_pCurrentStrategy;		// 現在の戦略
	};
}
