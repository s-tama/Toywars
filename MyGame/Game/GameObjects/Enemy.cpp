//
// Enemy.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------
#include "Enemy.h"

#include "../Strategies/AI_Level0.h"

#include "Mediator.h"



// usingディレクティブ --------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



//静的メンバ定数の定義 --------------------------------------------------------------
const Vector3 Enemy::APPEAR_POS[8]=
{
	Vector3(45, 0, 45),
	Vector3(45, 0, -45),
	Vector3(-45, 0, 45),
	Vector3(-45, 0, -45),
	Vector3(15, 0, 15),
	Vector3(15, 0, -15),
	Vector3(-15, 0, 15),
	Vector3(-15, 0, -15),
};



// 静的メンバ変数の定義 -------------------------------------------------------------
const float Enemy::ADVANCE_SPEED = 12;
const float Enemy::ROTATION_SPEED = 180;



// メンバ関数の定義 -----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Enemy::Enemy():
	m_pAI(nullptr)
{
	SetTag("Enemy");	// タグを設定
}

/// <summary>
/// 初期化処理
/// </summary>
void Enemy::Initialize()
{
	// 作成処理
	Create();

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(2, 3, 2));

	// 障害物の配列を初期化
	m_pObstacles = NodeManager::FindGameObjectsWithTag("Obstacle");

	m_pAI->Initialize();	// AIアルゴリズムを初期化する

	// メディエーターへのポインタを設定する
	GameObject* pMediator = NodeManager::FindGameObjectWithTag("Mediator");
	m_pMediator = dynamic_cast<Mediator*>(pMediator);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Enemy::Update(float elapsedTime)
{
	if (m_pAI != nullptr)
	{
		m_pAI->Think(elapsedTime);
	}
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="collider"></param>
void Enemy::OnCollisionStay(GameObject* collider)
{
}

/// <summary>
/// 作成処理
/// </summary>
void Enemy::Create()
{
	// 身体
	Obj3D* pBody = new Obj3D;
	pBody->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot"));
	pBody->SetTag("Body");
	AddChild(pBody);
}
