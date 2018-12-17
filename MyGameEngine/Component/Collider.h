//
// Collider.h
//
#pragma once

#include "Component.h"

namespace MyLibrary
{
	/// <summary>
	/// コライダークラス
	/// </summary>
	class Collider : public Component
	{
	public:

		// コンストラクタ
		Collider();

		// 仮想デストラクタ
		virtual ~Collider();
	};
}
