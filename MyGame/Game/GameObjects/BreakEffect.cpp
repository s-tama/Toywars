//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "BreakEffect.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
BreakEffect::BreakEffect() :
	EffectBase(),
	m_time(0.f)
{
	SetTag("BreakEffect");
}

/// <summary>
/// 初期化処理
/// </summary>
void BreakEffect::Start()
{
	// ロゴを作成する
	m_pSprite = new Sprite3D();
	m_pSprite->SetTexture(TextureRepository::GetInstance()->GetTexture(L"explosion"));
	m_pSprite->Scale() = Vector2(2, 2);
	m_pSprite->Rect().left = 0;
	m_pSprite->Rect().top = 0;
	m_pSprite->Rect().right = 0.1f;
	m_pSprite->Rect().bottom = (1.0f / 3.0f);
	m_pSprite->Billboard();
	AddChild(m_pSprite);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void BreakEffect::Update(float elapsedTime)
{
	if (!m_flag.Check(IS_PLAY)) return;

	m_time += elapsedTime;

	// アニメーションする
	if (m_time > 0.01f)
	{
		m_pSprite->Rect().left += 0.1f;
		m_pSprite->Rect().right += 0.1f;

		if (m_pSprite->Rect().left > 1)
		{
			m_pSprite->Rect().left = 0;
			m_pSprite->Rect().top += 1.0f / 3.0f;
			m_pSprite->Rect().bottom += 1.0f / 3.0f;
			m_pSprite->Rect().right = 0.1f;

			if (m_pSprite->Rect().top > 1)
			{
				m_pSprite->Rect().left = 0;
				m_pSprite->Rect().top = 0;
				m_pSprite->Rect().right = 0.1f;
				m_pSprite->Rect().bottom = 1.0f / 3.0f;

				// 再生モードが一度のみ
				if (!m_flag.Check(IS_LOOP))
				{
					Stop();	// 停止する
				}
			}
		}

		m_time = 0;
	}
}
