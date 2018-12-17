//
// GameObject.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------------------
#include <string>
#include <vector>
#include <memory>

#include "../Node/Node.h"
#include "../Component/Component.h"
#include "../Component/Transform.h"
//#include "../Collision/Collision.h"
#include "../Component/Collider.h"
#include "../Component/Rigidbody.h"
#include "../Component/SphereCollider.h"
#include "../Visitor/TagVisitor.h"


// クラスの定義 ---------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// ゲームオブジェクトクラス
	/// </summary>
	class GameObject : public Node
	{
	public:

		// コピーコンストラクタ
		GameObject();

		// デストラクタ
		virtual ~GameObject();

		// 当たっている間
		virtual void OnCollisionStay(GameObject* collider){}
		// 当たった瞬間
		virtual void OnCollisionEnter(Collider* collider){}
		// 離れた時
		virtual void OnCollisionExit(Collider* collision){}

		// テスト用
		virtual void OnCollision(){}

		// コンポネントを追加
		template <typename T>
		Component* AddComponent()
		{
			Component* component = new T();
			component->SetGameObject(this);
			this->AddChild(component);
			m_pComponents.push_back(component);
			return component;
		}

		// コンポーネントを取得
		template <typename T>
		T* GetComponent()
		{
			for (auto components : m_pComponents)
			{
				if (dynamic_cast<T*>(components))
				{
					return dynamic_cast<T*>(components);
				}
			}
			return nullptr;
		}

		// トランスフォームを設定
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		// トランスフォームを取得
		Transform** GetTransformConnect() 
		{ 
			Transform** p = new Transform*();
			p = &m_pTransform;
			return p; 
		}
		Transform* GetTransform() { return m_pTransform; }

		// ゲームオブジェクトの取得
		GameObject* GetGameObject() { return this; }

		// タグの取得
		void SetTag(std::string tag) { m_tag = tag; }
		std::string GetTag() const { return m_tag; }


	private:

		// タグ
		std::string m_tag;

		// コンポーネントリスト
		std::vector<Component*> m_pComponents;

		
	protected:

		// トランスフォーム
		Transform* m_pTransform;
	};
}
