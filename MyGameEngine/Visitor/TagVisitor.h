//
// TagVisitor.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------------
#include <string>


// クラスの宣言 -----------------------------------------------------------------------
namespace MyLibrary
{
	class GameObject;
}


// クラスの定義 -----------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// タグ訪問者クラス
	/// </summary>
	class TagVisitor
	{
	public:

		// コンストラクタ
		TagVisitor();

		// ゲームオブジェクト内を参照
		void ObjectOperation(GameObject* pGameObject);

		// タグ名のついたオブジェクトを取得
		GameObject* FindGameObjectWithTag(std::string tag);


	private:

		// ゲームオブジェクトへのポインタ
		GameObject* m_pGameObject;
	};
}