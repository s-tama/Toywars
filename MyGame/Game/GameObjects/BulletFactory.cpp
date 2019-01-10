//
// BulletFactory.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------------
#include "BulletFactory.h"



// usingディレクティブ ----------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
BulletFactory::BulletFactory():
	m_pBullets{ nullptr }
{
}

/// <summary>
/// 弾生成工場クラスを初期化する
/// </summary>
void BulletFactory::Initialize()
{	
	// 配列のサイズを設定する
	m_pBullets.resize(NUM_BULLETS);

	// 弾オブジェクトを生成して配列に格納する
	for (int i = 0; i < NUM_BULLETS; i++)
	{
		// 弾を生成
		m_pBullets[i] = new Bullet();
		// 弾を「使用不可」にする
		m_pBullets[i]->SetActive(false);
		// 弾を初期化する(ノードに追加する)
		NodeManager::AddNode(m_pBullets[i]);
	}
}

/// <summary>
/// 弾オブジェクトを生成する
/// </summary>
/// <param name="position">生成位置</param>
/// <returns>生成された弾オブジェクト</returns>
Bullet* BulletFactory::Create(Vector3 position)
{
	for (auto bullets : m_pBullets)
	{
		if (bullets->IsActive() != true)
		{
			// 弾を「使用中」に設定する
			bullets->SetActive(true);
			// 弾の座標を設定
			bullets->GetTransform()->SetPosition(position);
			// 生成した弾を返す
			return bullets;
		}
	}
	return nullptr;
}

/// <summary>
/// 弾の配列を取得
/// </summary>
/// <returns></returns>
std::vector<Bullet*> BulletFactory::GetBullets()
{
	return m_pBullets;
}

/// <summary>
/// 弾の最大生成数を取得する
/// </summary>
/// <returns>弾の最大数</returns>
const int BulletFactory::GetNumBullets()
{
	return NUM_BULLETS;
}
