//
// Enemy.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------
#include "Enemy.h"

#include "../Strategies/AI_Level0.h"



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

	/*int count = 0;
	while (count < 5)
	{
		GetTransform()->SetPosition(Enemy::APPEAR_POS[Math::GetRand(8)]);
		count++;
	}*/

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(2, 3, 2));

	// 障害物の配列を初期化
	m_pObstacles = GetNodeManager()->GetNode()->FindGameObjectsWithTag("Obstacle");

	// AIアルゴリズムを初期化する
	m_pAI->Initialize();
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
	pBody->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Body"));
	pBody->GetTransform()->SetPosition(0, 0.5f, 0);
	pBody->SetTag("Body");
	AddChild(pBody);

	// 顔
	Obj3D* pFace = new Obj3D;
	pFace->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Face"));
	pFace->GetTransform()->SetPosition(0, 2.5f, 0);
	AddChild(pFace);

	// 腕
	Obj3D* pArm = new Obj3D;
	pArm->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Arm"));
	pArm->GetTransform()->SetPosition(-1.0f, 2.0f, 0);
	AddChild(pArm);

	// 足
	Obj3D* pLeg = new Obj3D;
	pLeg->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Leg"));
	pLeg->GetTransform()->SetPosition(0, 0, 0);
	AddChild(pLeg);

	// ネジ
	Obj3D* pScrew = new Obj3D;
	pScrew->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Screw"));
	pScrew->GetTransform()->SetPosition(0, 1.85f, -0.9f);
	pScrew->SetTag("Screw");
	AddChild(pScrew);
}
