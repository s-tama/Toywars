//
// TextureRepository.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------------
#include "TextureRepository.h" 



// usingディレクティブ -----------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;



// 静的メンバ変数の定義 ----------------------------------------------------------------
// インスタンス
std::unique_ptr<TextureRepository> TextureRepository::m_pInstance;



// メンバ関数の定義 --------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
TextureRepository::TextureRepository()
{
}

/// <summary>
/// デストラクタ
/// </summary>
TextureRepository::~TextureRepository()
{
	// 全テクスチャを開放する
	ReleaseTexture();
}

/// <summary>
/// クラスのインスタンスを取得
/// </summary>
/// <returns>インスタンス</returns>
TextureRepository* TextureRepository::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new TextureRepository);
	return m_pInstance.get();
}

/// <summary>
/// テクスチャを貯蔵庫に追加
/// </summary>
/// <param name="pTexture">追加するテクスチャ</param>
void TextureRepository::AddRepository(Texture* pTexture)
{
	for (auto textures : m_pTextures)
	{
		if (textures->name == pTexture->name)
		{
			// エラー表示
			std::wstring name = L"テクスチャ名: " + pTexture->name;
			MessageBox(0, L"テクスチャはすでに登録されています。", name.c_str(), MB_OK);
			return;
		}
	}

	m_pTextures.push_back(pTexture);
}

/// <summary>
/// テクスチャ情報を取得する
/// </summary>
/// <param name="name">テクスチャの名前</param>
/// <returns>名前が一致したらテクスチャ情報を返す</returns>
Texture* TextureRepository::GetTexture(std::wstring name)
{
	for (auto textures : m_pTextures)
	{
		if (textures->name == name)
		{
			return textures;
		}
	}
	return nullptr;
}

/// <summary>
/// 全テクスチャを開放する
/// </summary>
void TextureRepository::ReleaseTexture()
{
	for (auto& textures : m_pTextures)
	{
		delete textures;
		textures = nullptr;
	}
}
