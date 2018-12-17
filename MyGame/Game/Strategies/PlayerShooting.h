//
// PlayerShooting.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "PlayerStrategy.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 「発射」戦略
	/// </summary>
	class PlayerShooting : public PlayerStrategy
	{
	private:

		static const UCHAR SHOOT_INTERVAL = 3;


	private:

		// コンストラクタ
		PlayerShooting();


	public:

		// クラスのインスタンスを取得
		static PlayerShooting* GetInstance();

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// インスタンス
		static std::unique_ptr<PlayerShooting> m_pInstance;

		// 発射間隔
		UCHAR m_shootInterval;
	};
}
