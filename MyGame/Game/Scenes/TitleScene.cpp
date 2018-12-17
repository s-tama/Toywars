//
// TitleScene.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "TitleScene.h"

#include "../GameObjects/MainCamera.h"
#include "../GameObjects/Background.h"
#include "../GameObjects/ButtonManager.h"
#include "../GameObjects/TitleLogo.h"



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
	// デバイス
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();

	// ノードマネージャーの作成
	m_pNodeManager = new NodeManager;

	// ノードに追加
	// 背景画像
	Background* pBackGround = new Background();
	pBackGround->GetSprite()->SetTexture(TextureRepository::GetInstance()->GetTexture(L"background_title"));
	pBackGround->GetSprite()->AnchorPoint() = Vector2(0, 0);
	m_pNodeManager->AddNode(pBackGround);
	// 選択ボタン
	m_pNodeManager->AddNode(new ButtonManager);
	// タイトルロゴ
	m_pNodeManager->AddNode(new TitleLogo);

	// ノードマネージャーの初期化
	m_pNodeManager->Initialize();

	// 全フラグをオフにする
	m_flag.OffAll();

	// カウントを初期化する
	m_nextSceneCount = 0;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TitleScene::Update(float elapsedTime)
{
	// ノードマネージャーの更新
	m_pNodeManager->Update(elapsedTime);

	
	// サンプルシーンに移動
	if (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::Space))
	{
		m_flag.On(IS_CHANGE);
	}

	if (!m_flag.Check(IS_CHANGE)) return;
	m_nextSceneCount += elapsedTime;
	if (m_nextSceneCount > 3)
	{
		SceneManager::ChangeScene("SampleScene");
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

	// ノードマネージャーの描画
	m_pNodeManager->Render();
}

/// <summary>
/// 終了処理
/// </summary>
void TitleScene::Finalize()
{
	// ノードマネージャーの開放
	delete m_pNodeManager;
	m_pNodeManager = nullptr;
}
