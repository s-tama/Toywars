//
// Mark.cpp
//



// ヘッダーファイルのインクルード --------------------------------------------------
#include "Mark.h"

#include "EffectBase.h"
#include "EffectFactory.h"



// usingディレクティブ -------------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ----------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
Mark::Mark()
{
	SetTag("Mark");
}

/// <summary>
/// 初期化処理
/// </summary>
void Mark::Initialize()
{
	// モデルオブジェクトを作成
	Obj3D* pObj = new Obj3D;
	pObj->SetModel(ModelRepository::GetInstance()->GetModel(L"Mark"));
	pObj->SetLight(true);
	AddChild(pObj);

	// 変換
	m_pTransform->SetScale(0.6f);

	// ボックスコライダの追加
	AddComponent<BoxCollider>();
	GetComponent<BoxCollider>()->SetStatus(Vector3::Zero, Vector3(1, 3, 1));

	// エフェクトファクトリー
	GameObject* pEffectFactory = NodeManager::FindGameObjectWithTag("EffectFactory");
	m_pEffectFactory = dynamic_cast<MyGame::EffectFactory*>(pEffectFactory);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void Mark::Update(float elapsedTime)
{
}

/// <summary>
/// 当たり判定(当たっている間)
/// </summary>
/// <param name="pCollider">コライダ</param>
void Mark::OnCollisionStay(GameObject* pCollider)
{
	// 当たった相手が弾の場合
	if (pCollider->GetTag() == "Bullet")
	{
		EffectBase* pEffect = m_pEffectFactory->Create(EffectFactory::EffectID::EXPLOSION);
		pEffect->GetTransform()->SetPosition(
			m_pTransform->GetPosition().x,
			m_pTransform->GetPosition().y + 3,
			m_pTransform->GetPosition().z
		);
		Destroy(this);						// 自信を破棄する
	}
}
