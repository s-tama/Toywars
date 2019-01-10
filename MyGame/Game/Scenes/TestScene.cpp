//
// TestScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "TestScene.h"

#include "../GameObjects/TitleCamera.h"
#include "../GameObjects/BreakEffect.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TestScene::TestScene() :
	m_pNodeManager(nullptr),
	m_pCollisionManager(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void TestScene::Initialize()
{
	Create();	// 作成処理

	m_pNodeManager->Initialize();	// ノードマネージャーの初期化
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TestScene::Update(float elapsedTime)
{
	// FPSカウント
	m_fpsCounter.Update();

	// ノードマネージャーの更新
	m_pNodeManager->Update(elapsedTime);
}

/// <summary>
/// 描画処理
/// </summary>
void TestScene::Render()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// 描画空間
	{
		// FPS描画
		GameText::GetInstance()->AddText(Vector2(0, 440), Colors::White, 2, L"FPS:%d", m_fpsCounter.GetFrame());

		// ノードマネージャーの描画
		m_pNodeManager->Render();
	}
}

/// <summary>
/// 終了処理
/// </summary>
void TestScene::Finalize()
{
	// ノードマネージャーの開放
	m_pNodeManager->Reset();
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}

/// <summary>
/// 作成処理
/// </summary>
void TestScene::Create()
{
	m_pNodeManager = new NodeManager();				// ノードマネージャー

	CreateGameObject();		// ゲームオブジェクト
}

/// <summary>
/// ゲームオブジェクト作成処理
/// </summary>
void TestScene::CreateGameObject()
{
	// 作成する
	TitleCamera* pCamera = new TitleCamera();		// カメラ
	BreakEffect* pBreakEffect = new BreakEffect();	// 壊れるエフェクト

	// ノードに追加する
	NodeManager::AddNode(pCamera);
	NodeManager::AddNode(pBreakEffect);
}

/// <summary>
/// UI作成処理
/// </summary>
void TestScene::CreateUI()
{
}
