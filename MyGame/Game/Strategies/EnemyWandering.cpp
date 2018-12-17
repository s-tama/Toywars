//
// EnemyWandering.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------
#include "EnemyWandering.h"

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
EnemyWandering::EnemyWandering(AI* pAI) :
	EnemyStrategy(pAI)
{
}

/// <summary>
/// 実行
/// </summary>
void EnemyWandering::Execute(float elapsedTime)
{
	return;
}
