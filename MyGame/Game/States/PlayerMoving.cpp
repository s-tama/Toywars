//
// PlayerMoving.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "PlayerMoving.h"

#include "PlayerStanding.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -------------------------------------------------------
std::unique_ptr<PlayerMoving> PlayerMoving::m_pInstance = nullptr;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
PlayerMoving::PlayerMoving() :
	m_elapsedTime(0)
{
}

/// <summary>
/// クラスのインスタンスを取得する
/// </summary>
/// <returns>インスタンス</returns>
PlayerMoving* PlayerMoving::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new PlayerMoving);
	return m_pInstance.get();
}

/// <summary>
/// 実行
/// </summary>
void PlayerMoving::Execute(float elapsedTime)
{
	m_elapsedTime = elapsedTime;

	if (m_pPlayer == nullptr) return;

	// キーが押されたかのフラグ定数
	const bool isUp		=	(System::InputDevice::GetInstance()->GetKeyState().W != false);
	const bool isDown	=	(System::InputDevice::GetInstance()->GetKeyState().S != false);
	const bool isRight	=	(System::InputDevice::GetInstance()->GetKeyState().D != false);
	const bool isLeft	=	(System::InputDevice::GetInstance()->GetKeyState().A != false);
	const bool isX		=	(System::InputDevice::GetInstance()->GetKeyState().X != false);
	const bool isZ		=	(System::InputDevice::GetInstance()->GetKeyState().Z != false);
	
	if (isUp)			MoveForward();		// 前進
	else if (isDown)	MoveBack();			// 後退
	if (isRight)		RotationRight();	// 右回転
	else if (isLeft)	RotationLeft();		// 左回転

	// ネジを回転させる
	GameObject* pScrew = m_pPlayer->FindGameObjectWithTag("Screw");
	pScrew->GetTransform()->Rotate(pScrew->GetTransform()->GetForward(), 90 * elapsedTime);

	// プレイヤーを「立ち」状態に変更
	m_pPlayer->ChangeState(PlayerStanding::GetInstance());
}

#pragma region 移動
/// <summary>
/// 前進
/// </summary>
void PlayerMoving::MoveForward()
{
	Vector3 pos = m_pPlayer->GetTransform()->GetPosition();
	Vector3 trans = -m_pPlayer->GetTransform()->GetForward() * Player::ADVANCE_SPEED * m_elapsedTime;
	pos += trans;
	m_pPlayer->GetTransform()->SetPosition(pos);

	LimitMove(trans);
}

/// <summary>
/// 後退
/// </summary>
void PlayerMoving::MoveBack()
{
	Vector3 pos = m_pPlayer->GetTransform()->GetPosition();
	Vector3 trans = m_pPlayer->GetTransform()->GetForward() * Player::ADVANCE_SPEED * m_elapsedTime;
	pos += trans;
	m_pPlayer->GetTransform()->SetPosition(pos);

	LimitMove(trans);
}

/// <summary>
/// 右回転
/// </summary>
void PlayerMoving::RotationRight()
{
	Vector3 axis = m_pPlayer->GetTransform()->GetUp();
	float rot = -Player::ROTATION_SPEED * m_elapsedTime;
	m_pPlayer->GetTransform()->Rotate(axis, rot);
}

/// <summary>
/// 左回転
/// </summary>
void PlayerMoving::RotationLeft()
{
	Vector3 axis = m_pPlayer->GetTransform()->GetUp();
	float rot = Player::ROTATION_SPEED * m_elapsedTime;
	m_pPlayer->GetTransform()->Rotate(axis, rot);
}

/// <summary>
/// 移動制限
/// </summary>
/// <param name="velocity">速度</param>
void PlayerMoving::LimitMove(Vector3& velocity)
{
	Vector3 pos = m_pPlayer->GetTransform()->GetPosition();
	if (Math::Abs(pos.x) > 48)
	{
		pos.x -= velocity.x;
		m_pPlayer->GetTransform()->SetPosition(pos);
	}
	pos = m_pPlayer->GetTransform()->GetPosition();
	if (Math::Abs(pos.z) > 48)
	{
		pos.z -= velocity.z;
		m_pPlayer->GetTransform()->SetPosition(pos);
	}
	
	for (auto obstacles : m_pPlayer->GetObstacles())
	{
		Vector3 pPos = m_pPlayer->GetTransform()->GetPosition();
		Vector3 oPos = obstacles->GetTransform()->GetPosition();
		if ((Math::Distance(pPos.x, oPos.x) < 11)
			&& (Math::Distance(pPos.z, oPos.z) < 11))
		{
			pos -= velocity;
			m_pPlayer->GetTransform()->SetPosition(pos);
		}
	}
}
#pragma endregion


//// 速度
//Vector3 vel;
//// プレイヤーの方向
//float dir = m_pPlayer->GetTransform()->GetDirection();

//// キー入力
//if (isUp)				vel.z = Player::ADVANCE_SPEED * elapsedTime;
//else if (isDown)		vel.z = -Player::ADVANCE_SPEED * elapsedTime;
//if (isRight)			m_pPlayer->GetTransform()->SetDirection(dir - XMConvertToRadians(Player::ROTATION_SPEED) * elapsedTime);
//else if (isLeft)		m_pPlayer->GetTransform()->SetDirection(dir + XMConvertToRadians(Player::ROTATION_SPEED) * elapsedTime);

//// プレイヤーの角度
//const Quaternion axisAngle = Quaternion::CreateFromAxisAngle(Vector3(0, 1, 0), dir);
//// プレイヤーの座標
//Vector3 pos = m_pPlayer->GetTransform()->GetPosition();

//// プレイヤーの移動
//m_pPlayer->GetTransform()->SetRotation(axisAngle);
//vel = Vector3::Transform(vel, m_pPlayer->GetTransform()->GetRotation());
//m_pPlayer->SetVelocity(vel);
//m_pPlayer->GetTransform()->SetPosition(pos + m_pPlayer->GetVelocity());

//LimitMove(vel);