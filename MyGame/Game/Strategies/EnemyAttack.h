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
	private:

		static const UCHAR SHOOT_INTERVAL = 3;


	private:

		// コンストラクタ
		EnemyAttack();


	public:

		// クラスのインスタンスを取得
		static EnemyAttack* GetInstance();

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// インスタンス
		static std::unique_ptr<EnemyAttack> m_pInstance;
	};
}
