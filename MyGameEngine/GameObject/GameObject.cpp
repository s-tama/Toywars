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
	m_pTransform = new Transform();
	m_pTransform->SetGameObject(this);
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
GameObject::~GameObject()
{
	delete m_pTransform;
	m_pTransform = nullptr;
}
