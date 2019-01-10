//
// EffectFactory.h
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyGame
{
	class EffectBase;
	class BreakEffect;
	class PoppingEffect;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// エフェクト生成工場クラス
	/// </summary>
	class EffectFactory : public MyLibrary::GameObject
	{
	private:

		static const int NUM_EFFECTS = 10;


	public:

		/// <summary>
		/// エフェクトID
		/// </summary>
		enum EffectID
		{
			EXPLOSION,	// 爆発
			POPPING,	// はじける
		};


	private:

		/// <summary>
		/// エフェクト配列構造体
		/// </summary>
		struct Effects
		{
			std::vector<EffectBase*> pExplosion;	// 爆発
			std::vector<EffectBase*> pPopping;		// はじける
		};


	public:

		// コンストラクタ
		EffectFactory();

		// 初期化処理
		void Initialize() override;
		// 作成処理
		EffectBase* Create(EffectID effectID);


	private:

		Effects m_effects;	// エフェクト配列
	};
}
