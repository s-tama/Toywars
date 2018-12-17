//
// PlayerStanding.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "PlayerState.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 「立ち」状態クラス
	/// </summary>
	class PlayerStanding : public PlayerState
	{
	private:

		// コンストラクタ
		PlayerStanding(){}


	public:

		// クラスのインスタンスを取得
		static PlayerStanding* GetInstance();

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// インスタンス
		static std::unique_ptr<PlayerStanding> m_pInstance;
	};
}
