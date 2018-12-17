//
// Obj3D
//
#pragma once


// ヘッダーファイルのインクルード -------------------------------------------------
#include <Effects.h>

#include "../GameObject/GameObject.h"
#include "Model3D.h"
#include "../Utility/Flag.h"


// クラスの宣言 -------------------------------------------------------------------
namespace MyLibrary
{
	class Camera;
}


// クラスの定義 -------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// 3Dオブジェクトクラス
	/// </summary>
	class Obj3D : public GameObject
	{
	private:

		// フラグ定数
		const UCHAR LIGHT = 1 << 7;


	public:

		// コンストラクタ
		Obj3D();

		// モデル情報の設定
		void SetModel(Model3D* pModel);

		// 初期化処理
		void Initialize()				override;
		// 更新処理
		void Update(float elapsedTime)	override;
		// 描画処理
		void Draw()						override;

		// ライトの設定
		void SetLight(bool state);


	private:

		// モデル3Dへのポインタ
		Model3D* m_pModel;

		// フラグ
		Utility::Flag m_flag;

		// カメラへのポインタ
		Camera* m_pCamera;
	};
}
