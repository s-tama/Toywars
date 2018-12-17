//
// Collision.h
//
#pragma once


// ヘッダーファイルのインクルード ----------------------------------------------------
#include "../Utility/Flag.h"


// クラスの宣言 ----------------------------------------------------------------------
namespace MyLibrary
{
	class SphereCollider;
	class BoxCollider;
}


// クラスの定義 ----------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// 当たり判定クラス
	/// </summary>
	class Collision
	{
	public:

		// コンストラクタ
		Collision();

		// 球と球の当たり判定
		static bool Sphere2Sphere(SphereCollider* sphere1, SphereCollider* sphere2);
		// ボックスとボックスの当たり判定
		static bool Box2Box(BoxCollider* box1, BoxCollider* box2);
	};
}
