//
// Camera.cpp
//



// ヘッダーファイルのインクルード --------------------------------------
#include "Camera.h"



// usingディレクティブ -------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------
/// <summary>
/// コンストラクタ	
/// </summary>
Camera::Camera():
	m_view(Matrix::Identity),
	m_projection(Matrix::Identity)
{
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
Camera::~Camera()
{
}

/// <summary>
/// ビュー行列の取得
/// </summary>
/// <returns></returns>
Matrix Camera::GetView()
{
	return m_view;
}

/// <summary>
/// 射影行列の取得
/// </summary>
/// <returns></returns>
Matrix Camera::GetProjection()
{
	return m_projection;
}

/// <summary>
/// 注視点を設定
/// </summary>
/// <param name="lookAtPos">注視点</param>
void Camera::LookAt(Vector3 lookAt)
{
	Vector3 eye = m_pTransform->GetPosition();
	Vector3 up = Vector3::Up;
	m_view = Matrix::CreateLookAt(eye, lookAt, up);
}

/// <summary>
/// 注視点を設定
/// </summary>
/// <param name="x">注視点X</param>
/// <param name="y">注視点Y</param>
/// <param name="z">注視点Z</param>
void Camera::LookAt(float x, float y, float z)
{
	Vector3 eye = m_pTransform->GetPosition();
	Vector3 lookAt(x, y, z);
	Vector3 up = Vector3::Up;
	m_view = Matrix::CreateLookAt(eye, lookAt, up);
}
