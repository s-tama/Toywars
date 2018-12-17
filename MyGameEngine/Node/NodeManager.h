//
// NodeManager.h
//
#pragma once


// ライブラリの定義 -------------------------------------------------------------------
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")


// ヘッダーファイルのインクルード -----------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <memory>
#include <list>
#include <string>


// クラスの宣言 -----------------------------------------------------------------------
namespace MyLibrary
{
	class Node;
	class GameObject;
}


// クラスの定義 -----------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// ゲーム内ノード管理クラス
	/// </summary>
	class NodeManager
	{
	public:

		// コンストラクタ
		NodeManager();
		// デストラクタ
		~NodeManager();

		// 初期化処理
		void Initialize();
		// 更新処理
		void Update(float elapsedTime);
		// 描画処理
		void Render();

		// ノードを設定する
		void SetNode(Node* pNode);
		// ノードに追加する
		void AddNode(Node* pNode);

		// ノードから開放する
		void RemoveNode(Node* pNode);

		// ノードの取得
		Node* GetNode();


	private:

		// ノードへのポインタ
		Node* m_pNode;
	};
}