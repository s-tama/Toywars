//
// TrainingScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "TrainingScene.h"

#include "../GameObjects/MainCamera.h"
#include "../GameObjects/Stage.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Obstacle.h"
#include "../GameObjects/Mark.h"
#include "../GameObjects/ItemBox.h"
#include "../GameObjects/ItemManager.h"
#include "../GameObjects/BulletManager.h"
#include "../GameObjects/EffectFactory.h"
#include "../GameObjects/Mediator.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TrainingScene::TrainingScene() :
	m_pNodeManager(nullptr),
	m_pCollisionManager(nullptr)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void TrainingScene::Initialize()
{
	Create();	// 作成処理

	m_pNodeManager->Initialize();	// ノードマネージャーの初期化
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TrainingScene::Update(float elapsedTime)
{
	// FPSカウント
	m_fpsCounter.Update();

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
void TrainingScene::Render()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// 描画空間
	{
		// シーン名を描画
		GameText::GetInstance()->AddText(Vector2(334, 10), Colors::Black, 2.1f, L"トレーニングモード");
		GameText::GetInstance()->AddText(Vector2(340, 10), Colors::White, 2, L"トレーニングモード");

		// FPS描画
		GameText::GetInstance()->AddText(Vector2(0, 440), Colors::White, 2, L"FPS:%d", m_fpsCounter.GetFrame());

		// ノードマネージャーの描画
		m_pNodeManager->Render();
	}
}

/// <summary>
/// 終了処理
/// </summary>
void TrainingScene::Finalize()
{
	// ノードマネージャーの開放
	m_pNodeManager->Reset();
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}

/// <summary>
/// 作成処理
/// </summary>
void TrainingScene::Create()
{
	m_pNodeManager = new NodeManager();				// ノードマネージャー
	m_pCollisionManager = new CollisionManager();	// コリジョンマネージャー

	CreateGameObject();		// ゲームオブジェクト
}

/// <summary>
/// ゲームオブジェクト作成処理
/// </summary>
void TrainingScene::CreateGameObject()
{
	// 作成する
	MainCamera* pCamera = new MainCamera();		// カメラ
	Stage* pStage = new Stage();				// ステージ
	Player* pPlayer = new Player();				// プレイヤー
	ItemBox* pItemBox = new ItemBox();			// アイテムボックス
	ItemManager* pItemManager = new ItemManager();			// アイテムマネージャー
	BulletManager* pBulletManager = new BulletManager();	// バレットマネージャー
	MyGame::EffectFactory* pEffectFactory = new MyGame::EffectFactory();	// エフェクトファクトリー
	Mediator* pMediator = new Mediator();		// メディエーター

	// 的
	std::vector<Mark*> pMarks;
	pMarks.resize(4);
	// 位置を設定する
	pMarks[0] = new Mark();
	pMarks[0]->GetTransform()->SetPosition(-46, 0, -46);
	pMarks[0]->GetTransform()->SetRotation(0, 45, 0);
	pMarks[1] = new Mark();
	pMarks[1]->GetTransform()->SetPosition(46, 0, -46);
	pMarks[1]->GetTransform()->SetRotation(0, -45, 0);
	pMarks[2] = new Mark();
	pMarks[2]->GetTransform()->SetPosition(-46, 0, 46);
	pMarks[2]->GetTransform()->SetRotation(0, -45, 0);
	pMarks[3] = new Mark();
	pMarks[3]->GetTransform()->SetPosition(46, 0, 46);
	pMarks[3]->GetTransform()->SetRotation(0, 45, 0);

	// 障害物
	std::vector<Obstacle*> pBlocks;				
	pBlocks.resize(9);
	for (UINT i = 0; i < pBlocks.size(); i++)
	{
		// 位置を設定する
		pBlocks[i] = new Obstacle();
		int x = (i % 3) * 30 - 30;
		int z = (i / 3) * 30 - 30;
		Vector3 offset(static_cast<float>(x), 0, static_cast<float>(z));
		pBlocks[i]->GetTransform()->SetPosition(offset);
	}


	// ノードに追加する
	NodeManager::AddNode(pCamera);				// カメラ
	NodeManager::AddNode(pStage);				// ステージ
	NodeManager::AddNode(pPlayer);				// プレイヤー
	NodeManager::AddNode(pItemBox);				// アイテムボックス
	NodeManager::AddNode(pItemManager);			// アイテムマネージャー
	NodeManager::AddNode(pBulletManager);		// バレットマネージャー
	NodeManager::AddNode(pEffectFactory);		// エフェクトファクトリー
	NodeManager::AddNode(pMediator);			// メディエーター
	for (auto mark : pMarks)
	{
		NodeManager::AddNode(mark);				// 的
	}
	for (auto block : pBlocks)
	{
		NodeManager::AddNode(block);			// 障害物
	}

	
	// マネージャーに追加する
	pItemBox->SetTag("AddBullet5");
	pItemManager->EntryItem(pItemBox);
}

/// <summary>
/// UI作成処理
/// </summary>
void TrainingScene::CreateUI()
{
}
