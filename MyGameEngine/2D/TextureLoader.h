//
// TextureLoader.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <memory>
#include <string>
#include <d3d11_1.h>

#include "Texture.h"


// クラスの定義 ------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// テクスチャ読み込みクラス
	/// </summary>
	class TextureLoader
	{
	private:

		static const std::wstring RESOURCE_DIRECTORY;	// リソースのディレクトリ
		static const std::wstring RESOURCE_FILENAME;	// リソースの拡張子


	public:

		// テクスチャデータを読み込む
		Texture* LoadTexture(const wchar_t*);
	};
}
