//
// NodeManager.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------------
#include "NodeManager.h"

#include "Node.h"
#include "../GameObject/GameObject.h"



// usingディレクティブ ------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
NodeManager::NodeManager():
	m_pNode(nullptr)
{
	m_pNode = new Node;
}

/// <summary>
/// デストラクタ
/// </summary>
NodeManager::~NodeManager()
{
	delete m_pNode;
	m_pNode = nullptr;
}

/// <summary>
/// 初期化処理
/// </summary>
void NodeManager::Initialize()
{
	m_pNode->SetNodeManager(this);
	m_pNode->InitializeAll();
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void NodeManager::Update(float elapsedTime)
{
	if (m_pNode != nullptr)
	{
		m_pNode->UpdateAll(elapsedTime);
		m_pNode->LateUpdateAll(elapsedTime);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void NodeManager::Render()
{
	if (m_pNode != nullptr)
	{
 		m_pNode->DrawAll();
	}
}

/// <summary>
/// ノードに追加する
/// </summary>
/// <param name="pChildren">子ノード</param>
void NodeManager::SetNode(Node* pNode)
{
	m_pNode = pNode;
}

/// <summary>
/// ノードに追加する
/// </summary>
/// <param name="pNode"></param>
void NodeManager::AddNode(Node* pNode)
{
	m_pNode->AddChild(pNode);
}

/// <summary>
/// ノードから開放する
/// </summary>
/// <param name="pNode"></param>
void NodeManager::RemoveNode(Node* pNode)
{
	//m_pNode->Remove(pNode);
}

/// <summary>
/// ノードマネージャーの取得
/// </summary>
/// <returns></returns>
Node* NodeManager::GetNode()
{
	return m_pNode;
}
