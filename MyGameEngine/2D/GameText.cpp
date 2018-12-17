#include "GameText.h"
using namespace DirectX;


// 静的メンバ変数の実体
std::unique_ptr<GameText> GameText::m_Instance;

GameText* GameText::GetInstance()
{
	if (!m_Instance)
	{
		m_Instance.reset(new GameText);
	}

	return m_Instance.get();
}

GameText::GameText()
{

}

GameText::~GameText()
{

}

void GameText::Initialize(ID3D11Device* d3dDevice, ID3D11DeviceContext* d3dContext)
{
	// スプライトバッチを作成
	spriteBatch = std::make_unique<SpriteBatch>(d3dContext);

	// フォントファイルの読み込み
	spriteFont = std::make_unique<SpriteFont>(d3dDevice, L"Resources/Fonts/msgothic.spritefont");
}

void GameText::Draw()
{
	spriteBatch->Begin();

	// 全ての文字列を描画する
	std::vector<GameText::Text>::iterator it;
	for (it = textArray.begin(); it != textArray.end(); it++)
	{
		spriteFont->DrawString(spriteBatch.get(), it->str.c_str(),it->pos, it->color, 0, XMFLOAT2(0,0), it->scale, DirectX::SpriteEffects::SpriteEffects_None, 0.0f);
	}

	spriteBatch->End();

	textArray.clear();
}

void GameText::AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...)
{
	GameText::Text text;
	// 表示位置
	text.pos = position;

	// 書式文字列を処理
	va_list args;

	va_start(args, format);
	// 出力用文字列の生成
	text.str.resize(_vscwprintf(format, args) + 1);

	// 出力用文字列の書き込み
	int length = _vsnwprintf_s(&text.str[0], text.str.size(), _TRUNCATE, format, args);

	va_end(args);

	// 文字列の配列に追加
	textArray.push_back(text);
}

void GameText::AddText(const DirectX::XMFLOAT2 & position, const DirectX::XMVECTOR & color , float scale, LPCWSTR format, ...)
{
	GameText::Text text;
	// 表示位置
	text.pos = position;

	// 色
	text.color = color;

	// サイズ
	text.scale = DirectX::XMFLOAT2(scale, scale);

	// 書式文字列を処理
	va_list args;

	va_start(args, format);
	// 出力用文字列の生成
	text.str.resize(_vscwprintf(format, args) + 1);

	// 出力用文字列の書き込み
	int length = _vsnwprintf_s(&text.str[0], text.str.size(), _TRUNCATE, format, args);

	va_end(args);

	// 文字列の配列に追加
	textArray.push_back(text);
}