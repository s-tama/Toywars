//
// Model3D.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------------------
#include <windows.h>
#include <wrl/client.h>
#include <d3d11_1.h>
#include <string>
#include <Model.h>


// クラスの定義 ---------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// 3Dモデル構造体
	/// </summary>
	struct Model3D
	{
		std::unique_ptr<DirectX::Model> pHandle;	// モデルハンドル
		std::wstring name;							// モデルの名前
	};
}
