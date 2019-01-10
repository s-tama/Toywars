//
// Sprite3D.h
//
#pragma once



// ヘッダーファイルのインクルード ------------------------------------------------------------------
#include <vector>

#include "../GameObject/GameObject.h"
#include "../2D/Texture.h"
#include "PrimitiveRenderer.h"
#include "../Camera/Camera.h"



// 構造体の定義 ------------------------------------------------------------------------------------
namespace MyLibrary
{ 
	/// <summary>
	/// Rect構造体
	/// </summary>
	struct Rectf
	{
		float left;
		float top;
		float right;
		float bottom;
	};
}



// クラスの定義 ------------------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// スプライトクラス
	/// </summary>
	class Sprite3D : public GameObject
	{
	private:

		const byte IS_BILLBOARD = 1 << 7;	// ビルボードフラグ


	public:

		// コンストラクタ
		Sprite3D();

		// 開始処理
		void Start() override;
		// 初期化処理
		void Initialize() override;
		// 描画処理
		void DrawPrimitive() override;

		// テクスチャ情報
		void SetTexture(Texture* pTexture);
		Texture* GetTexture();

		// サイズ情報
		DirectX::SimpleMath::Vector2& Size();

		// スケール情報
		DirectX::SimpleMath::Vector2& Scale();

		// ビルボード設定
		void Billboard();

		// 切り取り情報
		Rectf& Rect();

		// 自動でサイズを設定
		void AutoSize();


	private:

		Texture* m_pTexture;	// テクスチャハンドル

		PrimitiveRenderer* m_pPrimitiveRenderer;	// プリミティブレンダラーへのポインタ

		Camera* m_pCamera;	// カメラへのポインタ

		DirectX::SimpleMath::Vector2 m_size;	// サイズ
		DirectX::SimpleMath::Vector2 m_scale;	// スケール
		Rectf m_rect;							// 切り取り情報

		Utility::Flag m_flag;		// フラグ
	};
}

