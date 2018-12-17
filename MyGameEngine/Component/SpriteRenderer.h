//
// SpriteRenderer.h
//
#pragma once

#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// スプライト描画クラス
	/// </summary>
	class SpriteRenderer : public Component
	{
	public:

		// コンストラクタ
		SpriteRenderer();
		// デストラクタ
		~SpriteRenderer();

		// テクスチャデータを設定
		void SetTexture(const wchar_t*);
	};
}
