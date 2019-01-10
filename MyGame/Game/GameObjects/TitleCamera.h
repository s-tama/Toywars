//
// TitleCamera.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ------------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// メインカメラクラス
	/// </summary>
	class TitleCamera : public MyLibrary::Camera
	{
	public:

		// コンストラクタ
		TitleCamera();

		// 開始処理
		void Start() override;
		// 初期化処理
		void Initialize() override;

		// 更新処理
		void Update(float elapsedTime) override;


	private:
	};
}

