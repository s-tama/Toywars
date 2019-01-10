//
// BreakEffect.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "EffectBase.h"


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 背景画像クラス
	/// </summary>
	class BreakEffect : public EffectBase
	{
	public:

		// コンストラクタ
		BreakEffect();

		// 開始処理
		void Start() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:

		float m_time;	// 時間
	};
}

