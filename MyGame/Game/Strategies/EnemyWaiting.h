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
	private:

		// コンストラクタ
		EnemyWaiting();


	public:

		// クラスのインスタンスを取得
		static EnemyWaiting* GetInstance();

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// インスタンス
		static std::unique_ptr<EnemyWaiting> m_pInstance;
	};
}

