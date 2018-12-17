//
// Node.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------------- 
#include "Node.h"
#include "../Common/DeviceResources.h"
#include "../GameObject/GameObject.h"



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
	// スプライトバッチの作成
	m_pSpriteBatch = std::make_unique<SpriteBatch>(pContext);
	// 全オブジェクトをアクティブ状態にする
	m_stateFlag.On(IS_ACTIVE);
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
void Node::AddChild(Node* pNode)
{
	GameObject* pChild = dynamic_cast<GameObject*>(pNode);
	if (pChild != nullptr)
	{
		pChild->GetTransform()->SetParent(dynamic_cast<GameObject*>(this));
	}
	m_pChildren.push_back(pNode);
}

/// <summary>
/// 子のリストを取得
/// </summary>
/// <returns></returns>
std::list<Node*> Node::GetChildren()
{
	return m_pChildren;
}

/// <summary>
/// 子の削除
/// </summary>
/// <param name="pNode"></param>
void Node::Destroy()
{
	// 削除フラグを立てる
	m_stateFlag.On(IS_DELETED);
}

/// <summary>
/// 全てを初期化
/// </summary>
void MyLibrary::Node::InitializeAll()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// 自信を初期化
	Initialize();

	// 子を初期化
	for (auto children : m_pChildren)
	{
		children->SetNodeManager(m_pNodeManager);
		children->InitializeAll();
	}
}

/// <summary>
/// 全てを更新
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Node::UpdateAll(float elapsedTime)
{
	if (!m_stateFlag.Check(IS_ACTIVE)) return;

	// 自身の更新
	Update(elapsedTime);
	
	// 子を更新
	std::list<Node*>::iterator it = m_pChildren.begin();
	while (it != m_pChildren.end())
	{
		if ((*it) != nullptr)
		{
			(*it)->UpdateAll(elapsedTime);

			if ((*it)->GetState((*it)->IS_DELETED))
			{
				delete (*it);
				(*it) = nullptr;
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
/// <param name="elapsedTime"></param>
void Node::LateUpdateAll(float elapsedTime)
{
	if (!m_stateFlag.Check(IS_ACTIVE)) return;

	// 自身の更新
	LateUpdate(elapsedTime);

	// 子を更新
	std::list<Node*>::iterator it = m_pChildren.begin();
	while (it != m_pChildren.end())
	{
		if ((*it) != nullptr)
		{
			(*it)->LateUpdateAll(elapsedTime);

			if ((*it)->GetState((*it)->IS_DELETED))
			{
				delete (*it);
				(*it) = nullptr;
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
	if (!m_stateFlag.Check(IS_ACTIVE)) return;

	// 自信を描画
	Draw();

	// スプライトの描画処理
	m_pSpriteBatch->Begin(SpriteSortMode_Deferred, DeviceResources::GetInstance()->GetCommonStates()->NonPremultiplied());
	DrawSprite();
	m_pSpriteBatch->End();

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
/// 指定タグのついたオブジェクトを取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト</returns>
GameObject* Node::FindGameObjectWithTag(std::string tag)
{
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			if (dynamic_cast<GameObject*>(children)->GetTag() == tag)
			{
				return dynamic_cast<GameObject*>(children);
			}
		}
	}
	return nullptr;
}

/// <summary>
/// 指定タグのついたオブジェクト配列を取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト配列</returns>
std::vector<GameObject*> Node::FindGameObjectsWithTag(std::string tag)
{
	std::vector<GameObject*> objs;
	for (auto children : m_pChildren)
	{
		if (children != nullptr)
		{
			if (dynamic_cast<GameObject*>(children)->GetTag() == tag)
			{
				objs.push_back(dynamic_cast<GameObject*>(children));
			}
		}
	}
	return objs;
}

/// <summary>
/// オブジェクトのアクティブ状態を設定する
/// </summary>
/// <param name="activeState"></param>
void Node::SetActive(bool activeState)
{
	if (activeState == true) m_stateFlag.On(IS_ACTIVE);
	else m_stateFlag.Off(IS_ACTIVE);
}

/// <summary>
/// アクティブ状態を取得する
/// </summary>
bool Node::IsActive()
{
	return m_stateFlag.Check(IS_ACTIVE);
}

/// <summary>
/// オブジェクトの状態を取得する
/// </summary>
/// <param name="state"></param>
/// <returns></returns>
bool Node::GetState(UCHAR state)
{
	return m_stateFlag.Check(state);
}
