//
// EffectManager.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// エフェクト管理クラス
	/// </summary>
	class EffectManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		EffectManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;
	};
}
