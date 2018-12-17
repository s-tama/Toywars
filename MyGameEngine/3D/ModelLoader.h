//
// ModelLoader.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <memory>
#include <string>
#include <d3d11_1.h>

#include "Model3D.h"


// クラスの定義 ------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// モデル読み込みクラス
	/// </summary>
	class ModelLoader
	{
	private:

		static const std::wstring RESOURCE_DIRECTORY;	// リソースのディレクトリ
		static const std::wstring RESOURCE_FILENAME;	// リソースの拡張子


	public:

		// テクスチャデータを読み込む
		Model3D* LoadModel(const wchar_t*);
	};
}
