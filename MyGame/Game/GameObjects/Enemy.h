//
// Enemy.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ---------------------------------------------------------------------
namespace MyGame
{
	class EnemyState;
	class EnemyStrategy;
	class Mediator;
	class AI;
}


// クラスの定義 ---------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// プレイヤークラス
	/// </summary>
	class Enemy : public MyLibrary::GameObject
	{
	public:

		static const DirectX::SimpleMath::Vector3 APPEAR_POS[8];	// 初期出現地点


	public:

		static const float ADVANCE_SPEED;		// 前進速度
		static const float ROTATION_SPEED;		// 回転速度

		const UCHAR IS_HIT_OBSTACLE = 1 << 7;	// 障害物に当たっているかのフラグ


	public:

		// コンストラクタ
		Enemy();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// AIアルゴリズムを設定する
		void SetAI(AI* pAI) { m_pAI = pAI; }

		// メディエーターの情報
		void SetMediator(Mediator* pMediator) { m_pMediator = pMediator; }
		Mediator* GetMediator() { return m_pMediator; }

		// 当たっている間の処理
		void OnCollisionStay(GameObject* collider) override;


	private:

		// 作成処理
		void Create();


	private:

		AI* m_pAI;		// AIアルゴリズム
		Mediator* m_pMediator;							// メディエーターへのポインタ
	};
}

