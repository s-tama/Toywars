//
// MainCamera.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "MainCamera.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
MainCamera::MainCamera():
	m_pTarget(nullptr)
{
	// ウインドウサイズからアスペクト比を算出する
	RECT size = DeviceResources::GetInstance()->GetOutputSize();
	float aspectRatio = float(size.right) / float(size.bottom);

	// 画角を設定
	float fovAngleY = XMConvertToRadians(45.0f);

	// 射影行列を作成する
	m_projection = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView
	(
		fovAngleY,
		aspectRatio,
		0.01f,
		1000.0f
	);

	// タグを設定
	SetTag("MainCamera");
}

/// <summary>
/// 初期化処理
/// </summary>
void MainCamera::Initialize()
{
	// 追従ターゲットを設定
	GameObject* pPlayer = NodeManager::FindGameObjectWithTag("Player");
	//GameObject* pBody = pPlayer->FindGameObjectWithTag("Body");
	if (pPlayer != nullptr)
		m_pTarget = pPlayer->GetTransform();
	// 座標を設定
	m_pTransform->SetPosition(0, 3, -10);

	m_view = Matrix::CreateLookAt(m_pTransform->GetPosition(), Vector3::Zero, m_pTransform->GetUp());
}

/// <summary>
/// 最後の更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void MainCamera::LateUpdate(float elapsedTime)
{
	if ((m_pTarget) == nullptr) return;

	// 位置
	Vector3 eye = m_pTransform->GetPosition();

	// 注視点
	Vector3 lookAt((m_pTarget)->GetPosition().x, (m_pTarget)->GetPosition().y + 4, (m_pTarget)->GetPosition().z);

	// 回転行列
	Matrix rotY = Matrix::CreateRotationY((m_pTarget)->GetDirection());
	// 視点を変更
	eye = Vector3::Transform(eye, rotY);
	eye += lookAt;

	// ビュー行列を作成する
	m_view = Matrix::CreateLookAt(eye, lookAt, m_pTransform->GetUp());
}
