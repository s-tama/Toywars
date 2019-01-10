//
// TitleCamera.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "TitleCamera.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TitleCamera::TitleCamera()
{
	// タグを設定
	SetTag("MainCamera");
}

/// <summary>
/// 開始処理
/// </summary>
void TitleCamera::Start()
{
	// 射影行列を作成する
	RECT size = DeviceResources::GetInstance()->GetOutputSize();
	float aspectRatio = float(size.right) / float(size.bottom);
	float fovAngleY = XMConvertToRadians(45.0f);

	m_projection = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fovAngleY, aspectRatio, 0.01f, 1000.0f);

	// 初期位置を設定
	m_pTransform->SetPosition(0, 0, -10);
}

/// <summary>
/// 初期化処理
/// </summary>
void TitleCamera::Initialize()
{
	// ビュー行列を作成する
	m_view = Matrix::CreateLookAt(m_pTransform->GetPosition(), Vector3::Zero, Vector3::Up);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TitleCamera::Update(float elapsedTime)
{
	// ビュー行列を更新する
	m_view = Matrix::CreateLookAt(m_pTransform->GetPosition(), Vector3::Zero, Vector3::Up);
}
