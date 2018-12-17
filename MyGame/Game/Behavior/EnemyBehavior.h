//
// EnemyBehavior.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ---------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 敵の行動パターンノードクラス
	/// </summary>
	class EnemyBehavior
	{
	public:

		// コンストラクタ
		EnemyBehavior();
		// 仮想デストラクタ
		virtual ~EnemyBehavior();

		// 全ノード初期化処理
		void InitializeNode();
		// 全ノード実行処理
		bool ExecuteNode(float elapsedTime);
		

	private:

		// 初期化処理
		virtual void Initialize();
		// 実行処理
		virtual bool Execute(float elapsedTime);


	private:

		std::list<EnemyBehavior*> m_pChildren;	// 子ノード
	};
}
