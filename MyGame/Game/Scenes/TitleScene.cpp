//
// TitleScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "TitleScene.h"

#include "../GameObjects/TitleCamera.h"
#include "../GameObjects/Background.h"
#include "../GameObjects/ButtonManager.h"
#include "../GameObjects/TitleLogo.h"
#include "../GameObjects/SelectButton.h"
#include "../GameObjects/Robot.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene():
	m_pNodeManager(nullptr),
	m_nextSceneCount(0)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void TitleScene::Initialize()
{
	Create();		// 作成処理

	// 選択ボタン
	NodeManager::AddNode(new ButtonManager);
	// タイトルロゴ
	NodeManager::AddNode(new TitleLogo);

	// ノードマネージャーの初期化
	m_pNodeManager->Initialize();

	// 全フラグをオフにする
	m_flag.OffAll();

	// カウントを初期化する
	m_nextSceneCount = 0;

	// 選択ボタンにリスナーを登録
	std::vector<GameObject*> pObjs = NodeManager::FindGameObjectsWithTag("SelectButton");
	for (auto obj : pObjs)
	{
		SelectButton* pSelectButton = dynamic_cast<SelectButton*>(obj);
		pSelectButton->AttachListener([=]
		{
			m_flag.On(IS_CHANGE);
		});
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TitleScene::Update(float elapsedTime)
{
	// ノードマネージャーの更新
	m_pNodeManager->Update(elapsedTime);

	m_fpsCounter.Update();

	if (!m_flag.Check(IS_CHANGE)) return;
	m_nextSceneCount += elapsedTime;
	if (m_nextSceneCount > 3)
	{
		SceneManager::ChangeScene("TrainingScene");
	}
}

/// <summary>
/// 描画処理
/// </summary>
void TitleScene::Render()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// シーン名の描画
//	GameText::GetInstance()->AddText(Vector2::Zero, Colors::White, 2, L"たいとるシーン");
	GameText::GetInstance()->AddText(Vector2(0, 440), Colors::Black, 2,
		L"FPS: %d", m_fpsCounter.GetFrame());

	// ノードマネージャーの描画
	m_pNodeManager->Render();
}

/// <summary>
/// 終了処理
/// </summary>
void TitleScene::Finalize()
{
	// ノードマネージャーの開放
	m_pNodeManager->Reset();
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}

/// <summary>
/// 作成処理
/// </summary>
void TitleScene::Create()
{
	// ノードマネージャーの作成
	m_pNodeManager = new NodeManager;

	// ゲームオブジェクト作成
	CreateGameObject();
}

/// <summary>
/// オブジェクト作成処理
/// </summary>
void TitleScene::CreateGameObject()
{
	TitleCamera* pCamera = new TitleCamera();		// カメラ
	Background* pBackGround = new Background();		// 背景
	Robot* pRobot = new Robot();					// ロボット

	NodeManager::AddNode(pCamera);				// カメラ
	NodeManager::AddNode(pBackGround);			// 背景
	NodeManager::AddNode(pRobot);
}

/// <summary>
/// UI作成処理
/// </summary>
void TitleScene::CreateUI()
{
}
