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
#include "../Component/Collider.h"
#include "../Component/SphereCollider.h"


// クラスの定義 ---------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// ゲームオブジェクトクラス
	/// </summary>
	class GameObject : public Node
	{
	public:

		// コンストラクタ
		GameObject();
		// 仮想デストラクタ
		virtual ~GameObject();

		// 当たっている間
		virtual void OnCollisionStay(GameObject* collider){}
		// 当たった瞬間
		virtual void OnCollisionEnter(Collider* collider){}
		// 離れた時
		virtual void OnCollisionExit(Collider* collision){}

		/// <summary>
		/// 変換情報
		/// </summary>
		void SetTransform(Transform* transform) { m_pTransform = transform; }
		Transform* GetTransform() { return m_pTransform; }

		/// <summary>
		/// タグ情報
		/// </summary>
		void SetTag(std::string tag) { m_tag = tag; }
		std::string GetTag() const { return m_tag; }

		/// <summary>
		/// コンポネントの追加
		/// </summary>
		template <typename T>
		Component* AddComponent()
		{
			Component* component = new T();
			component->SetGameObject(this);
			m_pComponents.push_back(component);
			return component;
		}

		/// <summary>
		/// コンポネントの取得
		/// </summary>
		template <typename T>
		T* GetComponent()
		{
			for (auto components : m_pComponents)
			{
				T* pComponent = dynamic_cast<T*>(components);
				if (pComponent)
				{
					return pComponent;
				}
			}
			return nullptr;
		}

		/// <summary>
		/// 全コンポネントの取得
		/// </summary>
		/// <returns></returns>
		std::vector<Component*> GetComponents() { return m_pComponents; }


	private:

		std::string m_name;		// 名前
		std::string m_tag;		// タグ名

		std::vector<Component*> m_pComponents;		// コンポネント配列

		
	protected:

		Transform* m_pTransform;		// 変換情報
	};
}
