//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "Background.h"
#include <math.h>



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Background::Background():
	m_angle(0.f)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void Background::Initialize()
{
	Sprite3D* pSprite = new Sprite3D();
	pSprite->SetTexture(TextureRepository::GetInstance()->GetTexture(L"background_title"));
	pSprite->AutoSize();
//	pSprite->Scale() = Vector2(6, 6);
	AddChild(pSprite);

	m_pTransform->SetScale(6);
	m_pTransform->SetPosition(2, 0, 0);
	m_pTransform->SetRotation(0, 0, 0);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Background::Update(float elapsedTime)
{
	Vector3 rot = Vector3(0, m_angle, 0);
	rot = XMVectorLerp(rot, Vector3(0, -30, 0), elapsedTime);
	m_angle = rot.y;
	m_pTransform->SetRotation(0, m_angle, 0);
}
