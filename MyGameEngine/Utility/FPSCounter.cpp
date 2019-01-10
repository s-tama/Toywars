//
// FPSCounter.cpp
//



// ヘッダーファイルのインクルード ------------------------------------------------
#include "FPSCounter.h"



// usingディレクティブ -----------------------------------------------------------
using namespace MyLibrary;
using namespace Utility;



// 静的メンバ定数の定義 ----------------------------------------------------------
const float FPSCounter::FONT_SIZE = 1;



// メンバ関数の定義 --------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
FPSCounter::FPSCounter():
	m_frameCount(0),
	m_renderFrameCount(0)
{
}

/// <summary>
/// デストラクタ
/// </summary>
FPSCounter::~FPSCounter()
{
}

/// <summary>
/// 更新処理
/// </summary>
void FPSCounter::Update()
{
	// 前回の計測時間
	static DWORD prevTime = timeGetTime();	
	// 現在の計測時間
	DWORD nowTime = timeGetTime();

	// カウントを進める
	m_frameCount++;

	// 経過時間が1秒を超えたらリセット
	if (nowTime - prevTime > 1000)
	{
		prevTime = nowTime;
		m_renderFrameCount = m_frameCount;
		m_frameCount = 0;
	}
}
