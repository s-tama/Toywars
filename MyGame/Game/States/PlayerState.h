//
// PlayerState.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------
#include "MyLibrary.h"

#include "../GameObjects/Player.h"


// クラスの定義 --------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// プレイヤーの状態クラス
	/// </summary>
	class PlayerState
	{
	public:

		/// <summary>
		/// 初期化処理
		/// </summary>
		/// <param name="pPlayer">プレイヤーへのポインタ</param>
		virtual void Initialize(Player* pPlayer)
		{
			m_pPlayer = pPlayer;
		}

		// 実行
		virtual void Execute(float elapsedTime) = 0;


	protected:

		// プレイヤーへのポインタ
		Player* m_pPlayer;
	};
}
