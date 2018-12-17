//
// TitleScene.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ----------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// タイトルシーン
	/// </summary>
	class TitleScene : public MyLibrary::SceneBase
	{
	public:

		const UCHAR IS_CHANGE = 1 << 7;	// 次のシーンへの移動フラグ


	public:

		// コンストラクタ
		TitleScene();

		// 初期化処理
		void Initialize()				override;
		// 更新処理
		void Update(float elapsedTime)	override;
		// 描画処理
		void Render()					override;
		// 終了処理
		void Finalize()					override;

		// フラグへの参照
		MyLibrary::Utility::Flag& Flag() { return m_flag; }


	private:

		// ノードマネージャーへのポインタ
		MyLibrary::NodeManager* m_pNodeManager;

		// フラグ
		MyLibrary::Utility::Flag m_flag;

		// 次のシーンへのカウント
		float m_nextSceneCount;
	};
}
