//
// DebugText.h
// 作成者: 玉村柊希
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <vector>

#include "../Common/DeviceResources.h"


// クラスの定義 ---------------------------------------------------------------------------
namespace MyLibrary
{
	// デバッグ用テキストクラス
	class DebugText
	{
	public:
		static DebugText* GetInstance();
	private:
		static std::unique_ptr<DebugText> m_Instance;

	public:
		// テキスト1個分のデータ
		struct Text
		{
			// 表示位置
			DirectX::XMFLOAT2	pos;
			// 表示文字列
			std::wstring	str;
		};

		// コンストラクタ
		DebugText();
		// デストラクタ
		virtual ~DebugText();
		// 初期化
		void Initialize(ID3D11Device*	d3dDevice, ID3D11DeviceContext* d3dContext);
		// 描画
		// ※必ずSpriteBatchのBegin()とEnd()の間で呼び出すこと。
		void Draw();
		// テキスト追加（フォーマット指定付き）
		void AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...);
	protected:
		// スプライトバッチ
		std::unique_ptr<DirectX::SpriteBatch>	spriteBatch;
		// スプライトフォント
		std::unique_ptr<DirectX::SpriteFont>	spriteFont;
		// 文字列の配列
		std::vector<DebugText::Text> textArray;
	};
}
