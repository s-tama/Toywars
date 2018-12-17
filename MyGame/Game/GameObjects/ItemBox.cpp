//
// ItemBox.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "ItemBox.h"



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
ItemBox::ItemBox()
{
	SetTag("ItemBox");
}

/// <summary>
/// 初期化処理
/// </summary>
void ItemBox::Initialize()
{
	Obj3D* pObj = new Obj3D();
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"ItemBox"));
	pObj->GetTransform()->SetScale(2);
	pObj->SetLight(false);
	AddChild(pObj);

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(1, 1, 1));
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ItemBox::Update(float elapsedTime)
{
	GetTransform()->Rotate(GetTransform()->GetUp(), 60 * elapsedTime);
}
