//
// Rigidbody.h
//
#pragma once

#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// リジッドボディ
	/// </summary>
	class Rigidbody : public Component
	{
	public:

		// コンストラクタ
		Rigidbody();

		// 更新処理
		void Update(float elapsedTime) override;


	private:

		// 重力
		float m_gravity;

		// 速度
		DirectX::SimpleMath::Vector3 m_velocity;
	};
}
