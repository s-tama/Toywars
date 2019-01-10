//
// EffectBase.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// 列挙型の定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 再生モード構造体
	/// </summary>
	enum PlayMode
	{
		ONE,			// 一度のみ
		LOOP,			// ループ
	};
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// エフェクト基底クラス
	/// </summary>
	class EffectBase : public MyLibrary::GameObject
	{
	public:

		const byte IS_PLAY = 1 << 7;	// 再生状態フラグ
		const byte IS_END = 1 << 6;		// 終了状態フラグ
		const byte IS_LOOP = 1 << 5;	// ループ状態フラグ


	public:

		// コンストラクタ
		EffectBase();
		// 仮想デストラクタ
		virtual ~EffectBase();

		// 開始処理
		void Start() override;

		// 再生
		void Play(PlayMode playMode);
		// 停止
		void Stop();

		// 再生中か
		bool IsPlaying();


	protected:

		MyLibrary::Sprite3D* m_pSprite;		// エフェクトに使用するスプライト

		MyLibrary::Utility::Flag m_flag;	// フラグ
	};
}
