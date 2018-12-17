//
// SelectButton.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 選択ボタンクラス
	/// </summary>
	class SelectButton : public MyLibrary::GameObject
	{
	public:

		const int IN_SPEED  = 2;		// 画面に入ってくるときのスピード
		const int OUT_SPEED = 3;		// 画面から出ていくときのスピード

		const UCHAR IS_ON		= 1 << 7;	// 押されたかのフラグ
		const UCHAR IS_IN		= 1 << 6;	// 画面インフラグ
		const UCHAR IS_OUT		= 1 << 5;	// 画面アウトフラグ
		const UCHAR IS_SELECT	= 1 << 4;	// 選択されているかのフラグ


	public:

		// コンストラクタ
		SelectButton();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// テキスト用スプライトの取得
		MyLibrary::Sprite* GetText() { return m_pText; }

		// フラグへの参照
		MyLibrary::Utility::Flag& Flag() { return m_flag; }


	private:

		// スプライト
		MyLibrary::Sprite* m_pText;

		// フラグ
		MyLibrary::Utility::Flag m_flag;

		// 選択フレーム
		MyLibrary::Sprite* m_pSelect;

		// カウント
		float m_count;
	};
}
