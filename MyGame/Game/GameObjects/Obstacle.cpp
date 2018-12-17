//
// Obstacle.cpp 
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "Obstacle.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Obstacle::Obstacle()
{
	SetTag("Obstacle");
}

/// <summary>
/// 初期化処理
/// </summary>
void Obstacle::Initialize()
{
	Obj3D* pObj = new Obj3D();
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"RedBox"));
	pObj->SetLight(false);
	pObj->GetTransform()->SetScale(2);
	AddChild(pObj);

	// ボックスコライダを追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(9, 9, 9));
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Obstacle::Update(float elapsedTime)
{
}
