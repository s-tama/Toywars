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
#include <list>
#include <vector>

#include "../Utility/Flag.h"


// クラス宣言 -------------------------------------------------------------------------
namespace MyLibrary
{
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
	private:

		const byte IS_DELETED = 1 << 7;	// ノードから削除予定のフラグ
		const byte IS_ACTIVE  = 1 << 6;	// アクティブ状態のフラグ
		const byte IS_ENABLED = 1 << 5;	// 表示状態のフラグ


	public:

		// コンストラクタ
		Node();
		// 仮想デストラクタ
		virtual ~Node();

		// 子を追加
		void AddChild(GameObject* pNode);
		// ノードを取得
		std::list<GameObject*>& GetChildren();

		// 破棄
		void Destroy(GameObject* pObject);
		// アクティブ状態
		void SetActive(bool activeState);
		bool IsActive();
		// 表示状態
		void SetEnabled(bool enabled);
		bool IsEnabled();

		// ノード全体を初期化する
		void InitializeAll();
		// ノード全体を更新する
		void UpdateAll(float elapsedTime);
		void LateUpdateAll(float elapsedTime);
		// ノード全体を描画する
		void DrawAll();
		void DrawSpriteAll();
		void DrawPrimitiveAll();

		/// <summary>
		/// オブジェクトを取得する
		/// </summary>
		GameObject* FindGameObjectWithTag(std::string tag);
		std::vector<GameObject*> FindGameObjectsWithTag(std::string tag);


	private:

		// 開始処理(ノード追加時に一度だけ呼ばれる)
		virtual void Start(){}

		// 初期化処理(ノード全体の初期化時に呼ばれる)
		virtual void Initialize(){}

		// 更新処理(ノード追加後に毎フレーム呼ばれる)
		virtual void Update(float elapsedTime){}
		// 更新処理(全ての更新処理が終了した後に呼ばれる)
		virtual void LateUpdate(float elapsedTime){}

		// 描画処理(ノード追加後に毎フレーム呼ばれる)
		virtual void Draw(){}
		// 描画処理(2Dスプライト専用・ノード追加後に毎フレーム呼ばれる)
		virtual void DrawSprite(){}
		// 描画処理(3Dスプライト専用・ノード追加後に毎フレーム呼ばれる)
		virtual void DrawPrimitive(){}

		// 終了処理(プロジェクト終了時に一度だけ呼ばれる)
		virtual void Finalize(){}


	private:

		// 子ノードへのポインタリスト
		std::list<GameObject*> m_pChildren;

		// フラグ
		Utility::Flag m_flag;
	};
}
