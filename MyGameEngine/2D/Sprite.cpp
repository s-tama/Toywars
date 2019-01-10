//
// Sprite.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------------
#include "Sprite.h"
#include "TextureLoader.h"
#include "../Component/Transform.h"
#include "../Common/DeviceResources.h"



// usingディレクティブ ------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pTexture">テクスチャ</param>
Sprite::Sprite():
	m_pTexture(nullptr),
	m_color(Colors::White),
	m_rect{ 0, 0, 0, 0 },
	m_anchorPoint(Vector2::Zero),
	m_rotation(0),
	m_scale(1),
	m_pSpriteRenderer(nullptr)
{
	m_pSpriteRenderer = SpriteRenderer::GetInstance();
}

/// <summary>
/// 描画処理
/// </summary>
void Sprite::DrawSprite()
{
	if (((m_pTexture) && (m_pTransform->GetParent())))
	{
		GameObject* pParent = m_pTransform->GetParent();
		UINT w = m_pTexture->desk.Width;
		UINT h = m_pTexture->desk.Height;
		Vector2 offset = Vector2(static_cast<float>(w) * m_anchorPoint.x, static_cast<float>(h) * m_anchorPoint.y);
		Vector2 pos = pParent->GetTransform()->GetPosition() + m_pTransform->GetPosition();
//		Quaternion rot = pParent->GetTransform()->GetRotation() + m_pTransform->GetRotation();
		m_pSpriteRenderer->Draw(m_pTexture->pHandle.Get(), pos - offset, &m_rect, m_color, m_rotation, Vector2::Zero, Vector2(m_scale, m_scale));
	}
}

/// <summary>
/// テクスチャを設定する
/// </summary>
/// <param name="pTexture">テクスチャハンドル</param>
void Sprite::SetTexture(Texture* pTexture)
{
	m_pTexture = pTexture;
	m_color = Colors::White;
	m_rect = RECT{ 0, 0, static_cast<LONG>(m_pTexture->desk.Width), static_cast<LONG>(m_pTexture->desk.Height) };
	m_anchorPoint = Vector2(0.5f, 0.5f);
}

/// <summary>
/// テクスチャを取得する
/// </summary>
/// <returns>テクスチャハンドル</returns>
Texture* MyLibrary::Sprite::GetTexture()
{
	return m_pTexture;
}

/// <summary>
/// 切り取り情報を取得
/// </summary>
/// <returns></returns>
RECT& MyLibrary::Sprite::Rect()
{
	return m_rect;
}

/// <summary>
/// 色の取得
/// </summary>
/// <returns></returns>
Vector4& MyLibrary::Sprite::Color()
{
	return m_color;
}

/// <summary>
/// アンカーポイントを取得
/// </summary>
/// <returns></returns>
Vector2& MyLibrary::Sprite::AnchorPoint()
{
	return m_anchorPoint;
}

/// <summary>
/// 回転情報
/// </summary>
/// <returns></returns>
float& Sprite::Rotation()
{
	return m_rotation;
}

/// <summary>
/// スケール
/// </summary>
/// <returns></returns>
float& MyLibrary::Sprite::Scale()
{
	return m_scale;
}
