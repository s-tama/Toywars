//
// Stage.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "Stage.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Stage::Stage()
{
	SetTag("Stage");
}

/// <summary>
/// 初期化処理
/// </summary>
void Stage::Initialize()
{
	Obj3D* pObj = new Obj3D;
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"Room"));
	pObj->SetLight(true);
	pObj->GetTransform()->SetScale(2);
	AddChild(pObj);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Stage::Update(float elapsedTime)
{
}
