//
// SelectButton.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "SelectButton.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
SelectButton::SelectButton():
	m_pText(nullptr),
	m_pSelect(nullptr),
	m_count(0)
{
	m_pText = new Sprite;
	m_pText->SetTexture(TextureRepository::GetInstance()->GetTexture(L"text_playMode"));
}

/// <summary>
/// 初期化処理
/// </summary>
void SelectButton::Initialize()
{
	// 選択フレーム
	Sprite* pSelect = new Sprite();
	pSelect->SetTexture(TextureRepository::GetInstance()->GetTexture(L"frame_nowSelect"));
	pSelect->AnchorPoint() = Vector2(0, 0);
	pSelect->Scale() = 1.1f;
	pSelect->Color() = Colors::Blue;
	pSelect->Color().w = 0;
	AddChild(pSelect);
	m_pSelect = pSelect;

	// フレーム
	Sprite* pFrame = new Sprite();
	pFrame->SetTexture(TextureRepository::GetInstance()->GetTexture(L"frame_select"));
	pFrame->AnchorPoint() = Vector2(0, 0);
	AddChild(pFrame);

	// テキスト
	AddChild(m_pText);

	if (GetTag() != "TrainingButton")
	{
		pFrame->Color() = Colors::Black;
		pFrame->Color().w = 0.5f;
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void SelectButton::Update(float elapsedTime)
{
	// 画面イン
	if (m_flag.Check(IS_IN))
	{
		Vector3 pos = GetTransform()->GetPosition();
		pos = XMVectorLerp(pos, Vector3(0, pos.y, pos.z), IN_SPEED * elapsedTime);
		GetTransform()->SetPosition(pos);
	}
	// 画面アウト
	else if (m_flag.Check(IS_OUT))
	{
		Vector3 pos = GetTransform()->GetPosition();
		pos = XMVectorLerp(pos, Vector3(-400, pos.y, pos.z), OUT_SPEED * elapsedTime);
		GetTransform()->SetPosition(pos);
	}

	if (m_flag.Check(IS_SELECT))
	{
		//m_pSelect->Color().x = Math::GetRand<float>(0, 1.0f);
		//m_pSelect->Color().y = Math::GetRand<float>(0, 1.0f);
		//m_pSelect->Color().z = Math::GetRand<float>(0, 1.0f);
		m_pSelect->Color().w = std::abs(cos(m_count));
	}
	else m_pSelect->Color().w = 0;

	m_count += elapsedTime;
}

