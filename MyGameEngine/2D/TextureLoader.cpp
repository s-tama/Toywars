//
// TextureLoader.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <WICTextureLoader.h>

#include "TextureLoader.h"
#include "../Common/DeviceResources.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ定数の定義 ----------------------------------------------------------------------
// リソースのディレクトリパス
const std::wstring TextureLoader::RESOURCE_DIRECTORY = L"Resources/Textures/";
// リソースのファイル拡張子
const std::wstring TextureLoader::RESOURCE_FILENAME = L".png";



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// テクスチャデータを読み込む
/// </summary>
/// <param name="textureName">テクスチャの名前</param>
/// <returns>指定されたテクスチャデータ</returns>
Texture* TextureLoader::LoadTexture(const wchar_t* pFileName)
{
	// デバイス
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();

	// テクスチャハンドル
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> pShaderResourceView;
	// リソース
	Microsoft::WRL::ComPtr<ID3D11Resource> pResource;
	// テクスチャ2D
	Microsoft::WRL::ComPtr<ID3D11Texture2D> pTexture2D;

	// ファイルを読み込む
	std::wstring fullpath = RESOURCE_DIRECTORY + pFileName + RESOURCE_FILENAME;
	CreateWICTextureFromFile(pDevice, fullpath.c_str(), pResource.GetAddressOf(), pShaderResourceView.GetAddressOf());

	// リソースをテクスチャとして解釈
	pResource.As(&pTexture2D);
	// テクスチャ情報を取得
	D3D11_TEXTURE2D_DESC desk;
	pTexture2D->GetDesc(&desk);

	// 読み込まれた情報をもとにテクスチャを作成
	Texture* pTexture = new Texture;
	pTexture->pHandle = pShaderResourceView;
	pTexture->desk = desk;
	pTexture->name = pFileName;

	// 作成したテクスチャ情報を返す
	return pTexture;
}
