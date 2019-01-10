//
// SphereCollider.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------
#include "SphereCollider.h"

#include "../GameObject/GameObject.h"



// usingディレクティブ ------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
SphereCollider::SphereCollider()
	: m_radius(0.f), m_center(Vector3::Zero)
{
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="center"></param>
/// <param name="radius"></param>
SphereCollider::SphereCollider(DirectX::SimpleMath::Vector3 center, float radius)
	: m_center(center), m_radius(radius)
{
}
