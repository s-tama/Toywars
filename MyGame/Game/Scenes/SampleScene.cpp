//
// SampleScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "SampleScene.h"

#include "../GameObjects/MainCamera.h"
#include "../GameObjects/GameWorld.h"
#include "../GameObjects/Mediator.h"
#include "../GameObjects/UIManager.h"
#include "../GameObjects/Background.h"
#include "../GameObjects/Mark.h"
#include "../GameObjects/ItemBox.h"
#include "../GameObjects/ItemManager.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
SampleScene::SampleScene():
	m_pNodeManager(nullptr),
	m_pCollisionManager(nullptr),
	m_pMediator(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void SampleScene::Initialize()
{
	Create();	// 作成処理

	m_pNodeManager->Initialize();	// ノードマネージャーの初期化
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void SampleScene::Update(float elapsedTime)
{	
	// fpsをカウントする
	m_fpsCounter.Update();
	// fpsが60を超えたら更新を開始する
	if (m_fpsCounter.GetFrame() >= 60)
	{
		m_flag.On(IS_UPDATE);
	}
	if (!m_flag.Check(IS_UPDATE)) return;

	// ノードマネージャーの更新
	m_pNodeManager->Update(elapsedTime);

	// コリジョンマネージャーの更新
	m_pCollisionManager->Update(elapsedTime);

	// タイトルシーンに移動
	if (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::Space))
	{
		SceneManager::ChangeScene("TitleScene");
	}
}

/// <summary>
/// 描画処理
/// </summary>
void SampleScene::Render()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// 描画空間
	{
		// シーン名を描画
//		GameText::GetInstance()->AddText(Vector2::Zero, DirectX::Colors::Black, 2, L"さんぷるシーン");
		GameText::GetInstance()->AddText(Vector2(334, 10), Colors::Black, 2.1f, L"トレーニングモード");
		GameText::GetInstance()->AddText(Vector2(340, 10), Colors::White, 2, L"トレーニングモード");
		GameText::GetInstance()->AddText(Vector2(0, 440), Colors::White, 2,
			L"FPS:%d", m_fpsCounter.GetFrame());

		// ノードマネージャーの描画
		m_pNodeManager->Render();
	}
}

/// <summary>
/// 終了処理
/// </summary>
void SampleScene::Finalize()
{
	// ノードマネージャーの開放
	m_pNodeManager->Reset();
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}

/// <summary>
/// 作成処理
/// </summary>
void SampleScene::Create()
{
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();						// デバイス
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();		// デバイスコンテキスト

	m_pNodeManager = new NodeManager();		// ノードマネージャー

	MainCamera* pCamera = new MainCamera();		// カメラ
	GameWorld* pGameWorld = new GameWorld();	// ゲームワールド
	Mediator* pMadiator = new Mediator();		// メディエーター
	UIManager* pUIManager = new UIManager();	// UIマネージャー
	ItemBox* pItemBox = new ItemBox();			// アイテムボックス
	ItemManager* pItemManager = new ItemManager();			// アイテムマネージャー
	NodeManager::AddNode(pItemBox);
	NodeManager::AddNode(pItemManager);

	m_pNodeManager->AddNode(pCamera);
	pGameWorld->Initialize();
	m_pNodeManager->AddNode(pMadiator);
	m_pNodeManager->AddNode(pUIManager);

	m_pCollisionManager = new CollisionManager();	// コリジョンマネージャー

	// マネージャーに追加する
	pItemBox->SetTag("AddBullet5");
	pItemManager->EntryItem(pItemBox);
}
