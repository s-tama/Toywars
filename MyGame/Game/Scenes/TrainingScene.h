//
// TrainingScene.h
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
	/// トレーニングシーン
	/// </summary>
	class TrainingScene : public MyLibrary::SceneBase
	{
	public:

		// コンストラクタ
		TrainingScene();

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
		void CreateGameObject();
		void CreateUI();


	private:

		// ノードマネージャーへのポインタ
		MyLibrary::NodeManager* m_pNodeManager;

		// コリジョンマネージャーへのポインタ
		MyLibrary::CollisionManager* m_pCollisionManager;

		// FPSカウンター
		MyLibrary::Utility::FPSCounter m_fpsCounter;
	};
}
