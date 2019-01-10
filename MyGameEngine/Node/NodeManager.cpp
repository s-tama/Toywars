//
// NodeManager.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------
#include "NodeManager.h"

#include "Node.h"
#include "../GameObject/GameObject.h"
#include "../2D/SpriteRenderer.h"



// usingディレクティブ ------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;



// 静的メンバ変数の実態 -----------------------------------------------------------
Node* NodeManager::m_pNode = nullptr;



// メンバ関数の定義 ---------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
NodeManager::NodeManager()
{
	m_pNode = new Node();
	m_pSpriteRenderer = SpriteRenderer::GetInstance();
}

/// <summary>
/// 初期化処理
/// </summary>
void NodeManager::Initialize()
{
	m_pNode->InitializeAll();
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void NodeManager::Update(float elapsedTime)
{
	m_pNode->UpdateAll(elapsedTime);
	m_pNode->LateUpdateAll(elapsedTime);
}

/// <summary>
/// 描画処理
/// </summary>
void NodeManager::Render()
{
	m_pNode->DrawAll();

	m_pNode->DrawPrimitiveAll();

	m_pSpriteRenderer->Begin();
	m_pNode->DrawSpriteAll();
	m_pSpriteRenderer->End();
}

/// <summary>
/// ノードをリセットする
/// </summary>
void NodeManager::Reset()
{
	delete m_pNode;
	m_pNode = nullptr;
}

/// <summary>
/// ノードに追加する
/// </summary>
void NodeManager::AddNode(GameObject* pObject)
{
	m_pNode->AddChild(pObject);
}

/// <summary>
/// ノードを取得する
/// </summary>
/// <returns></returns>
Node* NodeManager::GetNode()
{
	return m_pNode;
}

/// <summary>
/// 指定タグのついたオブジェクトを取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト</returns>
GameObject* NodeManager::FindGameObjectWithTag(std::string tag)
{
	return m_pNode->FindGameObjectWithTag(tag);
}

/// <summary>
/// 指定タグのついたオブジェクト配列を取得する
/// </summary>
/// <param name="tag">タグ</param>
/// <returns>オブジェクト配列</returns>
std::vector<GameObject*> NodeManager::FindGameObjectsWithTag(std::string tag)
{
	return m_pNode->FindGameObjectsWithTag(tag);
}
