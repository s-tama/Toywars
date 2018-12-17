//
// Bullet.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------------
#include "Bullet.h"

#include "MainCamera.h"



// usingディレクティブ ---------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ定数の定義 -------------------------------------------------------------
const float Bullet::ADVANCE_SPEED = 48;
const float Bullet::ROTATION_SPEED = 180;



// メンバ関数の定義 -----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Bullet::Bullet():
	m_pOwner(nullptr),
	m_velocity(Vector3::Zero),
	m_attribute(Attribute::NORMAL)
{
	SetTag("Bullet");
}

/// <summary>
/// 初期化処理
/// </summary>
void Bullet::Initialize()
{
	// ビー玉を作成して子に追加
	Obj3D* pObj = new Obj3D;
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"Marble"));
	pObj->SetLight(true);
	pObj->GetTransform()->SetScale(2);
	AddChild(pObj);

	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3(0, 0, 0), Vector3(1, 1, 1));
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Bullet::Update(float elapsedTime)
{
	// 通常状態の場合
	if (m_attribute == Attribute::NORMAL)
	{
		// 一直線に進める
		this->GetTransform()->Translate(0, 0, Bullet::ADVANCE_SPEED * elapsedTime);
	}
}

/// <summary>
/// フラグを取得する
/// </summary>
/// <returns>フラグ</returns>
Utility::Flag& Bullet::GetFlag()
{
	return m_flag;
}

/// <summary>
/// 所有者を設定する
/// </summary>
/// <param name="pOwner"></param>
void Bullet::SetOwner(MyLibrary::GameObject* pOwner)
{
	m_pOwner = pOwner;
}

/// <summary>
/// 所有者の情報を取得する
/// </summary>
/// <returns></returns>
GameObject* MyGame::Bullet::GetOwner()
{
	return m_pOwner;
}

/// <summary>
/// 速度ベクトルを設定する
/// </summary>
/// <param name="velocity">速度ベクトル</param>
void Bullet::SetVelocity(DirectX::SimpleMath::Vector3 velocity)
{
	m_velocity = velocity;
}

/// <summary>
/// 速度ベクトルを取得する
/// </summary>
/// <returns>速度ベクトル</returns>
DirectX::SimpleMath::Vector3 Bullet::GetVelocity()
{
	return m_velocity;
}

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="collider"></param>
void Bullet::OnCollisionStay(MyLibrary::GameObject* collider)
{
	if (collider->GetTag() == "Obstacle")
	{
		// ヒットフラグをオンにする
		m_flag.On(IS_HIT_OBSTACLE);
	}
	if (collider->GetTag() == "Enemy")
	{
		if (this->m_pOwner->GetTag() == "Player")
		{
			collider->SetActive(false);
			m_flag.On(IS_HIT_OBSTACLE);
		}
	}
	if (collider->GetTag() == "Player")
	{
		if (this->m_pOwner->GetTag() == "Enemy")
		{
			collider->SetActive(false);
			m_flag.On(IS_HIT_OBSTACLE);
		}
	}
}
