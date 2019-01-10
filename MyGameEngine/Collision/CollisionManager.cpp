//
// CollisionManager.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------------
#include "CollisionManager.h"
#include "Collision.h"
#include "../Node/Node.h"
#include "../GameObject/GameObject.h"
#include "../Component/SphereCollider.h"
#include "../Component/BoxCollider.h"
#include "../Node/NodeManager.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pNode"></param>
CollisionManager::CollisionManager()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void CollisionManager::Update(float elapsedTime)
{
	for (auto children1 : NodeManager::GetNode()->GetChildren())
	{
		if (children1->IsActive())
		{
			SphereCollider* pC1 = children1->GetComponent<SphereCollider>();
			BoxCollider* pB1 = children1->GetComponent<BoxCollider>();

			for (auto children2 : NodeManager::GetNode()->GetChildren())
			{
				if (children2->IsActive())
				{
					if (pC1 != nullptr)
					{
						SphereCollider* pC2 = children2->GetComponent<SphereCollider>();
						if (pC2 != nullptr)
						{
							// 当たった時の処理
							OnCollisionSphere(children1, children2);
						}
					}
					if (pB1 != nullptr)
					{
						BoxCollider* pB2 = children2->GetComponent<BoxCollider>();
						if (pB2 != nullptr)
						{
							// 当たった時の処理
							OnCollisionBox(children1, children2);
						}
					}
				}
			}
		}
	}
}

/// <summary>
/// 当たった時の処理
/// </summary>
/// <param name="pChildren1"></param>
/// <param name="pChildren2"></param>
void CollisionManager::OnCollisionBox(GameObject* pChildren1, GameObject* pChildren2)
{
	if (pChildren1 != pChildren2)
	{
		// 球
		BoxCollider* box1 = pChildren1->GetComponent<BoxCollider>();
		BoxCollider* box2 = pChildren2->GetComponent<BoxCollider>();

		// 当たったかの処理
		const bool hit = Collision::Box2Box(box1, box2);
		if (hit)
		{
			// 当たっているときの処理
			pChildren1->OnCollisionStay(pChildren2);
		}
	}
}

/// <summary>
/// 当たった時の処理
/// </summary>
/// <param name="pChildren1"></param>
/// <param name="pChildren2"></param>
void CollisionManager::OnCollisionSphere(GameObject* pChildren1, GameObject* pChildren2)
{
	if (pChildren1 != pChildren2)
	{
		// 球
		SphereCollider* sphere1 = pChildren1->GetComponent<SphereCollider>();
		SphereCollider* sphere2 = pChildren2->GetComponent<SphereCollider>();

		// 当たったかの処理
		const bool hit = Collision::Sphere2Sphere(sphere1, sphere2);
		if (hit)
		{
			// 当たっているときの処理
			pChildren1->OnCollisionStay(pChildren2);
		}
	}
}
