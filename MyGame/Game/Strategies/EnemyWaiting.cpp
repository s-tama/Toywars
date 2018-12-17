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



// 静的メンバ変数の定義 -------------------------------------------------------
std::unique_ptr<EnemyWaiting> EnemyWaiting::m_pInstance = nullptr;



// メンバ関数の定義 -----------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
EnemyWaiting::EnemyWaiting()
{
}

/// <summary>
/// クラスのインスタンスを取得する
/// </summary>
/// <returns>インスタンス</returns>
EnemyWaiting* EnemyWaiting::GetInstance()
{
	if (m_pInstance == nullptr)
		m_pInstance.reset(new EnemyWaiting);
	return m_pInstance.get();
}

/// <summary>
/// 実行
/// </summary>
void EnemyWaiting::Execute(float elapsedTime)
{
	
}
