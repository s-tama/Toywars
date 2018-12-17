//
// ItemBox.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


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

//		void OnCollisionStay(MyLibrary::GameObject* collider) override;


	private:

		float m_time;
	};
}

