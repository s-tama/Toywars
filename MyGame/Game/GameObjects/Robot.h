//
// Robot.h
//
#pragma once


// ヘッダーファイルのインクルード ---------------------------------------
#include "MyLibrary.h"


// クラスの定義 ---------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// 障害物クラス
	/// </summary>
	class Robot : public MyLibrary::GameObject
	{
	public:

		// コンストラクタ
		Robot();

		// 初期化処理
		void Start() override;
		// 初期化処理
		void Initialize() override;
		// 更新処理
		void Update(float elapsedTime) override;


	private:

		std::vector<MyLibrary::Obj3D*> m_pParts;	// パーツへのポインタ配列
	};
}


