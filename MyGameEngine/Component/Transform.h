//
// Transform.h
//
#pragma once


// ヘッダーファイルのインクルード -----------------------------------------------
#include "Component.h"


// クラス宣言 -------------------------------------------------------------------
namespace MyLibrary
{
	class GameObject;
}


// クラスの定義 -----------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// 変換情報クラス
	/// </summary>
	class Transform : public Component
	{
	public:

		// コンストラクタ
		Transform();
		// デストラクタ
		~Transform();

		// 移動処理
		void Translate(DirectX::SimpleMath::Vector3 translate);
		void Translate(float x, float y, float z);
		void Reflection(DirectX::SimpleMath::Vector3 reflection);
		void Reflection(float x, float y, float z);
		void ReflectTranslate(DirectX::SimpleMath::Vector3 translate);
		// 回転処理
		void Rotate(DirectX::SimpleMath::Vector3 v, float dir);

		// ワールド行列情報
		void SetWorld(DirectX::SimpleMath::Matrix world) { m_world = world; }
		DirectX::SimpleMath::Matrix GetWorld() 
		{
			DirectX::SimpleMath::Matrix scale = DirectX::SimpleMath::Matrix::CreateScale(m_scale);
			DirectX::SimpleMath::Matrix rot = DirectX::SimpleMath::Matrix::CreateFromQuaternion(m_rotation);
			DirectX::SimpleMath::Matrix trans = DirectX::SimpleMath::Matrix::CreateTranslation(m_position);
			m_world = scale * rot * trans;
			return m_world;
		}

		// 座標情報
		void SetPosition(DirectX::SimpleMath::Vector3 position) { m_position = position; }
		void SetPosition(float x, float y, float z) { m_position = DirectX::SimpleMath::Vector3(x, y, z); }
		DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }

		// スケーリング情報
		void SetScale(DirectX::SimpleMath::Vector3 scale) { m_scale = scale; }
		void SetScale(float x, float y, float z) { m_scale = DirectX::SimpleMath::Vector3(x, y, z); }
		void SetScale(float scale){ m_scale = DirectX::SimpleMath::Vector3(scale, scale, scale); }
		DirectX::SimpleMath::Vector3 GetScale() { return m_scale; }

		// 回転情報
		void SetRotation(DirectX::SimpleMath::Quaternion rotation) { m_rotation = rotation; }
		void SetRotation(float x, float y, float z, float w) { m_rotation = DirectX::SimpleMath::Quaternion(x, y, z, w); }
		DirectX::SimpleMath::Quaternion GetRotation() { return m_rotation; }

		// 方向情報
		void SetDirection(float direction) { m_direction = direction; }
		float GetDirection() { return m_direction; }

		// 前方ベクトル
		DirectX::SimpleMath::Vector3 GetForward();
		// 右方向ベクトル
		DirectX::SimpleMath::Vector3 GetRight();
		// 上方ベクトル
		DirectX::SimpleMath::Vector3 GetUp();

		// 親オブジェクト情報
		void SetParent(GameObject* pParent) { m_pParent = pParent; }
		GameObject* GetParent() { return m_pParent; }


	private:

		// 座標
		DirectX::SimpleMath::Vector3 m_position;

		// スケール
		DirectX::SimpleMath::Vector3 m_scale;

		// 回転
		DirectX::SimpleMath::Quaternion m_rotation;

		// ワールド行列
		DirectX::SimpleMath::Matrix m_world;

		// 方向
		float m_direction;

		// 親オブジェクト
		GameObject* m_pParent;

		// 反射
		DirectX::SimpleMath::Vector3 m_reflection;
	};
}