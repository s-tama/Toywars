//
// ModelRepository.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------------
#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include <memory>
#include <list>
#include <string>

#include "Model3D.h"


// クラスの定義 -------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// モデル貯蔵庫クラス
	/// </summary>
	class ModelRepository
	{
	private:

		// コンストラクタ
		ModelRepository();


	public:

		// デストラクタ
		~ModelRepository();

		// クラスのインスタンスを取得する
		static ModelRepository* GetInstance();

		// 貯蔵庫に追加する
		void AddRepository(Model3D*);

		// モデル情報を取得する
		Model3D* GetModel(std::wstring);

		// 全モデルを開放する
		void ReleaseModel();


	private:

		// インスタンス
		static std::unique_ptr<ModelRepository> m_pInstance;

		// モデル配列
		std::list<Model3D*> m_pModels;
	};
}
