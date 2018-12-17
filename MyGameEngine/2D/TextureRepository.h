//
// TextureRepository.h
//
#pragma once


// ヘッダーファイルのインクルード  --------------------------------------------------------
#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include <memory>
#include <list>
#include <string>

#include "Texture.h"


// クラスの定義 --------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// テクスチャ貯蔵庫クラス
	/// </summary>
	class TextureRepository
	{
	private:

		// コンストラクタ
		TextureRepository();


	public:

		// デストラクタ
		~TextureRepository();

		// クラスのインスタンスを取得する
		static TextureRepository* GetInstance();

		// 貯蔵庫に追加する
		void AddRepository(Texture*);

		// テクスチャ情報を取得する
		Texture* GetTexture(std::wstring);

		// 全テクスチャを開放する
		void ReleaseTexture();


	private:

		// インスタンス
		static std::unique_ptr<TextureRepository> m_pInstance;

		// テクスチャ配列
		std::list<Texture*> m_pTextures;
	};
}
