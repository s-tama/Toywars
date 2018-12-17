//
// BoxCollider.cpp
//

#include "BoxCollider.h"

#include "../GameObject/GameObject.h"

using namespace MyLibrary;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
BoxCollider::BoxCollider(): 
	m_center(Vector3::Zero), 
	m_extents(Vector3::Zero), 
	m_size(Vector3::Zero)
{
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="center"></param>
/// <param name="extents"></param>
/// <param name="size"></param>
BoxCollider::BoxCollider(DirectX::SimpleMath::Vector3 center, DirectX::SimpleMath::Vector3 extents, DirectX::SimpleMath::Vector3 size)
	: m_center(center), m_extents(extents), m_size(size)
{
}
