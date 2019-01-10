//
// AI.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "AI.h"



// usingディレクティブ ---------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pEnemy">敵オブジェクトへのポインタ</param>
AI::AI(Enemy* pEnemy):
	m_pEnemy(pEnemy)
{
}

/// <summary>
/// 仮想デストラクタ
/// </summary>
AI::~AI()
{
}

/// <summary>
/// 戦略を変更する
/// </summary>
/// <param name="pNextStrategy">次の戦略</param>
void AI::ChangeStrategy(EnemyStrategy* pNextStrategy)
{
	delete m_pCurrentStrategy;
	m_pCurrentStrategy = nullptr;
	m_pCurrentStrategy = pNextStrategy;
}
