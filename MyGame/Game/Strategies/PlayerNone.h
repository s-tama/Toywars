//
// PlayerNone.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "PlayerStrategy.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 戦略無し状態
	/// </summary>
	class PlayerNone : public PlayerStrategy
	{
	private:

		// コンストラクタ
		PlayerNone() {}


	public:

		// クラスのインスタンスを取得
		static PlayerNone* GetInstance();

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// インスタンス
		static std::unique_ptr<PlayerNone> m_pInstance;
	};
}

