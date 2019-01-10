//
// NodeManager.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------
#include <memory>
#include <string>
#include <vector>

#include "../Utility/Flag.h"


// クラスの宣言 --------------------------------------------------------------------
namespace MyLibrary
{
	class Node;
	class GameObject;
	class SpriteRenderer;
}


// クラスの定義 --------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// ノード管理クラス
	/// </summary>
	class NodeManager
	{
	public:

		// コンストラクタ
		NodeManager();

		// 初期化処理
		void Initialize();
		// 更新処理
		void Update(float elapsedTime);
		// 描画処理
		void Render();
		// リセット
		void Reset();

		/// <summary>
		/// ノード情報
		/// </summary>
		static void AddNode(GameObject* pObject);
		static Node* GetNode();

		/// <summary>
		/// オブジェクトを取得する
		/// </summary>
		static GameObject* FindGameObjectWithTag(std::string tag);
		static std::vector<GameObject*> FindGameObjectsWithTag(std::string tag);


	private:

		static Node* m_pNode;		// ノードへのポインタ

		SpriteRenderer* m_pSpriteRenderer;	// スプライトレンダラーへのポインタ
	};
}
