//
// Player.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------------------
#include "MyLibrary.h"


// クラスの宣言 ---------------------------------------------------------------------
namespace MyGame
{
	class PlayerState;
	class PlayerStrategy;
	class Mediator;
}


// クラスの定義 ---------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// プレイヤークラス
	/// </summary>
	class Player : public MyLibrary::GameObject
	{
	public:

		static const float ADVANCE_SPEED;		// 前進速度
		static const float ROTATION_SPEED;		// 回転速度

		const UCHAR IS_HIT_OBSTACLE = 1 << 7;	// 障害物に当たっているかのフラグ


	public:

		// コンストラクタ
		Player();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;

		// 状態を変更する
		void ChangeState(PlayerState* pNextState);
		// 戦略を変更する
		void ChangeStrategy(PlayerStrategy* pNextStrategy);

		// 速度ベクトルの情報
		void SetVelocity(DirectX::SimpleMath::Vector3 velocity) { m_velocity = velocity; }
		DirectX::SimpleMath::Vector3 GetVelocity() { return m_velocity; }

		// 当たっている間の処理
		void OnCollisionStay(GameObject* collider) override;

		// メディエーターの情報
		void SetMediator(Mediator* pMediator) { m_pMediator = pMediator; }
		Mediator* GetMediator() { return m_pMediator; }

		// フラグ情報
		MyLibrary::Utility::Flag& GetFlag() { return m_flag; }

		// 障害物情報
		std::vector<GameObject*> GetObstacles() { return m_pObstacles; }

		// 所持している弾数
		UINT& PossessBulletNum() { return m_possessBulletNum; }


	private:

		// 作成処理
		void Create();
		// 状態を初期化する
		void InitializeState();
		// 戦略を初期化する
		void InitializeStrategy();


	private:

		PlayerState* m_pCurrentState;					// 現在の状態
		PlayerStrategy* m_pCurrentStrategy;				// 現在の戦略
		Mediator* m_pMediator;							// メディエーターへのポインタ
		DirectX::SimpleMath::Vector3 m_velocity;		// 速度ベクトル
		MyLibrary::Utility::Flag m_flag;				// フラグ
		std::vector<GameObject*> m_pObstacles;			// 障害物の配列
		UINT m_possessBulletNum;						// 所持している弾の数
	};
}
