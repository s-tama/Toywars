//
// EffectFactory.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------
#include "EffectFactory.h"

#include "EffectBase.h"
#include "BreakEffect.h"
#include "PoppingEffect.h"



// usingディレクティブ -----------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 --------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
MyGame::EffectFactory::EffectFactory()
{
	SetTag("EffectFactory");
}

/// <summary>
/// 初期化処理
/// </summary>
void MyGame::EffectFactory::Initialize()
{
	// 爆発エフェクト
	m_effects.pExplosion.resize(NUM_EFFECTS);
	for (int i = 0; i < NUM_EFFECTS; i++)
	{
		m_effects.pExplosion[i] = new BreakEffect();
		m_effects.pExplosion[i]->Stop();
		NodeManager::AddNode(m_effects.pExplosion[i]);
	}

	// はじけるエフェクト
	m_effects.pPopping.resize(NUM_EFFECTS);
	for (int i = 0; i < NUM_EFFECTS; i++)
	{
		m_effects.pPopping[i] = new PoppingEffect();
		m_effects.pPopping[i]->Stop();
		NodeManager::AddNode(m_effects.pPopping[i]);
	}
}

/// <summary>
/// 作成処理
/// </summary>
/// <param name="effectID"></param>
MyGame::EffectBase* MyGame::EffectFactory::Create(EffectID effectID)
{
	switch (effectID)
	{
	case EffectID::EXPLOSION:
		for (int i = 0; i < NUM_EFFECTS; i++)
		{
			if (m_effects.pExplosion[i]->IsActive() != true)
			{
				m_effects.pExplosion[i]->Play(MyGame::PlayMode::ONE);
				return m_effects.pExplosion[i];
			}
		}
		break;
	case EffectID::POPPING:
		for (int i = 0; i < NUM_EFFECTS; i++)
		{
			if (m_effects.pPopping[i]->IsActive() != true)
			{
				m_effects.pPopping[i]->Play(MyGame::PlayMode::ONE);
				return m_effects.pPopping[i];
			}
		}
		break;
	}

	return nullptr;
}
