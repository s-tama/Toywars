//
// ButtonManager.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class SelectButton;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// ボタンマネージャークラス
	/// </summary>
	class ButtonManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		ButtonManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:

		// 選択ボタン配列
		std::vector<SelectButton*> m_pSelectButtonList;

		// カウント
		int m_count;

		// 選択番号
		SelectButton* m_pSelectPointer;
		// 現在の番号
		int m_currentIndex;
	};
}
