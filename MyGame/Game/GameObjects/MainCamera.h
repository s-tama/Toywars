//
// MainCamera.h
//
#pragma once


// ヘッダーファイルのインクルード ------------------------------------------------------
#include "MyLibrary.h"


// クラスの定義 ------------------------------------------------------------------------
namespace MyGame
{
	/// <summary>
	/// メインカメラクラス
	/// </summary>
	class MainCamera : public MyLibrary::Camera
	{
	public:

		// フラグ定数
		const UCHAR NORMAL	= 1 << 7;		// 通常（普通に追従）
		const UCHAR LATE	= 1 << 6;		// 遅れて追従


	public:

		// コンストラクタ
		MainCamera();

		// 初期化処理
		void Initialize() override;
		// 更新処理
		void LateUpdate(float elapsedTime) override;


	private:

		MyLibrary::Transform* m_pTarget;			// ターゲットの変換情報へのポインタ

		MyLibrary::Utility::Flag m_flag;			// フラグ
	};
}
