//
// Component.h
//
#pragma once


// ヘッダーファイルのインクルード --------------------------------------------------------
#include "../Node/Node.h"


// クラスの宣言 --------------------------------------------------------------------------
namespace MyLibrary
{
	class Transform;
}


// クラスの定義 --------------------------------------------------------------------------
namespace MyLibrary
{
	/// <summary>
	/// コンポーネントクラス
	/// </summary>
	class Component
	{
	public:

		// コンストラクタ
		Component();
		// 仮想デストラクタ
		virtual ~Component();

		// ゲームオブジェクトの取得
		GameObject* GetGameObject();
		// ゲームオブジェクトの設定
		void SetGameObject(GameObject* pGameObject);


	protected:

		GameObject* m_pGameObject;		// ゲームオブジェクトへのポインタ
		Transform* m_pTransform;		// トランスフォームへのポインタ
	};
}
