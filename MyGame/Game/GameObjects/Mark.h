//
// Mark.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
	class EffectFactory;
}


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// ステージクラス
	/// </summary>
	class Mark : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Mark();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// 当たり判定(当たっている間)
		void OnCollisionStay(GameObject* pCollider) override;


	private:

		EffectFactory* m_pEffectFactory;	// エフェクトファクトリーへのポインタ
	};
}
