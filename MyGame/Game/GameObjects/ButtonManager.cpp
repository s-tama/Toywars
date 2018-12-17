//
// ButtonManager.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------
#include "ButtonManager.h"

#include "SelectButton.h"



// usingディレクティブ ----------------------------------------------------------
using namespace MyLibrary;
using namespace MyGame;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// メンバ関数の定義 -------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
ButtonManager::ButtonManager():
	m_count(0),
	m_pSelectPointer(nullptr),
	m_currentIndex(-1)
{
}

/// <summary>
/// 初期化処理
/// </summary>
void ButtonManager::Initialize()
{
	// トレーニングボタン
	SelectButton* pTraining = new SelectButton;
	pTraining->GetText()->Rect() = RECT{ 0, 0, 300, 50 };
	pTraining->GetText()->AnchorPoint() = Vector2(0, 0);
	pTraining->SetTag("TrainingButton");
	GetNodeManager()->AddNode(pTraining);

	// VSボタン
	SelectButton* pVS = new SelectButton;
	pVS->GetText()->Rect() = RECT{ 0, 50, 300, 100 };;
	pVS->GetText()->AnchorPoint() = Vector2(0, 0);
	pVS->SetTag("VSButton");
	GetNodeManager()->AddNode(pVS);

	// サバイバルボタン
	SelectButton* pSurvival = new SelectButton;
	pSurvival->GetText()->Rect() = RECT{ 0, 100, 300, 150 };;
	pSurvival->GetText()->AnchorPoint() = Vector2(0, 0);
	pSurvival->SetTag("SurvivalButton");
	GetNodeManager()->AddNode(pSurvival);

	// ミニゲームボタン
	SelectButton* pMiniGame = new SelectButton;
	pMiniGame->GetText()->Rect() = RECT{ 0, 150, 300, 200 };;
	pMiniGame->GetText()->AnchorPoint() = Vector2(0, 0);
	pMiniGame->SetTag("MiniGameButton");
	GetNodeManager()->AddNode(pMiniGame);

	// リストに追加
	m_pSelectButtonList.push_back(pTraining);
	m_pSelectButtonList.push_back(pVS);
	m_pSelectButtonList.push_back(pSurvival);
	m_pSelectButtonList.push_back(pMiniGame);

	// 座標を設定する
	int count = 0;
	for (auto it = m_pSelectButtonList.begin(); it != m_pSelectButtonList.end(); it++)
	{
		(*it)->GetTransform()->SetPosition(-300, 140 + (static_cast<float>(count) * 80), 0);
		count++;
	}
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="elapsedTime">経過時間</param>
void ButtonManager::Update(float elapsedTime)
{
	// 選択ボタンを画面インする
	for (auto buttons : m_pSelectButtonList)
	{
		if (!(buttons->Flag().Check(buttons->IS_IN)))
		{
			if (m_count % 10 == 0)
			{
				if (!(buttons->Flag().Check(buttons->IS_OUT)))
				{
					buttons->Flag().On(buttons->IS_IN);
					break;
				}
			}
		}
	}

	// 選択ボタンを画面アウトさせる
	if (m_count > 240)
	{
		// 現在のプレイモード番号を0で初期化する
		if (m_currentIndex == -1)
		{
			m_currentIndex = 0;
			m_pSelectPointer = m_pSelectButtonList[m_currentIndex];
			m_pSelectPointer->Flag().On(m_pSelectPointer->IS_SELECT);
		}

		// スペースキーインプット
		const bool isSpace = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::Space));
		if (isSpace)
		{
			for (auto buttons : m_pSelectButtonList)
			{
				// 「画面イン」フラグをオフにする
				buttons->Flag().Off(buttons->IS_IN);

				// 「画面アウト」フラグをオンにする
				if (buttons == m_pSelectPointer)
				{
					buttons->Flag().On(buttons->IS_OUT);
				}
			}
		}
	}

	if (m_currentIndex != -1)
	{
		// プレイモードを選択する
		const bool isW = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::W));
		const bool isS = (System::InputDevice::GetInstance()->GetKeyTracker().IsKeyPressed(Keyboard::Keys::S));
		if (isS)
		{
			m_currentIndex++;
			m_currentIndex %= m_pSelectButtonList.size();
			m_pSelectPointer = m_pSelectButtonList[m_currentIndex];
			m_pSelectPointer->Flag().On(m_pSelectPointer->IS_SELECT);	
		}
		else if (isW)
		{
			m_currentIndex--;
			if (m_currentIndex < 0) m_currentIndex = m_pSelectButtonList.size() - 1;
			m_pSelectPointer = m_pSelectButtonList[m_currentIndex];
			m_pSelectPointer->Flag().On(m_pSelectPointer->IS_SELECT);
		}

		for (auto buttons : m_pSelectButtonList)
		{
			if (buttons != m_pSelectPointer)
			{
				buttons->Flag().Off(buttons->IS_SELECT);
			}
		}
	}

	m_count++;
	m_count %= 1000;
}
