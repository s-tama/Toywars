//
// SampleScene.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ----------------------------------------------------------------------
namespace MyGame
{
	class Mediator;
}


// クラスの定義 ----------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// サンプルシーン
	/// </summary>
	class SampleScene : public MyLibrary::SceneBase
	{
	public:

		// コンストラクタ
		SampleScene();

		// 初期化処理
		void Initialize()				override;
		// 更新処理
		void Update(float elapsedTime)	override;
		// 描画処理
		void Render()					override;
		// 終了処理
		void Finalize()					override;


	private:

		// ノードマネージャーへのポインタ
		MyLibrary::NodeManager* m_pNodeManager;

		// コリジョンマネージャーへのポインタ
		MyLibrary::CollisionManager* m_pCollisionManager;

		// メディエーターへのポインタ
		Mediator* m_pMediator;
	};
}
