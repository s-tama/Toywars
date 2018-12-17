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
	m_scale(1.f), 
	m_world(Matrix::Identity), 
	m_direction(0.f),
	m_pParent(nullptr),
	m_reflection(Vector3::Zero)
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
/// 反射する
/// </summary>
/// <param name="reflection"></param>
void Transform::Reflection(DirectX::SimpleMath::Vector3 reflection)
{
	m_reflection = reflection;
}

/// <summary>
/// 反射する
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="z"></param>
void MyLibrary::Transform::Reflection(float x, float y, float z)
{
	m_reflection = Vector3(x, y, z);
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
