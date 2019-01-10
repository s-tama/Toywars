//
// Sprite3D.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------------
#include "Sprite3D.h"
#include "../Component/Transform.h"
#include "../Common/DeviceResources.h"
#include "../Node/NodeManager.h"

#include "../2D/DebugText.h"



// usingディレクティブ ------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pTexture">テクスチャ</param>
Sprite3D::Sprite3D() :
	m_pTexture(nullptr),
	m_pPrimitiveRenderer(nullptr),
	m_pCamera(nullptr),
	m_size(Vector2(1, 1)),
	m_scale(Vector2(1, 1)),
	m_rect{ 0, 0, 1, 1 }
{
	m_pPrimitiveRenderer = PrimitiveRenderer::GetInstance();
}

/// <summary>
/// 開始処理
/// </summary>
void Sprite3D::Start()
{
	// カメラオブジェクトへのポインタを設定
	GameObject* pObj = NodeManager::FindGameObjectWithTag("MainCamera");
	m_pCamera = dynamic_cast<Camera*>(pObj);
}

/// <summary>
/// 初期化処理
/// </summary>
void Sprite3D::Initialize()
{
	// カメラオブジェクトへのポインタを設定
	GameObject* pObj = NodeManager::FindGameObjectWithTag("MainCamera");
	m_pCamera = dynamic_cast<Camera*>(pObj);
}

/// <summary>
/// 描画処理
/// </summary>
void Sprite3D::DrawPrimitive()
{
	// 頂点情報
	std::vector<VertexPositionTexture> vertices;
	vertices.resize(4);

	vertices[0] = VertexPositionTexture(Vector3(m_size.x, m_size.y, 0) * m_scale, Vector2(m_rect.left, m_rect.top));
	vertices[1] = VertexPositionTexture(Vector3(-m_size.x, m_size.y, 0) * m_scale, Vector2(m_rect.right, m_rect.top));
	vertices[2] = VertexPositionTexture(Vector3(-m_size.x, -m_size.y, 0) * m_scale, Vector2(m_rect.right, m_rect.bottom));
	vertices[3] = VertexPositionTexture(Vector3(m_size.x, -m_size.y, 0) * m_scale, Vector2(m_rect.left, m_rect.bottom));

	// 変換する
	GameObject* pParent = m_pTransform->GetParent();
	Vector3 pos = pParent->GetTransform()->GetPosition() + m_pTransform->GetPosition();

	// ワールド行列を作成する
	Matrix world = m_pTransform->GetWorld() * m_pTransform->GetParent()->GetTransform()->GetWorld();
	if (m_flag.Check(IS_BILLBOARD))
	{
		world = Matrix::CreateBillboard(pos, m_pCamera->GetTransform()->GetPosition(), Vector3::Up);
	}

	// 描画する
	m_pPrimitiveRenderer->Draw(m_pTexture->pHandle.Get(), vertices, world, m_pCamera->GetView(), m_pCamera->GetProjection());
}

/// <summary>
/// テクスチャを設定する
/// </summary>
/// <param name="pTexture">テクスチャハンドル</param>
void Sprite3D::SetTexture(Texture* pTexture)
{
	m_pTexture = pTexture;
}

/// <summary>
/// テクスチャを取得する
/// </summary>
/// <returns>テクスチャハンドル</returns>
Texture* MyLibrary::Sprite3D::GetTexture()
{
	return m_pTexture;
}

/// <summary>
/// サイズ情報
/// </summary>
/// <returns></returns>
Vector2& Sprite3D::Size()
{
	return m_size;
}

/// <summary>
/// スケール情報
/// </summary>
/// <returns></returns>
Vector2& Sprite3D::Scale()
{
	return m_scale;
}

/// <summary>
/// ビルボード
/// </summary>
void Sprite3D::Billboard()
{
	m_flag.On(IS_BILLBOARD);
}

/// <summary>
/// 切り取り情報
/// </summary>
/// <returns></returns>
Rectf& Sprite3D::Rect()
{
	return m_rect;
}

/// <summary>
/// 自動でサイズを設定
/// </summary>
void Sprite3D::AutoSize()
{
	// 頂点情報を作成
	D3D11_TEXTURE2D_DESC desk = m_pTexture->desk;
	if (desk.Width > desk.Height)
	{
		m_size.x = static_cast<float>(desk.Width) / static_cast<float>(desk.Height);
	}
	else if (desk.Width < desk.Height)
	{
		m_size.y = static_cast<float>(desk.Height) / static_cast<float>(desk.Width);
	}
}
