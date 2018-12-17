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



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pNode"></param>
CollisionManager::CollisionManager(Node* pNode)
	: m_pNode(pNode)
{
	for (auto children : m_pNode->GetChildren())
	{
		//m_pObject[0].push_back(dynamic_cast<GameObject*>(children));
		//m_pObject[1].push_back(dynamic_cast<GameObject*>(children));
	}
}

/// <summary>
/// 更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void CollisionManager::Update(float elapsedTime)
{
	for (auto children1 : m_pNode->GetChildren())
	{
		GameObject* pObj1 = dynamic_cast<GameObject*>(children1);

		if (pObj1->IsActive())
		{
			SphereCollider* pC1 = pObj1->GetComponent<SphereCollider>();
			BoxCollider* pB1 = pObj1->GetComponent<BoxCollider>();

			for (auto children2 : m_pNode->GetChildren())
			{
				GameObject* pObj2 = dynamic_cast<GameObject*>(children2);

				if (pObj2->IsActive())
				{
					if (pC1 != nullptr)
					{
						SphereCollider* pC2 = pObj2->GetComponent<SphereCollider>();
						if (pC2 != nullptr)
						{
							// 当たった時の処理
							OnCollisionSphere(children1, children2);
						}
					}
					if (pB1 != nullptr)
					{
						BoxCollider* pB2 = pObj2->GetComponent<BoxCollider>();
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
void CollisionManager::OnCollisionBox(Node* pChildren1, Node* pChildren2)
{
	// オブジェクト
	GameObject* c1 = dynamic_cast<GameObject*>(pChildren1);
	GameObject* c2 = dynamic_cast<GameObject*>(pChildren2);

	if (c1 != c2)
	{
		// 球
		BoxCollider* box1 = c1->GetComponent<BoxCollider>();
		BoxCollider* box2 = c2->GetComponent<BoxCollider>();

		// 当たったかの処理
		const bool hit = Collision::Box2Box(box1, box2);
		if (hit)
		{
			// 当たっているときの処理
			c1->OnCollisionStay(c2);
		}
	}
}

/// <summary>
/// 当たった時の処理
/// </summary>
/// <param name="pChildren1"></param>
/// <param name="pChildren2"></param>
void CollisionManager::OnCollisionSphere(Node* pChildren1, Node* pChildren2)
{
	// オブジェクト
	GameObject* c1 = dynamic_cast<GameObject*>(pChildren1);
	GameObject* c2 = dynamic_cast<GameObject*>(pChildren2);

	if (c1 != c2)
	{
		// 球
		SphereCollider* sphere1 = c1->GetComponent<SphereCollider>();
		SphereCollider* sphere2 = c2->GetComponent<SphereCollider>();

		// 当たったかの処理
		const bool hit = Collision::Sphere2Sphere(sphere1, sphere2);
		if (hit)
		{
			// 当たっているときの処理
			c1->OnCollisionStay(c2);
		}
	}
}
