//
// CollisionManager.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------
#include <list>


// クラスの宣言 --------------------------------------------------------------------
namespace MyLibrary
{
	class Node;
	class GameObject;
}


// クラスの定義 --------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// 当たり判定マネージャー
	/// </summary>
	class CollisionManager
	{
	public:

		// コンストラクタ
		CollisionManager(Node*);

		// 更新
		void Update(float);


	private:

		// 当たった時の処理
		void OnCollisionSphere(Node*, Node*);
		void OnCollisionBox(Node*, Node*);


	private:

		// ノードポインタ
		Node* m_pNode;

		// 当たり判定に使うオブジェクト
		std::list<GameObject*> m_pObject[2];
	};
}
