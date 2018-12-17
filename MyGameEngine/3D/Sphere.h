//
// Sphere.h
//
#pragma once

#include <GeometricPrimitive.h>

#include "../GameObject/GameObject.h"

namespace MyLibrary
{
	/// <summary>
	/// 球クラス
	/// </summary>
	class Sphere
	{
	public:

		// コンストラクタ
		Sphere(ID3D11DeviceContext* pContext, float size = 1.0f, size_t tessellation = 2);

		// 描画
		void Draw(DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix projection);

		// 位置の設定
		void SetPosition(DirectX::SimpleMath::Vector3 positon);
		void SetPosition(float x, float y, float z);

		// 位置の取得
		DirectX::SimpleMath::Vector3 GetPosition();

		// クオータニオンの設定
		void SetRotation(DirectX::SimpleMath::Quaternion rotation);
		void SetRotation(float x, float y, float z, float w);

		// 回転の取得
		DirectX::SimpleMath::Quaternion GetRotation();

		// 色の設定
		void SetColor(DirectX::FXMVECTOR color);

		// サイズの設定
		void SetScale(float scale);

		// サイズの取得
		float GetScale();


	private:

		// デバイスコンテキスト
		ID3D11DeviceContext* m_pContext;

		// 球
		std::unique_ptr<DirectX::GeometricPrimitive> m_pSphere;

		// ワールド行列
		DirectX::SimpleMath::Matrix m_world;

		// クオータニオン
		DirectX::SimpleMath::Quaternion m_rotation;

		// 色
		DirectX::SimpleMath::Vector4 m_color;

		// 位置
		DirectX::SimpleMath::Vector3 m_position;

		// 速度
		DirectX::SimpleMath::Vector3 m_velocity;

		// サイズ
		float m_size;
	};
}
