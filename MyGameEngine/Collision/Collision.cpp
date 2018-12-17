//
// Collision.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------------
#include "Collision.h"
#include "../Component/SphereCollider.h"
#include "../Component/BoxCollider.h"
#include "../Component/Transform.h"
#include "../GameObject/GameObject.h"



// usingディレクティブ ---------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX::SimpleMath;
using namespace Utility;



// メンバ関数の定義 ------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
MyLibrary::Collision::Collision()
{
}

/// <summary>
/// 球と球の当たり判定
/// </summary>
/// <param name="sphere1"></param>
/// <param name="sphere2"></param>
bool Collision::Sphere2Sphere(SphereCollider* sphere1, SphereCollider* sphere2)
{
	//static bool currentHit;		// 現在当たっているか
	//static bool lastHit;		// 1フレーム前当たってたか

	//float dx = sphere1->GetGameObject()->GetTransform()->GetPosition().x - sphere2->GetGameObject()->GetTransform()->GetPosition().x;
	//float dy = sphere1->GetGameObject()->GetTransform()->GetPosition().y - sphere2->GetGameObject()->GetTransform()->GetPosition().y;
	//float dz = sphere1->GetGameObject()->GetTransform()->GetPosition().z - sphere2->GetGameObject()->GetTransform()->GetPosition().z;
	//float d = sphere1->GetRadius() + sphere2->GetRadius();

	//float dx2 = dx * dx;
	//float dy2 = dy * dy;
	//float dz2 = dz * dz;
	//float d2 = d*d;

	//lastHit = currentHit;
	//currentHit = dx2 + dy2 + dz2 <= d2;

	//if (currentHit)
	//{
	//	// 当たっている間
	//	sphere1->GetGameObject()->OnCollisionStay(sphere2);
	//}

	//if (!lastHit)
	//{
	//	if (currentHit)
	//	{
	//		// 当たった瞬間
	//		sphere1->GetGameObject()->OnCollisionEnter(sphere2);
	//	}
	//}
	//else
	//{
	//	if (!currentHit)
	//	{
	//		// 離れた瞬間
	//		sphere1->GetGameObject()->OnCollisionExit(sphere2);
	//	}
	//}

	if ((sphere1->GetGameObject() != nullptr) && (sphere2->GetGameObject() != nullptr))
	{
		Vector3 s1 = sphere1->GetGameObject()->GetTransform()->GetPosition() + sphere1->GetCenter();
		Vector3 s2 = sphere2->GetGameObject()->GetTransform()->GetPosition() + sphere2->GetCenter();

		float dx = s1.x - s2.x;
		float dy = s1.y - s2.y;
		float dz = s1.z - s2.z;
		float d = sphere1->GetRadius() + sphere2->GetRadius();

		float dx2 = dx * dx;
		float dy2 = dy * dy;
		float dz2 = dz * dz;
		float d2 = d * d;

		const bool hit = dx2 + dy2 + dz2 <= d2;

		if (hit)
		{
			return true;
		}
	}
	return false;
}

/// <summary>
/// ボックスとボックスの当たり判定
/// </summary>
/// <param name="box1"></param>
/// <param name="box2"></param>
/// <returns></returns>
bool Collision::Box2Box(BoxCollider* box1, BoxCollider* box2)
{
	Vector3 b1 = box1->GetGameObject()->GetTransform()->GetPosition() + box1->GetCenter();
	Vector3 b2 = box2->GetGameObject()->GetTransform()->GetPosition() + box2->GetCenter();

	if (fabsf(b1.x - b2.x) > (box1->GetExtents().x + box2->GetExtents().x)) return false;
	if (fabsf(b1.y - b2.y) > (box1->GetExtents().y + box2->GetExtents().y)) return false;
	if (fabsf(b1.z - b2.z) > (box1->GetExtents().z + box2->GetExtents().z)) return false;
	return true;
}
