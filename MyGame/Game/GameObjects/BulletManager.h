//
// BulletManager.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------
#include <vector>

#include "MyLibrary.h"


// クラス宣言 ----------------------------------------------------------------------
namespace MyGame
{
	class Bullet;
	class Mediator;
}


// クラスの定義 --------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 弾管理クラス
	/// </summary>
	class BulletManager : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		BulletManager();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// 弾の配列を取得する
		std::vector<Bullet*> GetBullets() const;
		// 弾を取得する
		inline Bullet* GetBullet(int i) const;
		// 弾数を取得する
		int BulletCount() const;


	private:

		std::vector<Bullet*> m_pBulletArray;			// 弾の配列
	};
}
