//
// ItemBox.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
	class EffectFactory;
}


// クラスの定義 ---------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 障害物クラス
	/// </summary>
	class ItemBox : public MyLibrary::GameObject
	{
	public:

		static const DirectX::SimpleMath::Vector3 APPEAR_POS[8];	// 初期出現地点


	public:

		// コンストラクタ
		ItemBox();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// 当たり判定(当たっている間)
		void OnCollisionStay(GameObject* pCollider) override;


	private:

		float m_time;

		EffectFactory* m_pEffectFactory;	// エフェクトファクトリーへのポインタ
	};
}

