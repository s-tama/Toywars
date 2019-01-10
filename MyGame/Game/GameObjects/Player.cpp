//
// Player.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------
#include "Player.h"

#include "Mediator.h"

#include "../States/PlayerStanding.h"
#include "../States/PlayerMoving.h"
#include "../Strategies/PlayerNone.h"
#include "../Strategies/PlayerShooting.h"

#include "EffectFactory.h"
#include "EffectBase.h"



// usingディレクティブ --------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -------------------------------------------------------------
const float Player::ADVANCE_SPEED  = 24;
const float Player::ROTATION_SPEED = 180;



// メンバ関数の定義 -----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Player::Player():
	m_pCurrentState(nullptr),
	m_pCurrentStrategy(nullptr),
	m_velocity(Vector3::Zero),
	m_pMediator(nullptr),
	m_possessBulletNum(0)
{
	SetTag("Player");	// タグを設定
}

/// <summary>
/// 開始処理
/// </summary>
void Player::Start()
{
	// 作成処理
	Create();
}

/// <summary>
/// 初期化処理
/// </summary>
void Player::Initialize()
{
	// 状態を初期化する
	InitializeState();
	// 戦略を初期化する
	InitializeStrategy();

	// 初期位置を設定する
	int x = 0;
	int z = 0;
	while (x == 0 && z == 0)
	{
		x = Math::GetRand(3) - 1;		// -1～1までの値
		z = Math::GetRand(3) - 1;		// -1～1までの値
	}
	this->GetTransform()->SetPosition(static_cast<float>(x) * 45, 0, static_cast<float>(z) * 45);

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(2, 3, 2));

	// 速度を初期化
	m_velocity = Vector3(0, 0, ADVANCE_SPEED);

	// 障害物の配列を初期化
	m_pObstacles = NodeManager::FindGameObjectsWithTag("Obstacle");

	// メディエーターへのポインタを設定する
	GameObject* pMediator = NodeManager::FindGameObjectWithTag("Mediator");
	m_pMediator = dynamic_cast<Mediator*>(pMediator);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Player::Update(float elapsedTime)
{
	// 現在の状態を実行する
	if (m_pCurrentState != nullptr)
	{
		m_pCurrentState->Execute(elapsedTime);
	}

	// 現在の戦略を実行する
	if (m_pCurrentStrategy != nullptr)
	{
		m_pCurrentStrategy->Execute(elapsedTime);
	}
}

/// <summary>
/// 状態を変更する
/// </summary>
/// <param name="pNextState">次の状態</param>
void Player::ChangeState(PlayerState* pNextState)
{
	m_pCurrentState = pNextState;
}

/// <summary>
/// 次の戦略を設定する
/// </summary>
/// <param name="pNextStrategy">次の戦略へのポインタ</param>
void Player::ChangeStrategy(PlayerStrategy* pNextStrategy)
{
	m_pCurrentStrategy = pNextStrategy;
}

/// <summary>
/// 当たっている間の処理
/// </summary>
/// <param name="collider"></param>
void MyGame::Player::OnCollisionStay(GameObject* collider)
{
	/*auto SetEffect = [&](MyGame::EffectFactory::EffectID effectID)
	{
		EffectBase* pEffect = m_pMediator->GetEffectFactory()->Create(effectID);
		pEffect->GetTransform()->SetPosition(
			collider->GetTransform()->GetPosition().x,
			collider->GetTransform()->GetPosition().y,
			collider->GetTransform()->GetPosition().z
		);
	};*/

	if (collider->GetTag() == "AddBullet5")
	{
//		SetEffect(MyGame::EffectFactory::EffectID::POPPING);
		collider->SetActive(false);
		m_possessBulletNum += 5;
	}
}

/// <summary>
/// 作成処理
/// </summary>
void Player::Create()
{
	// 身体
	Obj3D* pBody = new Obj3D;
	pBody->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Body"));
	pBody->GetTransform()->SetPosition(0, 0.5f, 0);
	pBody->SetTag("Body");
	pBody->SetLight(false);
	AddChild(pBody);
	
	// 顔
	Obj3D* pFace = new Obj3D;
	pFace->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Face"));
	pFace->GetTransform()->SetPosition(0, 2.5f, 0);
	pFace->SetLight(false);
	AddChild(pFace);

	// 腕
	Obj3D* pArm = new Obj3D;
	pArm->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Arm"));
	pArm->GetTransform()->SetPosition(-1.0f, 2.0f, 0);
	pArm->SetLight(false);
	AddChild(pArm);

	// 足
	Obj3D* pLeg = new Obj3D;
	pLeg->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Leg"));
	pLeg->GetTransform()->SetPosition(0, 0, 0);
	pLeg->SetLight(false);
	AddChild(pLeg);

	// ネジ
	Obj3D* pScrew = new Obj3D;
	pScrew->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Screw"));
	pScrew->GetTransform()->SetPosition(0, 1.85f, -0.9f);
	pScrew->SetLight(false);
	pScrew->SetTag("Screw");
	AddChild(pScrew);
}

/// <summary>
/// 状態を初期化する
/// </summary>
void Player::InitializeState()
{
	// プレイヤーの状態を初期化する
	PlayerStanding::GetInstance()->Initialize(this);
	PlayerMoving::GetInstance()->Initialize(this);

	// 初期状態を設定する
	m_pCurrentState = PlayerStanding::GetInstance();
}

/// <summary>
/// 戦略を初期化する
/// </summary>
void Player::InitializeStrategy()
{
	// プレイヤーの戦略を初期化する
	PlayerNone::GetInstance()->Initialize(this);
	PlayerShooting::GetInstance()->Initialize(this);

	// 初期戦略を設定する
	m_pCurrentStrategy = PlayerNone::GetInstance();
}


