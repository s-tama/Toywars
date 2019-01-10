//
// BulletFactory.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------
#include <vector>
#include "../GameObjects/Bullet.h"
#include "MyLibrary.h"


// クラスの宣言 ------------------------------------------------------------------
namespace MyGame
{
}


// クラスの定義 ------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 弾生成工場クラス
	/// </summary>
	class BulletFactory
	{
	public:

		// 弾の最大生成数
		static const int NUM_BULLETS = 10;


	public:

		// コンストラクタ
		BulletFactory();

		// 初期化処理
		void Initialize();

		// 作成処理
		Bullet* Create(DirectX::SimpleMath::Vector3 position);

		// 弾の配列を取得
		std::vector<Bullet*> GetBullets();

		// 弾の最大生成数を取得
		const int GetNumBullets();


	private:

		std::vector<Bullet*> m_pBullets;		// 弾の配列
	};
}
