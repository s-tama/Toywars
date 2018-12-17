//
// SpriteRenderer.cpp
//

#include "SpriteRenderer.h"

#include "../Common/DeviceResources.h"
#include "../2D/Sprite.h"
#include "../GameObject/GameObject.h"
#include "../2D/TextureRepository.h"
#include "Transform.h"

using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;

/// <summary>
/// コンストラクタ
/// </summary>
SpriteRenderer::SpriteRenderer()
{
}

/// <summary>
/// デストラクタ
/// </summary>
SpriteRenderer::~SpriteRenderer()
{
}

/// <summary>
/// テクスチャハンドルを設定
/// </summary>
/// <param name="pTexture">描画したいテクスチャ</param>
void SpriteRenderer::SetTexture(const wchar_t* pFileName)
{
	// スプライトを作成
	//Sprite* pSprite = new Sprite(TextureRepository::GetInstance()->GetTexture(pFileName));
	// トランスフォームを設定
	//pSprite->SetTransform(this->m_pTransform);
	// 子に追加
	//this->AddChild(pSprite);
}
