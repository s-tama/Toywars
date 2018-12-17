//
// ToyBox.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------------
#include "ToyBox.h"



// usingディレクティブ --------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pCamera">カメラへのポインタ</param>
ToyBox::ToyBox()
{
	SetTag("ToyBox");
}

/// <summary>
/// 初期化処理
/// </summary>
void ToyBox::Initialize()
{
	Obj3D* pObj = new Obj3D;
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"ToyBox"));
	pObj->SetLight(false);
	AddChild(pObj);

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(5, 5, 10));
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ToyBox::Update(float elapsedTime)
{
	m_pTransform->SetRotation(Quaternion::CreateFromAxisAngle(Vector3::Up, -XMConvertToRadians(90)));
	m_pTransform->SetPosition(45, 0, 40);
}
