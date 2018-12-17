//
// Cube.cpp
//

#include "Cube.h"

using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="context"></param>
/// <param name="size"></param>
/// <param name="tessellation"></param>
MyLibrary::Cube::Cube(ID3D11DeviceContext * pContext, float size, size_t tessellation)
	: m_world(Matrix::Identity), m_color(Colors::White), m_position(Vector3::Zero), m_velocity(Vector3::Zero), m_size(1.0f), m_rotation(Quaternion::Identity)
{
	// 球の作成
	m_pCube = GeometricPrimitive::CreateCube(pContext, size, true);
}

/// <summary>
/// 描画
/// </summary>
/// <param name="view">ビュー行列</param>
/// <param name="projection">射影行列</param>
void MyLibrary::Cube::Draw(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix projection)
{
	// ワールド行列の作成
	Matrix trans = Matrix::CreateTranslation(m_position);
	Matrix scale = Matrix::CreateScale(m_size);
	Matrix rot = Matrix::CreateFromQuaternion(m_rotation);
	m_world = scale * rot * trans;

	// 球の描画
	m_pCube->Draw(m_world, view, projection, m_color, nullptr, true);
}

/// <summary>
/// 位置の設定
/// </summary>
/// <param name="positon">座標</param>
void MyLibrary::Cube::SetPosition(DirectX::SimpleMath::Vector3 positon)
{
	m_position = positon;
}

/// <summary>
/// 位置の設定
/// </summary>
/// <param name="x">x</param>
/// <param name="y">y</param>
/// <param name="z">z</param>
void MyLibrary::Cube::SetPosition(float x, float y, float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

/// <summary>
/// 座標の取得
/// </summary>
/// <returns></returns>
DirectX::SimpleMath::Vector3 MyLibrary::Cube::GetPosition()
{
	return m_position;
}

/// <summary>
/// 回転の設定
/// </summary>
/// <param name="rotation"></param>
void MyLibrary::Cube::SetRotation(DirectX::SimpleMath::Quaternion rotation)
{
	m_rotation = rotation;
}

/// <summary>
/// 回転の設定
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <param name="w"></param>
void MyLibrary::Cube::SetRotation(float x, float y, float z, float w)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
	m_rotation.w = w;
}

/// <summary>
/// 回転の取得
/// </summary>
/// <returns></returns>
DirectX::SimpleMath::Quaternion MyLibrary::Cube::GetRotation()
{
	return m_rotation;
}

/// <summary>
/// 色の設定
/// </summary>
/// <param name="color"></param>
void MyLibrary::Cube::SetColor(DirectX::FXMVECTOR color)
{
	m_color = color;
}

/// <summary>
/// 大きさの設定
/// </summary>
/// <param name="scale"></param>
void MyLibrary::Cube::SetScale(float scale)
{
	m_size = scale;
}

/// <summary>
/// 大きさの取得
/// </summary>
/// <returns></returns>
float MyLibrary::Cube::GetScale()
{
	return m_size;
}