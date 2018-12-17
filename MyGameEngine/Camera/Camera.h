//
// Camera.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------------------
#include "../GameObject/GameObject.h"


// クラスの定義 ----------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// カメラクラス
	/// </summary>
	class Camera : public GameObject
	{
	public:

		// コンストラクタ
		Camera();
		// 仮想デストラクタ
		virtual ~Camera();

		// ビュー行列の取得
		virtual DirectX::SimpleMath::Matrix GetView();
		// 射影行列の取得
		virtual DirectX::SimpleMath::Matrix GetProjection();

		// 注視点を設定する
		virtual void LookAt(DirectX::SimpleMath::Vector3 lookAt);
		virtual void LookAt(float x, float y, float z);


	protected:
		
		DirectX::SimpleMath::Matrix m_view;			// ビュー行列
		DirectX::SimpleMath::Matrix m_projection;	// 射影行列
	};
}
