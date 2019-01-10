//
// BulletManager.cpp
//



// ヘッダーファイルのインクルード -------------------------------------------------------
#include "BulletManager.h"

#include "BulletFactory.h"
#include "Mediator.h"



// usingディレクティブ ------------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ---------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
BulletManager::BulletManager()
{
	SetTag("BulletManager");
}

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="pNodeManager">ノードマネージャーへのポインタ</param>
void BulletManager::Initialize()
{
	// 弾工場
	BulletFactory bulletFactory;
	// 弾工場を初期化する
	bulletFactory.Initialize();

	// 弾工場で生成された弾オブジェクトを配列に格納
	for (int i = 0; i < BulletFactory::NUM_BULLETS; i++)
	{
		m_pBulletArray.push_back(bulletFactory.GetBullets()[i]);
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void BulletManager::Update(float elapsedTime)
{
	for (auto bullets : m_pBulletArray)
	{
		// 弾が「非アクティブ」状態
		if (bullets->IsActive() != false)
		{
			// 弾が活動範囲を超えた場合
			if ((Math::Abs(bullets->GetTransform()->GetPosition().x) > 50)
				|| (Math::Abs(bullets->GetTransform()->GetPosition().z) > 50))
			{
				bullets->GetFlag().On(bullets->IS_HIT_OBSTACLE);
			}
		}

		if (bullets->GetFlag().Check(bullets->IS_HIT_OBSTACLE))
		{
			// 弾を「非アクティブ」状態にする
			bullets->SetActive(false);
			// 弾の座標を初期化する
			bullets->GetTransform()->SetPosition(Vector3::Zero);
			// 弾の回転情報を初期化する
			bullets->GetTransform()->SetRotation(Quaternion::Identity);
			// 弾の所有者を「無し」に設定する
			bullets->SetOwner(nullptr);
			// ヒットフラグをオフにする
			bullets->GetFlag().Off(bullets->IS_HIT_OBSTACLE);
			// 反射フラグをオフにする
			bullets->GetFlag().Off(bullets->IS_REFLECT);
		}
	}
}

/// <summary>
/// 弾を取得する
/// </summary>
/// <param name="i">要素番号</param>
/// <returns></returns>
inline Bullet* BulletManager::GetBullet(int i) const
{
	return m_pBulletArray[i];
}

/// <summary>
/// 弾数を数える
/// </summary>
/// <returns></returns>
int BulletManager::BulletCount() const
{
	return m_pBulletArray.size();
}

/// <summary>
/// 弾の配列を取得する
/// </summary>
/// <returns></returns>
std::vector<Bullet*> BulletManager::GetBullets() const
{
	return m_pBulletArray;
}
