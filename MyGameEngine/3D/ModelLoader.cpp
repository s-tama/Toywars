//
// ModelLoader.cpp
// 



// ヘッダーファイルのインクルード -------------------------------------------------------
#include <d3d11.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Effects.h>

#include "ModelLoader.h"
#include "../Common/DeviceResources.h"



// usingディレクティブ ------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 -----------------------------------------------------------------
// リソースのディレクトリパス
const std::wstring ModelLoader::RESOURCE_DIRECTORY = L"Resources/Models/";
// リソースのファイル拡張子
const std::wstring ModelLoader::RESOURCE_FILENAME = L".cmo";



// メンバ関数の定義 ---------------------------------------------------------------------
/// <summary>
/// モデルを読み込む
/// </summary>
/// <param name=""></param>
/// <returns></returns>
Model3D* ModelLoader::LoadModel(const wchar_t* pFileName)
{
	// デバイス
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// エフェクトファクトリー
	EffectFactory fx(pDevice);
	fx.SetDirectory(L"Resources/Models");

	// ファイルを読みこんでモデルを作成
	Model3D* pModel3D = new Model3D;
	std::wstring fullpath = RESOURCE_DIRECTORY + pFileName + RESOURCE_FILENAME;
	pModel3D->pHandle = Model::CreateFromCMO(pDevice, fullpath.c_str(), fx);
	pModel3D->name = pFileName;

	return pModel3D;
}
