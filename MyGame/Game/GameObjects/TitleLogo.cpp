//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "TitleLogo.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TitleLogo::TitleLogo()
{
}

/// <summary>
/// 初期化処理
/// </summary>
void TitleLogo::Initialize()
{
	// スクリーンサイズ
	long right = DeviceResources::GetInstance()->GetOutputSize().right;
	long top = DeviceResources::GetInstance()->GetOutputSize().top;

	// 自身の座標を設定する
	GetTransform()->SetPosition(500, 0, 0);

	// ロゴを作成する
	Sprite* pLogo = new Sprite;
	pLogo->SetTexture(TextureRepository::GetInstance()->GetTexture(L"toywars"));
	pLogo->AnchorPoint() = Vector2(1, 0);
	pLogo->GetTransform()->SetPosition(static_cast<float>(right), static_cast<float>(top), 0);
	AddChild(pLogo);

	// 画面インフラグをオンにする
	m_flag.On(IS_IN);
	m_flag.Off(IS_OUT);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void TitleLogo::Update(float elapsedTime)
{
	// 画面イン時の処理
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
		pos = XMVectorLerp(pos, Vector3(500, pos.y, pos.z), OUT_SPEED * elapsedTime);
		GetTransform()->SetPosition(pos);
	}
	// スペースキーインプット
	//const bool isSpace = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::Space));
	//if (isSpace)
	//{
	//	// 「画面イン」フラグをオフにする
	//	m_flag.Off(IS_IN);
	//	// 「画面アウト」フラグをオンにする
	//	m_flag.On(IS_OUT);
	//}
}
