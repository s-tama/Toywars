//
// Robot.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "Robot.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Robot::Robot()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Robot::Start()
{
	
}

/// <summary>
/// 初期化処理
/// </summary>
void Robot::Initialize()
{
	// 身体
	Obj3D* pBody = new Obj3D;
	pBody->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Body"));
	pBody->GetTransform()->SetPosition(0, 0.5f, 0);
	pBody->SetLight(true);
	AddChild(pBody);

	// 顔
	Obj3D* pFace = new Obj3D;
	pFace->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Face"));
	pFace->GetTransform()->SetPosition(0, 2.5f, 0);
	pFace->SetLight(true);
	AddChild(pFace);

	// 腕
	Obj3D* pArm = new Obj3D;
	pArm->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Arm"));
	pArm->GetTransform()->SetPosition(-1.0f, 2.0f, 0);
	pArm->SetLight(true);
	AddChild(pArm);

	// 足
	Obj3D* pLeg = new Obj3D;
	pLeg->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Leg"));
	pLeg->GetTransform()->SetPosition(0, 0, 0);
	pLeg->SetLight(true);
	AddChild(pLeg);

	// ネジ
	Obj3D* pScrew = new Obj3D;
	pScrew->SetModel(ModelRepository::GetInstance()->GetModel(L"Robot_Screw"));
	pScrew->GetTransform()->SetPosition(0, 1.85f, -0.9f);
	pScrew->SetLight(true);
	AddChild(pScrew);

	// 配列に格納する
	m_pParts.push_back(pBody);		// 0
	m_pParts.push_back(pFace);		// 1
	m_pParts.push_back(pArm);		// 2
	m_pParts.push_back(pLeg);		// 3
	m_pParts.push_back(pScrew);		// 4

	GetTransform()->SetScale(0.6f);
	GetTransform()->SetRotation(0, -150, 0);
	GetTransform()->SetPosition(-1.2f, -1.5f, -5);
	GetTransform()->SetPosition(GetTransform()->GetPosition() * 2);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Robot::Update(float elapsedTime)
{
	// 位置を補間する
	Vector3 pos = m_pTransform->GetPosition();
	pos = XMVectorLerp(pos, Vector3(-1.2f, -1.5f, -5), elapsedTime);
	m_pTransform->SetPosition(pos);

	// 回転する
	m_pParts[4]->GetTransform()->Rotate(0, 0, 90 * elapsedTime);
}
