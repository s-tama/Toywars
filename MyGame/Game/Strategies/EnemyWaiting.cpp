//
// EnemyWaiting.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "EnemyWaiting.h"

#include "EnemyAttack.h"



// usingディレクティブ --------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyWaiting::EnemyWaiting(AI* pAI):
	EnemyStrategy(pAI)
{
}

/// <summary>
/// 実行
/// </summary>
void EnemyWaiting::Execute(float elapsedTime)
{
	return;
}
