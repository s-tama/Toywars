//
// SceneManager.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------------
#include <map>
#include <string>


// クラスの宣言 -------------------------------------------------------------------------
namespace MyLibrary
{
	class SceneBase;
}


// クラスの定義 -------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// シーン管理クラス
	/// </summary>
	class SceneManager
	{
	public:

		// コンストラクタ
		SceneManager();
		// デストラクタ
		~SceneManager();

		// シーンの登録
		void EntryScene(SceneBase* pEntryScene);

		// 開始シーンの設定
		void StartScene(std::string sceneName);

		// 現在のシーンを更新
		void UpdateActiveScene(float elapsedTime);

		// 現在のシーンを描画
		void RenderActiveScene();

		// シーンを変更
		static void ChangeScene(std::string sceneName);

		// 活動中のシーンを取得
		static SceneBase* GetActiveScene();


	private:

		// 活動中のシーン
		static SceneBase* m_pActiveScene;

		// シーンのマップ
		static std::map<std::string, SceneBase*> m_pSceneMap;
	};
}
