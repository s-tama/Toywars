//
// Obj3D.cpp
//



// ヘッダーファイルのインクルード -----------------------------------------------
#include <Effects.h>

#include "Obj3D.h"
#include "../Common/DeviceResources.h"
#include "../Camera/Camera.h"
#include "../Node/NodeManager.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 ------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="view">ビュー行列</param>
Obj3D::Obj3D(): 
	m_pModel(nullptr),
	m_pCamera(nullptr)
{
}

/// <summary>
/// モデルの情報
/// </summary>
/// <param name="pModel"></param>
void Obj3D::SetModel(Model3D* pModel)
{
	m_pModel = pModel;
}

/// <summary>
/// 初期化処理
/// </summary>
void Obj3D::Initialize()
{
	GameObject* pCamera = NodeManager::FindGameObjectWithTag("MainCamera");
	m_pCamera = dynamic_cast<Camera*>(pCamera);

	// ライトの設定
	if (m_flag.Check(LIGHT) != false)
	{
		auto SetLight = [&](DirectX::IEffect* effect)
		{
			DirectX::IEffectLights* lights = dynamic_cast<DirectX::IEffectLights*>(effect);
			if (lights)
			{
				lights->SetAmbientLightColor(Vector3(1, 1, 1));    // アンビエント色を設定する
				lights->SetLightEnabled(0, true);	// １番のライトON
				lights->SetLightEnabled(1, false);	// ２番のライトOFF
				lights->SetLightEnabled(2, false);	// ３番のライトOFF
				lights->SetLightDiffuseColor(0, DirectX::Colors::White);	// ライトの色
				DirectX::SimpleMath::Vector3 light_dir(1, -1, -1);		// ライトの方向ベクトル
				light_dir.Normalize();		// ライトの方向ベクトルを正規化する
				lights->SetLightDirection(0, light_dir);	// １番のライトの方向を設定する
				lights->SetPerPixelLighting(true);
			}
		};
		m_pModel->pHandle->UpdateEffects(SetLight);
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime"></param>
void Obj3D::Update(float elapsedTime)
{
}

/// <summary>
/// 描画処理
/// </summary>
void Obj3D::Draw()
{
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();
	// コモンステート
	DirectX::CommonStates* pStates = DeviceResources::GetInstance()->GetCommonStates();
	// モデルを描画する
	if (m_pModel != nullptr)
	{
		Matrix world = GetTransform()->GetWorld();
		if (GetTransform()->GetParent() != nullptr)
		{
			world = GetTransform()->GetWorld() * GetTransform()->GetParent()->GetTransform()->GetWorld();
		}
		m_pModel->pHandle->Draw(pContext, *pStates, world, m_pCamera->GetView(), m_pCamera->GetProjection());
	}
}

/// <summary>
/// ライトの設定
/// </summary>
/// <param name="state"></param>
void Obj3D::SetLight(bool state)
{
	switch (state)
	{
	case true:  m_flag.On(LIGHT);  break;
	case false: m_flag.Off(LIGHT); break;
	}
}
