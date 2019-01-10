//
// SpriteRenderer.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <memory>
#include <string>
#include <d3d11_1.h>

#include <SpriteBatch.h>
#include <SimpleMath.h>
#include <DirectXColors.h>
#include <CommonStates.h>


// クラスの定義 -----------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// スプライト描画クラス
	/// </summary>
	class SpriteRenderer
	{
	private:

		// コンストラクタ
		SpriteRenderer();


	public:

		// インスタンスを取得
		static SpriteRenderer* GetInstance();

		// 初期化処理
		void Initialize(ID3D11Device* pDevice, ID3D11DeviceContext* pContext);
		// 描画処理
		void Draw(ID3D11ShaderResourceView* pTexture, const DirectX::XMFLOAT2& position, const RECT* sourceRectangle, DirectX::XMVECTOR color = DirectX::Colors::White, float rotation = 0, const DirectX::XMFLOAT2& origin = DirectX::SimpleMath::Vector2(0, 0), const DirectX::XMFLOAT2& scale = DirectX::SimpleMath::Vector2(1, 1));

		// 描画に必要な関数
		void Begin();
		void End();


	private:

		// デバイス
		ID3D11Device* m_pDevice;
		// デバイスコンテキスト
		ID3D11DeviceContext* m_pContext;

		// スプライトバッチ
		std::unique_ptr<DirectX::SpriteBatch> m_pSpriteBatch;
		// コモンステート
		std::unique_ptr<DirectX::CommonStates> m_pCommonStates;

		// インスタンス
		static std::unique_ptr<SpriteRenderer> m_pInstance;
	};
}
