//
// AI_Level0.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "AI.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class EnemyStrategy;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// レベル0のAIクラス
	/// </summary>
	class AI_Level0 : public AI
	{
	private:

		// 方向
		static const float DIRECTION[4];


	public:

		// コンストラクタ
		AI_Level0(Enemy* pEnemy);

		// 初期化処理
		void Initialize() override;

		// 思考
		void Think(float elapsedTime) override;


	private:

		MyLibrary::GameObject* m_pTarget;					// ターゲットへのポインタ
		int m_time;											// タイマー(int)
		float m_timef;										// タイマー(float)
	};
}
