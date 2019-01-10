//
// SpriteRenderer.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "SpriteRenderer.h"

#include "../Common/DeviceResources.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の実態 ---------------------------------------------------------
std::unique_ptr<SpriteRenderer> SpriteRenderer::m_pInstance = nullptr;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
SpriteRenderer::SpriteRenderer()
{
}

/// <summary>
/// インスタンスを取得
/// </summary>
/// <returns></returns>
SpriteRenderer* SpriteRenderer::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new SpriteRenderer());
	return m_pInstance.get();
}

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="pDevice">デバイス</param>
/// <param name="pContext">デバイスコンテキスト</param>
void SpriteRenderer::Initialize(ID3D11Device* pDevice, ID3D11DeviceContext* pContext)
{
	m_pDevice = pDevice;
	m_pContext = pContext;

	// スプライトバッチの作成
	m_pSpriteBatch = std::make_unique<SpriteBatch>(m_pContext);
	
	// コモンステートの作成
	m_pCommonStates = std::make_unique<CommonStates>(m_pDevice);
}

/// <summary>
/// 描画処理
/// </summary>
/// <param name="pTexture">テクスチャハンドル</param>
/// <param name="position">位置</param>
/// <param name="sourceRectangle">切り取り情報</param>
/// <param name="color">色</param>
/// <param name="rotation">回転</param>
/// <param name="origin">オリジン</param>
/// <param name="scale">スケール</param>
void SpriteRenderer::Draw(ID3D11ShaderResourceView* pTexture, const XMFLOAT2& position, const RECT* sourceRectangle, XMVECTOR color, float rotation, const XMFLOAT2& origin, const XMFLOAT2& scale)
{
	m_pSpriteBatch->Draw(pTexture, position, sourceRectangle, color, rotation, origin, scale);
}

/// <summary>
/// 描画開始
/// </summary>
void SpriteRenderer::Begin()
{
	m_pSpriteBatch->Begin(SpriteSortMode_Deferred, DeviceResources::GetInstance()->GetCommonStates()->NonPremultiplied());
}

void SpriteRenderer::End()
{
	m_pSpriteBatch->End();
}
