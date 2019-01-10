//
// Transform.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "Transform.h"

#include "../GameObject/GameObject.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Transform::Transform() : 
	m_position(Vector3::Zero), 
	m_rotation(Quaternion::Identity), 
	m_rotationWorld(Vector3::Zero),
	m_scale(1.f), 
	m_world(Matrix::Identity), 
	m_direction(0.f),
	m_pParent(nullptr)
{
}

/// <summary>
/// デストラクタ
/// </summary>
Transform::~Transform()
{
}

/// <summary>
/// 移動
/// </summary>
/// <param name="translate"></param>
void Transform::Translate(Vector3 translate)
{
	Vector3 v3 = Vector3::Zero;
	v3 = translate;
	v3 = Vector3::Transform(v3, m_rotation);
	m_position += v3;
}

/// <summary>
/// 移動
/// </summary>
/// <param name="x">x</param>
/// <param name="y">y</param>
/// <param name="z">z</param>
void Transform::Translate(float x, float y, float z)
{
	Vector3 v3 = Vector3::Zero;
	v3 = Vector3(x, y, z);
	v3 = Vector3::Transform(v3, m_rotation);
	m_position += v3;
}

/// <summary>
/// 反転移動
/// </summary>
/// <param name="translate"></param>
void Transform::ReflectTranslate(DirectX::SimpleMath::Vector3 translate)
{
	Vector3 v3 = Vector3::Zero;
	v3 += translate;
	v3 = Vector3::Transform(v3, m_rotation);
	m_position -= v3;
}

/// <summary>
/// 回転
/// </summary>
/// <param name="v">軸</param>
/// <param name="dir">回転量</param>
void Transform::Rotate(DirectX::SimpleMath::Vector3 v, float dir)
{
	m_direction += XMConvertToRadians(dir);
	m_rotation = Quaternion::CreateFromAxisAngle(v, m_direction);
}

/// <summary>
/// 回転
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
/// <param name="space"></param>
void Transform::Rotate(float x, float y, float z, Space space)
{
	auto RotateWorld = [=]
	{
		m_rotationWorld.x += XMConvertToRadians(x);
		m_rotationWorld.y += XMConvertToRadians(y);
		m_rotationWorld.z += XMConvertToRadians(z);
		
		Matrix rotX = Matrix::CreateRotationX(m_rotationWorld.x);
		Matrix rotY = Matrix::CreateRotationY(m_rotationWorld.y);
		Matrix rotZ = Matrix::CreateRotationZ(m_rotationWorld.z);
		Matrix rot = rotX * rotY * rotZ;
		m_rotation = Quaternion::CreateFromRotationMatrix(rot);
	};

	auto RotateSelf = [=]
	{
		float dx = 0;
		float dy = 0;
		float dz = 0;
		dx += XMConvertToRadians(x);
		dy += XMConvertToRadians(y);
		dz += XMConvertToRadians(z);
		Quaternion rx = Quaternion::CreateFromAxisAngle(Vector3::Right, dx);
		Quaternion ry = Quaternion::CreateFromAxisAngle(Vector3::Up, dy);
		Quaternion rz = Quaternion::CreateFromAxisAngle(Vector3::Forward, dz);
		m_rotation *= rx * ry * rz;
	};

	switch (space)
	{
	case MyLibrary::Transform::WORLD:
		RotateWorld();
		break;
	case MyLibrary::Transform::SELF:
		RotateSelf();
		break;
	}
}

/// <summary>
/// 注視処理
/// </summary>
/// <param name="target">ターゲット座標</param>
/// <returns></returns>
Matrix Transform::LookAt(DirectX::SimpleMath::Vector3& target)
{
	return Matrix::CreateBillboard(m_position, target, Vector3::Up);
}

/// <summary>
/// 回転情報を設定
/// </summary>
/// <param name="x">x</param>
/// <param name="y">y</param>
/// <param name="z">z</param>
/// <param name="space">space</param>
void Transform::SetRotation(float x, float y, float z, Space space)
{
	auto RotateWorld = [=]
	{
		m_rotationWorld.x = XMConvertToRadians(x);
		m_rotationWorld.y = XMConvertToRadians(y);
		m_rotationWorld.z = XMConvertToRadians(z);

		Matrix rotX = Matrix::CreateRotationX(m_rotationWorld.x);
		Matrix rotY = Matrix::CreateRotationY(m_rotationWorld.y);
		Matrix rotZ = Matrix::CreateRotationZ(m_rotationWorld.z);
		Matrix rot = rotX * rotY * rotZ;
		m_rotation = Quaternion::CreateFromRotationMatrix(rot);
	};

	auto RotateSelf = [=]
	{
		Quaternion rx = Quaternion::CreateFromAxisAngle(GetRight(), XMConvertToRadians(x));
		Quaternion ry = Quaternion::CreateFromAxisAngle(GetUp(), XMConvertToRadians(y));
		Quaternion rz = Quaternion::CreateFromAxisAngle(GetForward(), XMConvertToRadians(z));
		m_rotation = rx * ry * rz;
	};

	switch (space)
	{
	case MyLibrary::Transform::WORLD:
		RotateWorld();
		break;
	case MyLibrary::Transform::SELF:
		RotateSelf();
		break;
	}
}

/// <summary>
/// 前方ベクトルを取得する
/// </summary>
/// <returns></returns>
Vector3 Transform::GetForward()
{
	return Vector3::Transform(Vector3::Forward, m_rotation);
}

/// <summary>
/// 右方向ベクトル
/// </summary>
/// <returns></returns>
Vector3 Transform::GetRight()
{
	return Vector3::Transform(Vector3::Right, m_rotation);
}

/// <summary>
/// 上方向ベクトル
/// </summary>
/// <returns></returns>
Vector3 Transform::GetUp()
{
	return Vector3::Transform(Vector3::Up, m_rotation);
}
