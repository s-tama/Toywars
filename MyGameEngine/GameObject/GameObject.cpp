//
// GameObject.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------------
#include "GameObject.h"



// usingディレクティブ ----------------------------------------------------------------
using namespace MyLibrary;



// メンバ関数の定義 -------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="tag">タグ名</param>
GameObject::GameObject():
	m_tag("")
{
	AddComponent<Transform>();
	m_pTransform = GetComponent<Transform>();
//	m_pTransform = new Transform();
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
GameObject::~GameObject()
{
	for (auto component : m_pComponents)
	{
		delete component;
		component = nullptr;
	}
}
