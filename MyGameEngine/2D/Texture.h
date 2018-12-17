//
// Texture.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <string>


// クラスの定義 -------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// テクスチャ構造体
	/// </summary>
	struct Texture
	{
		D3D11_TEXTURE2D_DESC desk;									// テクスチャ情報
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pHandle;	// テクスチャハンドル
		std::wstring name;											// テクスチャの名前
	};
}
