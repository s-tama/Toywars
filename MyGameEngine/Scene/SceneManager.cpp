//
// SceneManager.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------------
#include <windows.h>
#include <string>

#include "SceneManager.h"
#include "SceneBase.h"

#include "../Math/Math.h"



// usingディレクティブ -----------------------------------------------------------------
using namespace MyLibrary;



// 静的メンバ変数の実態を定義 ----------------------------------------------------------
SceneBase* SceneManager::m_pActiveScene = nullptr;
std::map<std::string, SceneBase*> SceneManager::m_pSceneMap;



// メンバ関数の定義 --------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager()
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager()
{
	m_pActiveScene = nullptr;

	for (auto scenes : m_pSceneMap)
	{
		scenes.second->Finalize();
		delete scenes.second;
		scenes.second = nullptr;
	}
}

/// <summary>
/// シーンを登録する
/// </summary>
/// <param name="pEntryScene">登録するシーンのインスタンス</param>
void SceneManager::EntryScene(SceneBase* pEntryScene)
{
	// 生成されたシーンのクラス名を自動取得する
	const std::string sceneName = Math::EraseStringFirst(typeid(*pEntryScene).name(), " class MyGame::");

	for (auto scenes : m_pSceneMap)
	{
		if (scenes.first == sceneName)
		{
			// エラーメッセージ
			std::wstring wSceneName = Math::StringToWString(sceneName);
			std::wstring msg = L"シーンはすでに登録されています。 -> " + wSceneName;
			const wchar_t* pMsg = L"シーンの登録失敗";
			MessageBox(0, msg.c_str(), pMsg, MB_OK);
			return;
		}
	}

	// シーンを登録する
	pEntryScene->SetName(sceneName);
	m_pSceneMap[sceneName] = pEntryScene;
}

/// <summary>
/// 開始時のシーンを設定
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::StartScene(std::string sceneName)
{
	// 活動中のシーンに登録する
	m_pActiveScene = m_pSceneMap[sceneName];

	// 開始シーンを初期化する
	m_pActiveScene->Initialize();
}

/// <summary>
/// シーンを変更する
/// </summary>
/// <param name="sceneName"></param>
void SceneManager::ChangeScene(std::string sceneName)
{
	// 現在活動中のシーンを終了する
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Finalize();
	}

	// 活動中のシーンに要求されたシーンを登録する
	m_pActiveScene = m_pSceneMap[sceneName];

	// 活動中のシーンを初期化する
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Initialize();
	}
}

/// <summary>
/// 活動中のシーンの更新
/// </summary>
void SceneManager::UpdateActiveScene(float elapsedTime)
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Update(elapsedTime);
	}
}

/// <summary>
/// 活動中のシーンの描画
/// </summary>
void SceneManager::RenderActiveScene()
{
	if (m_pActiveScene != nullptr)
	{
		m_pActiveScene->Render();
	}
}

/// <summary>
/// 活動中のシーンの取得
/// </summary>
/// <returns></returns>
SceneBase* SceneManager::GetActiveScene()
{
	return m_pActiveScene;
}
