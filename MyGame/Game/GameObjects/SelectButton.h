//
// SelectButton.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include <functional>

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

		const byte IS_ON			= 1 << 7;	// 押されたかのフラグ
		const byte IS_IN			= 1 << 6;	// 画面インフラグ
		const byte IS_OUT			= 1 << 5;	// 画面アウトフラグ
		const byte IS_SELECT		= 1 << 4;	// 選択されているかのフラグ
		const byte IS_SELECT_ABLE	= 1 << 3;	// 選択可能かのフラグ


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

		// 観測者の登録
		void AttachListener(std::function<void()> Listener);
		// ボタンが押されたことを観測者に通知
		void OnClick();


	private:

		// イベント通知を受け取る観測者(空のラムダ式)
		std::function<void()> Listener = [] {};


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
