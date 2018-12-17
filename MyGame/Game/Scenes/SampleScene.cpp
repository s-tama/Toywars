//
// SampleScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "SampleScene.h"

#include "../GameObjects/MainCamera.h"
#include "../GameObjects/GameWorld.h"
#include "../GameObjects/BulletManager.h"
#include "../GameObjects/Mediator.h"
#include "../GameObjects//EnemyManager.h"
#include "../GameObjects/ItemManager.h"
#include "../GameObjects/UIManager.h"



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
	// デバイス
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();

	// ノードマネージャーの作成
	m_pNodeManager = new NodeManager;

	// カメラの作成
	m_pNodeManager->AddNode(new MainCamera);

	// ゲームワールドの作成と初期化
	GameWorld* pGameWorld = new GameWorld;
	pGameWorld->Initialize(m_pNodeManager);

	// バレットマネージャーの作成
	BulletManager* pBulletManager = new BulletManager();
	m_pNodeManager->AddNode(pBulletManager);

	// エネミーマネージャーの作成
	EnemyManager* pEnemyMnager = new EnemyManager();
	m_pNodeManager->AddNode(pEnemyMnager);

	// アイテムマネージャーの作成
	ItemManager* pItemManager = new ItemManager();
	m_pNodeManager->AddNode(pItemManager);

	// UIマネージャーの作成
	UIManager* pUIManager = new UIManager();
	m_pNodeManager->AddNode(pUIManager);

	// ノードマネージャーの初期化
	m_pNodeManager->Initialize();

	// コリジョンマネージャーの作成
	m_pCollisionManager = new CollisionManager(m_pNodeManager->GetNode());

	// メディエーターの作成
	m_pMediator = new Mediator();
	m_pMediator->SetBulletManager(pBulletManager);
	m_pMediator->SetNodeManager(m_pNodeManager);
	m_pMediator->Initialize();
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void SampleScene::Update(float elapsedTime)
{	
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
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}
