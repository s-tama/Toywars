//
// ModelRepository.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------------
#include "ModelRepository.h"



// usingディレクティブ -----------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;



// 静的メンバ変数の定義 ----------------------------------------------------------------
std::unique_ptr<ModelRepository> ModelRepository::m_pInstance;



// メンバ関数の定義 --------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
ModelRepository::ModelRepository()
{
}

/// <summary>
/// デストラクタ
/// </summary>
ModelRepository::~ModelRepository()
{
	// テクスチャを開放する
	ReleaseModel();
}

/// <summary>
/// クラスのインスタンスを取得
/// </summary>
/// <returns>インスタンス</returns>
ModelRepository* ModelRepository::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new ModelRepository);
	return m_pInstance.get();
}

/// <summary>
/// テクスチャを貯蔵庫に追加
/// </summary>
/// <param name="pModel">追加するテクスチャ</param>
void ModelRepository::AddRepository(Model3D* pModel)
{
	for (auto Models : m_pModels)
	{
		if (Models->name == pModel->name)
		{
			// エラー表示
			std::wstring name = L"モデル名: " + pModel->name;
			MessageBox(0, L"モデルはすでに登録されています。", name.c_str(), MB_OK);
			return;
		}
	}

	m_pModels.push_back(pModel);
}

/// <summary>
/// モデル情報を取得する
/// </summary>
/// <param name="name">モデルの名前</param>
/// <returns>名前が一致したらモデル情報を返す</returns>
Model3D* ModelRepository::GetModel(std::wstring name)
{
	for (auto Models : m_pModels)
	{
		if (Models->name == name)
		{
			return Models;
		}
	}

	// エラー表示
	std::wstring display = L"モデル名: " + name;
	MessageBox(0, L"モデルが存在しません。", display.c_str(), MB_OK);
	return nullptr;
}

/// <summary>
/// 全モデルを開放する
/// </summary>
void ModelRepository::ReleaseModel()
{
	for (auto& Models : m_pModels)
	{
		delete Models;
		Models = nullptr;
	}
}
