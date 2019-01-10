//
// BoxCollider.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------
#include "BoxCollider.h"

#include "../GameObject/GameObject.h"



// usingディレクティブ ------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
BoxCollider::BoxCollider(): 
	m_center(Vector3::Zero), 
	m_extents(Vector3::Zero)
{
}

/// <summary>
/// コピーコンストラクタ
/// </summary>
/// <param name="center">中心点</param>
/// <param name="extents">大きさ</param>
BoxCollider::BoxCollider(DirectX::SimpleMath::Vector3 center, DirectX::SimpleMath::Vector3 extents): 
	m_center(center), 
	m_extents(extents)
{
}
