//
// Bckground.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include "Background.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Background::Background():
	m_pSprite(nullptr)
{
	m_pSprite = new Sprite();
}

/// <summary>
/// 初期化処理
/// </summary>
void Background::Initialize()
{
	AddChild(m_pSprite);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Background::Update(float elapsedTime)
{
}
