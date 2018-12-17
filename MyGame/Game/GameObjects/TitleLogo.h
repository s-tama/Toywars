//
// TitleLogo.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 背景画像クラス
	/// </summary>
	class TitleLogo : public MyLibrary::GameObject
	{
	public:

		const int IN_SPEED = 2;			// 画面に入ってくるときのスピード
		const int OUT_SPEED = 3;		// 画面から出ていくときのスピード

		const UCHAR IS_IN = 1 << 6;		// 画面インフラグ
		const UCHAR IS_OUT = 1 << 5;	// 画面アウトフラグ

	public:

		// コンストラクタ
		TitleLogo();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// フラグへの参照
		MyLibrary::Utility::Flag& Flag();


	private:

		// フラグ
		MyLibrary::Utility::Flag m_flag;
	};
}
