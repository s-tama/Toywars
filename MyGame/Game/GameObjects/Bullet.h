//
// Bullet.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
}


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 弾クラス
	/// </summary>
	class Bullet : public MyLibrary::GameObject
	{
	public:

		static const float ADVANCE_SPEED;		// 前進速度
		static const float ROTATION_SPEED;		// 回転速度

		const UCHAR IS_HIT_OBSTACLE = 1 << 7;


	public:

		/// <summary>
		/// 属性
		/// </summary>
		enum Attribute
		{
			NORMAL,		// 通常
			REFLECT,	// 反射
		};


	public:

		// コンストラクタ
		Bullet();

		// 初期化処理
		void Initialize() override;

		// 更新処理
		void Update(float elapsedTime) override;

		// フラグの取得
		MyLibrary::Utility::Flag& GetFlag();

		// 所有者の情報
		void SetOwner(MyLibrary::GameObject* pOwner);
		MyLibrary::GameObject* GetOwner();

		// 速度ベクトルの情報
		void SetVelocity(DirectX::SimpleMath::Vector3 velocity);
		DirectX::SimpleMath::Vector3 GetVelocity();

		// 当たり判定
		void OnCollisionStay(MyLibrary::GameObject* collider);


	private:

		// フラグ
		MyLibrary::Utility::Flag m_flag;

		// 所有者
		MyLibrary::GameObject* m_pOwner;

		// 速度ベクトル
		DirectX::SimpleMath::Vector3 m_velocity;

		// 属性
		Attribute m_attribute;
	};
}
