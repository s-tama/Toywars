//
// EffectBase.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------
#include "EffectBase.h"



// usingディレクティブ -----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 --------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EffectBase::EffectBase():
	m_pSprite(nullptr)
{
}

/// <summary>
/// デストラクタ
/// </summary>
EffectBase::~EffectBase()
{
}

/// <summary>
/// 開始処理
/// </summary>
void EffectBase::Start()
{
	// 活動を停止する
	SetActive(false);
}

/// <summary>
/// 再生する
/// </summary>
/// <param name="playMode">再生モード</param>
void EffectBase::Play(PlayMode playMode)
{
	SetActive(true);
	m_flag.On(IS_PLAY);
	if (playMode == PlayMode::LOOP)
	{
		m_flag.On(IS_LOOP);
	}
}

/// <summary>
/// 停止
/// </summary>
void EffectBase::Stop()
{
	SetActive(false);
	m_flag.Off(IS_PLAY);
	m_flag.Off(IS_LOOP);
	m_pTransform->SetPosition(Vector3::Zero);
}

/// <summary>
/// 再生中か
/// </summary>
/// <returns></returns>
bool EffectBase::IsPlaying()
{
	return m_flag.Check(IS_PLAY);
}
