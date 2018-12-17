/// <summary>
/// 文字列画面表示クラス
/// </summary>
#pragma once

#include <wrl/client.h>
#include <SpriteFont.h>
#include <SimpleMath.h>
#include <vector>

class	GameText
{
public:
	static GameText* GetInstance();
private:
	static std::unique_ptr<GameText> m_Instance;

public:
	// テキスト1個分のデータ
	struct Text
	{
		// 表示位置
		DirectX::XMFLOAT2 pos = {0,0};
		DirectX::XMVECTOR color = {1,1,1,1};
		DirectX::XMFLOAT2 scale = {1,1};
		// 表示文字列
		std::wstring	str;
	};

	// コンストラクタ
	GameText();
	// デストラクタ
	virtual ~GameText();
	// 初期化
	void Initialize(ID3D11Device*	d3dDevice, ID3D11DeviceContext* d3dContext);
	// 描画
	// ※必ずSpriteBatchのBegin()とEnd()の間で呼び出すこと。
	void Draw();
	// テキスト追加（フォーマット指定付き)
	void AddText(const DirectX::XMFLOAT2& position, LPCWSTR format, ...);
	void AddText(const DirectX::XMFLOAT2& position, const DirectX::XMVECTOR& color, float scale, LPCWSTR format, ...);


protected:
	// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch>	spriteBatch;
	// スプライトフォント
	std::unique_ptr<DirectX::SpriteFont>	spriteFont;
	// 文字列の配列
	std::vector<GameText::Text> textArray;
};
