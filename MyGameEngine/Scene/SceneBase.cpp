//
// Scene.cpp
//



// ヘッダーファイルのインクルード ---------------------------------------------------------------
#include "SceneBase.h"

#include "../Math/Math.h"



// usingディレクティブ --------------------------------------------------------------------------
using namespace MyLibrary;



// メンバ関数の定義 -----------------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="name">シーン名</param>
SceneBase::SceneBase():
	m_name("")
{
}

/// <summary>
/// デストラクタ
/// </summary>
SceneBase::~SceneBase()
{
}
