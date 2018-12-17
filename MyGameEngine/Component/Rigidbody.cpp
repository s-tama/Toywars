//
// Rigidbody.cpp
//

#include "Rigidbody.h"

#include "Transform.h"
#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
MyLibrary::Rigidbody::Rigidbody()
	: m_gravity(0.0098f), m_velocity(Vector3::Zero)
{
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime"></param>
void MyLibrary::Rigidbody::Update(float elapsedTime)
{
	// 重力を足していく
	m_velocity.y -= m_gravity;

	// 更新
	m_pTransform->SetPosition(
		m_pTransform->GetPosition() + m_velocity
	);
}
