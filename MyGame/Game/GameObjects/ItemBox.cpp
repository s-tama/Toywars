//
// ItemBox.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "ItemBox.h"

#include "EffectBase.h"
#include "EffectFactory.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



//静的メンバ定数の定義 --------------------------------------------------------------
const Vector3 ItemBox::APPEAR_POS[8] =
{
	Vector3(45, 2, 45),
	Vector3(45, 2, -45),
	Vector3(-45, 2, 45),
	Vector3(-45, 2, -45),
	Vector3(15, 2, 15),
	Vector3(15, 2, -15),
	Vector3(-15, 2, 15),
	Vector3(-15, 2, -15),
};



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
ItemBox::ItemBox():
	m_time(0)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void ItemBox::Initialize()
{
	Obj3D* pObj = new Obj3D();
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"ItemBox"));
	pObj->GetTransform()->SetScale(2);
	pObj->SetLight(true);
	AddChild(pObj);

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(0.5f, 0.5f, 0.5f));
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ItemBox::Update(float elapsedTime)
{
	GetTransform()->Rotate(GetTransform()->GetUp(), 60 * elapsedTime);
	GetTransform()->Translate(0, -sin(m_time * 2) * elapsedTime, 0);

	m_time += elapsedTime;
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="pCollider"></param>
void ItemBox::OnCollisionStay(GameObject* pCollider)
{
}
