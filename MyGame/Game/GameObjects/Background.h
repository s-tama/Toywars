//
// Background.h
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
	class Background : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Background();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// スプライト情報
		MyLibrary::Sprite* GetSprite() { return m_pSprite; }


	private:

		MyLibrary::Sprite* m_pSprite;
	};
}
