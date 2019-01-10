//
// Node.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------------- 
#include "Node.h"

#include "../Common/DeviceResources.h"
#include "../GameObject/GameObject.h"
#include "../2D/SpriteRenderer.h"



// usingディレクティブ --------------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;



// メンバ関数の定義 -----------------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Node::Node()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();
	// 全オブジェクトをアクティブ状態にする
	m_flag.On(IS_ACTIVE);
	// 全オブジェクトを表示状態にする
	m_flag.On(IS_ENABLED);
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
Node::~Node()
{
	// 子ノードを破棄する
	for (auto children : m_pChildren)
	{
		delete children;
		children = nullptr;
	}
}

/// <summary>
/// 子を追加
/// </summary>
/// <param name="pNode">ノード</param>
void Node::AddChild(GameObject* pNode)
{
	pNode->GetTransform()->SetParent(dynamic_cast<GameObject*>(this));
	pNode->Start();
	m_pChildren.push_back(pNode);
}

/// <summary>
/// 子のリストを取得
/// </summary>
/// <returns></returns>
std::list<GameObject*>& Node::GetChildren()
{
	return m_pChildren;
}

/// <summary>
/// 子の削除
/// </summary>
/// <param name="pObject"></param>
void Node::Destroy(GameObject* pObject)
{
	// リストから破棄する
	pObject->m_flag.On(pObject->IS_DELETED);
}

/// <summary>
/// 全てを初期化
/// </summary>
void MyLibrary::Node::InitializeAll()
{
	// 自信を初期化
	Initialize();

	// 子を初期化
	for (auto children : m_pChildren)
	{
		children->InitializeAll();
	}	
}

/// <summary>
/// 全てを更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Node::UpdateAll(float elapsedTime)
{
	if (!m_flag.Check(IS_ACTIVE)) return;

	// 自身の更新
	Update(elapsedTime);
	
	// 子を更新
	std::list<GameObject*>::iterator it = m_pChildren.begin();
	while (it != m_pChildren.end())
	{
		if ((*it) != nullptr)
		{
			(*it)->UpdateAll(elapsedTime);

			if ((*it)->m_flag.Check((*it)->IS_DELETED))
			{
				delete (*it);
				it = m_pChildren.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}

/// <summary>
/// 全てを更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Node::LateUpdateAll(float elapsedTime)
{
	if (!m_flag.Check(IS_ACTIVE)) return;

	// 自身の更新
	LateUpdate(elapsedTime);

	// 子を更新
	std::list<GameObject*>::iterator it = m_pChildren.begin();
	while (it != m_pChildren.end())
	{
		if ((*it) != nullptr)
		{
			(*it)->LateUpdateAll(elapsedTime);

			if ((*it)->m_flag.Check((*it)->IS_DELETED))
			{
				delete (*it);
				it = m_pChildren.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
}

/// <summary>
/// 全てを描画
/// </summary>
void Node::DrawAll()
{
	if (!m_flag.Check(IS_ACTIVE)) return;
	if (!m_flag.Check(IS_ENABLED)) return;

	// 描画
	Draw();

	// 子を描画
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->DrawAll();
		}
	}
}

/// <summary>
/// 全スプライト描画処理
/// </summary>
void Node::DrawSpriteAll()
{
	if (!m_flag.Check(IS_ACTIVE)) return;
	if (!m_flag.Check(IS_ENABLED)) return;

	DrawSprite();

	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->DrawSpriteAll();
		}
	}
}

/// <summary>
/// プリミティブ描画処理
/// </summary>
void Node::DrawPrimitiveAll()
{
	if (!m_flag.Check(IS_ACTIVE)) return;
	if (!m_flag.Check(IS_ENABLED)) return;

	DrawPrimitive();

	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			children->DrawPrimitiveAll();
		}
	}
}

/// <summary>
/// オブジェクトのアクティブ状態を設定する
/// </summary>
/// <param name="activeState"></param>
void Node::SetActive(bool activeState)
{
	if (activeState == true) m_flag.On(IS_ACTIVE);
	else m_flag.Off(IS_ACTIVE);
}

/// <summary>
/// アクティブ状態を取得する
/// </summary>
bool Node::IsActive()
{
	return m_flag.Check(IS_ACTIVE);
}

/// <summary>
/// 表示状態を設定する
/// </summary>
/// <param name="enabled"></param>
void Node::SetEnabled(bool enabled)
{
	if (enabled == true) m_flag.On(IS_ENABLED);
	else m_flag.Off(IS_ENABLED);
}

/// <summary>
/// 表示状態を取得する
/// </summary>
/// <returns></returns>
bool Node::IsEnabled()
{
	return m_flag.Check(IS_ENABLED);
}

/// <summary>
/// 指定タグのついたオブジェクトを取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト</returns>
GameObject* Node::FindGameObjectWithTag(std::string tag)
{
	// ノードからオブジェクトを探し出す
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			GameObject* pObj = children;
			if (pObj->GetTag() == tag)
			{
				return pObj;
			}
		}
	}

	// 末端ノードまで再帰的に探し出す
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			GameObject* pObj = children->FindGameObjectWithTag(tag);
			if (pObj != nullptr)
			{
				return pObj;
			}
		}
	}

	// 失敗
	return nullptr;
}

/// <summary>
/// 指定タグのついたオブジェクト配列を取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト配列</returns>
std::vector<GameObject*> Node::FindGameObjectsWithTag(std::string tag)
{
	// オブジェクト配列
	std::vector<GameObject*> objs;

	// ノードからオブジェクトを探し出す
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			GameObject* pObj = children;
			if (pObj != nullptr)
			{
				if (pObj->GetTag() == tag)
				{
					objs.push_back(pObj);
				}

				// 子の関数を再帰呼び出し
				for (auto a : pObj->FindGameObjectsWithTag(tag))
				{
					objs.push_back(a);
				}
			}
		}
	}

	return objs;
}
