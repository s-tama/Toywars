//
// Game.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "Game.h"

#include "Scenes/TitleScene.h"
#include "Scenes/SampleScene.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="hInstance">インスタンス</param>
/// <param name="nCmdShow">表示状態</param>
Game::Game(HINSTANCE hInstance, int nCmdShow): 
	Framework(hInstance, nCmdShow, 640, 480),
	m_pSceneManager(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Game::Initialize()
{
	// リソースの作成処理
	CreateResources();

	// シーンマネージャーの作成
	m_pSceneManager = new SceneManager;

	// シーンマネージャーに追加
	m_pSceneManager->EntryScene(new TitleScene);
	m_pSceneManager->EntryScene(new SampleScene);

	// 開始シーンを設定
	m_pSceneManager->StartScene("SampleScene");
}

#pragma region ゲームループ
/// <summary>
/// 更新処理
/// </summary>
/// <param name="timer">タイマー</param>
void Game::Update(StepTimer const& timer)
{
	// 経過時間
	float elapsedTime = float(timer.GetElapsedSeconds());

	// シーンマネージャーの更新
	m_pSceneManager->UpdateActiveScene(elapsedTime);

	// エスケープキーでゲームの終了
	if (System::InputDevice::GetInstance()->GetKeyState().Escape)
	{
		PostQuitMessage(0);
	}

	// インプットデバイスの更新
	System::InputDevice::GetInstance()->Update();
}

/// <summary>
/// 描画処理
/// </summary>
void Game::Render()
{
	// シーンマネージャーの描画
	m_pSceneManager->RenderActiveScene();
}
#pragma endregion

/// <summary>
/// 終了処理
/// </summary>
void Game::Finalize()
{
	// シーンマネージャーの開放
	delete m_pSceneManager;
	m_pSceneManager = nullptr;
}

/// <summary>
/// リソースの作成処理
/// </summary>
void Game::CreateResources()
{
	// テクスチャ読み込み
	TextureLoader textureLoader;
	TextureRepository* pTexRepo = TextureRepository::GetInstance();
	pTexRepo->AddRepository(textureLoader.LoadTexture(L"frame_select"));
	pTexRepo->AddRepository(textureLoader.LoadTexture(L"text_playMode"));
	pTexRepo->AddRepository(textureLoader.LoadTexture(L"background_title"));
	pTexRepo->AddRepository(textureLoader.LoadTexture(L"toywars"));
	pTexRepo->AddRepository(textureLoader.LoadTexture(L"frame_nowSelect"));

	// モデルの読み込み
	ModelLoader modelLoader;
	ModelRepository* pModelRepo = ModelRepository::GetInstance();
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Room"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot_Face"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot_Arm"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot_Leg"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot_Body"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Robot_Screw"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"ToyBox"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"Marble"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"RedBox"));
	pModelRepo->AddRepository(modelLoader.LoadModel(L"ItemBox"));
}
