//
// PlayerMoving.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------
#include "PlayerState.h"


// クラスの定義 ----------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 「移動」状態クラス
	/// </summary>
	class PlayerMoving : public PlayerState
	{
	private:

		// コンストラクタ
		PlayerMoving();


	public:

		// クラスのインスタンスを取得
		static PlayerMoving* GetInstance();

		// 初期化処理
		void Initialize(Player* pPlayer) override;

		// 実行
		void Execute(float elapsedTime) override;


	private:

		// 移動関数
		void MoveForward();
		void MoveBack();
		void RotationRight();
		void RotationLeft();
		void LimitMove(DirectX::SimpleMath::Vector3& velocity);


	private:

		// インスタンス
		static std::unique_ptr<PlayerMoving> m_pInstance;

		// 経過時間
		float m_elapsedTime;

		// ロボットのネジオブジェクトへのポインタ
		MyLibrary::GameObject* m_pScrew;
	};
}
