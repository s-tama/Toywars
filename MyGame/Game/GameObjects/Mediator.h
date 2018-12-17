//
// Mediator.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------
#include "MyLibrary.h"


// クラス宣言 -------------------------------------------------------------------
namespace MyGame
{
	class BulletManager;
}


// クラスの定義 -----------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// オブジェクト仲介役クラス
	/// </summary>
	class Mediator
	{
	public:

		// コンストラクタ
		Mediator();

		// 初期化処理
		void Initialize();

		// バレットマネージャーの情報
		void SetBulletManager(BulletManager* pBulletManager);
		BulletManager* GetBulletManager();

		// ノードマネージャーの情報
		void SetNodeManager(MyLibrary::NodeManager* pNodeManager);
		MyLibrary::NodeManager* GetNodeManager();


	private:

		BulletManager* m_pBulletManager;	// バレットマネージャーへのポインタ
		MyLibrary::NodeManager* m_pNodeManager;		// ノードマネージャーへのポインタ
	};
}
