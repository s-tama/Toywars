//
// Mediator.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------
#include "MyLibrary.h"


// クラス宣言 -------------------------------------------------------------------
namespace MyGame
{
	class BulletManager;
	class Obstacle;
	class EffectFactory;
}


// クラスの定義 -----------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// オブジェクト仲介役クラス
	/// </summary>
	class Mediator : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Mediator();

		// 初期化処理
		void Initialize() override;

		// プロパティ
		BulletManager* GetBulletManager() const;
		EffectFactory* GetEffectFactory() const;


	private:

		BulletManager* m_pBulletManager;			// バレットマネージャーへのポインタ
		MyGame::EffectFactory* m_pEffectFactory;	// エフェクトファクトリーへのポインタ
	};
}
