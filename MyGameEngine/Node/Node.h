//
// Node.h
//
#pragma once


// ライブラリの定義 -------------------------------------------------------------------
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")


// ヘッダーファイルのインクルード -----------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <list>
#include <vector>

#include "../Utility/Flag.h"


// クラス宣言 -------------------------------------------------------------------------
namespace MyLibrary
{
	class NodeManager;
	class GameObject;
}


// クラスの定義 -----------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// ゲームオブジェクト管理ノードクラス
	/// </summary>
	class Node
	{
	protected:

		const UCHAR IS_DELETED = 1 << 7;	// ノードから削除予定のフラグ
		const UCHAR IS_ACTIVE  = 1 << 6;	// アクティブ状態のフラグ


	public:

		// コンストラクタ
		Node();
		// 仮想デストラクタ
		virtual ~Node();

		// 子を追加
		void AddChild(Node* pNode);
		// 子のリストを取得
		std::list<Node*> GetChildren();

		// 子の削除
		void Destroy();
		// アクティブ状態を設定する
		void SetActive(bool activeState);
		// アクティブ状態を取得する
		bool IsActive();

		// 初期化する
		void InitializeAll();
		// 更新する
		void UpdateAll(float elapsedTime);
		void LateUpdateAll(float elapsedTime);
		// 描画する
		void DrawAll();

		// ノードマネージャーの情報
		virtual void SetNodeManager(NodeManager* pNodeManager) { m_pNodeManager = pNodeManager; }
		virtual NodeManager* GetNodeManager() const { return m_pNodeManager; }

		// タグのついたゲームオブジェクトを取得する
		GameObject* FindGameObjectWithTag(std::string tag);
		std::vector<GameObject*> FindGameObjectsWithTag(std::string tag);

		// オブジェクトの状態を取得する
		bool GetState(UCHAR state);


	private:

		// 自身の初期化処理
		virtual void Initialize(){}

		// 自身の更新処理
		virtual void Update(float elapsedTime){}
		// 最後に更新する
		virtual void LateUpdate(float elapsedTime){}

		// 自身の描画処理
		virtual void Draw(){}
		// スプライトの描画処理
		virtual void DrawSprite(){}
		// 自身の終了処理
		virtual void Finalize(){}


	private:

		// 子ノード
		std::list<Node*> m_pChildren;
		std::list<Node*> m_pNoneActiveChildren;

		// ノードマネージャーへのポインタ
		NodeManager* m_pNodeManager;

		// フラグ
		Utility::Flag m_stateFlag;

	
	protected:

		// スプライトバッチ
		std::unique_ptr<DirectX::SpriteBatch> m_pSpriteBatch;
	};
}
