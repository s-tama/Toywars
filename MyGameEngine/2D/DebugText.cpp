//
// DebugText.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------------
#include "DebugText.h"
#include "../Common/DeviceResources.h"



// usingディレクティブ -------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の実体を定義 ------------------------------------------------------------
// インスタンス
std::unique_ptr<DebugText> DebugText::m_Instance;



// メンバ関数の定義 ----------------------------------------------------------------------
/// <summary>
/// クラスのインスタンスを取得
/// </summary>
/// <returns></returns>
DebugText * DebugText::GetInstance()
{
	if (!m_Instance)
	{
		m_Instance.reset(new DebugText);
	}

	return m_Instance.get();
}

/// <summary>
/// コンストラクタ
/// </summary>
DebugText::DebugText()
{
}

/// <summary>
/// デストラクタ
/// </summary>
DebugText::~DebugText()
{
}

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="d3dDevice"></param>
/// <param name="d3dContext"></param>
void DebugText::Initialize(ID3D11Device* d3dDevice, ID3D11DeviceContext* d3dContext)
{
	// スプライトバッチを作成
	spriteBatch = std::make_unique<SpriteBatch>(d3dContext);

	// フォントファイルの読み込み
	spriteFont = std::make_unique<SpriteFont>(d3dDevice, L"Resources/Fonts/myfile.spritefont");
}

/// <summary>
/// 描画処理
/// </summary>
void DebugText::Draw()
{
	spriteBatch->Begin();

	// 全ての文字列を描画する
	std::vector<DebugText::Text>::iterator it;
	for (it = textArray.begin(); it != textArray.end(); it++)
	{
		spriteFont->DrawString(spriteBatch.get(), it->str.c_str(), it->pos);
	}

	spriteBatch->End();

	textArray.clear();
}

/// <summary>
/// テキストを追加する
/// </summary>
/// <param name="position"></param>
/// <param name="format"></param>
/// <param name=""></param>
void DebugText::AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...)
{
	DebugText::Text text;
	// 表示位置
	text.pos = position;

	// 書式文字列を処理
	va_list args;

	va_start(args, format);
	// 出力用文字列の生成
	text.str.resize(_vscwprintf(format, args) + 1);    // +1 for '\0'
													   // 出力用文字列の書き込み
	int length = _vsnwprintf_s(&text.str[0], text.str.size(), _TRUNCATE, format, args);

	va_end(args);

	// 文字列の配列に追加
	textArray.push_back(text);
}
