//
// TagVisitor.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------------
#include "TagVisitor.h"
#include "../GameObject/GameObject.h"



// usingディレクティブ ---------------------------------------------------------------
using namespace MyLibrary;



// メンバ関数の定義 ------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TagVisitor::TagVisitor()
{
}

/// <summary>
/// ゲームオブジェクト内を参照
/// </summary>
/// <param name="pGameObject"></param>
void TagVisitor::ObjectOperation(GameObject* pGameObject)
{
	m_pGameObject = pGameObject;
}

/// <summary>
/// タグ名のついたオブジェクトを取得
/// </summary>
/// <param name="tag"></param>
/// <returns></returns>
GameObject* TagVisitor::FindGameObjectWithTag(std::string tag)
{
	for (auto children : m_pGameObject->GetChildren())
	{
		if (dynamic_cast<GameObject*>(children)->GetTag() == tag)
		{
			return dynamic_cast<GameObject*>(children);
		}
	}
	return nullptr;
}
