//
// Scene.h
//
#pragma once

#include <string>

namespace MyLibrary
{
		class SceneManager;
		
		/// <summary>
		/// シーン基底クラス
		/// </summary>
		class SceneBase
		{
		public:

			// コンストラクタ
			SceneBase();

			// 仮想デストラクタ
			virtual ~SceneBase();

			// 初期化処理
			virtual void Initialize() = 0;

			// 更新処理
			virtual void Update(float elapsedTime) = 0;

			// 描画処理
			virtual void Render() = 0;

			// 終了処理
			virtual void Finalize() = 0;

			// 名前の情報
			std::string GetName() { return m_name; }
			void SetName(std::string name) { m_name = name; }


		protected:

			// 名前
			std::string m_name;
		};
}
