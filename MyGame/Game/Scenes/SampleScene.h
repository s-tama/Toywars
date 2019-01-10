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
	private:

		const byte IS_UPDATE = 1 << 7;		// 更新を行うかのフラグ


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

		// 作成処理
		void Create();


	private:

		// ノードマネージャーへのポインタ
		MyLibrary::NodeManager* m_pNodeManager;

		// コリジョンマネージャーへのポインタ
		MyLibrary::CollisionManager* m_pCollisionManager;

		// メディエーターへのポインタ
		Mediator* m_pMediator;

		// FPSカウンター
		MyLibrary::Utility::FPSCounter m_fpsCounter;

		// フラグ
		MyLibrary::Utility::Flag m_flag;
	};
}
