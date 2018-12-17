//
// Framework.cpp
//



// ヘッダーファイルのインクルード ----------------------------------------------------------------
#include "Framework.h"

#include "../2D/DebugText.h"
#include "../2D/GameText.h"
#include "../System/InputDevice.h"



// usingディレクティブ ---------------------------------------------------------------------------
using namespace MyLibrary;
using namespace DirectX;
using namespace DirectX::SimpleMath;



// 静的メンバ変数の定義 --------------------------------------------------------------------------



// メンバ関数の定義 ------------------------------------------------------------------------------
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="window"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Framework::Framework(HINSTANCE hInstance, int nCmdShow, int width, int height)
	: m_screenWidth(width), m_screenHeight(height), m_screenColor(Colors::DarkBlue), m_pAppName(L"だんご大家族")
{
	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, L"IDI_ICON");
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"Direct3D_Win32_Game1WindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, L"IDI_ICON");
	if (!RegisterClassEx(&wcex))
		return;

	// Create window
	int w, h;
	GetDefaultSize(w, h);

	RECT rc;
	rc.top = 0;
	rc.left = 0;
	rc.right = static_cast<long>(w);
	rc.bottom = static_cast<long>(h);

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindowEx(0, L"Direct3D_Win32_Game1WindowClass", m_pAppName, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance,
		nullptr);
	// TODO: Change to CreateWindowEx(WS_EX_TOPMOST, L"Direct3D_Win32_Game1WindowClass", L"Direct3D Win32 Game1", WS_POPUP,
	// to default to fullscreen.

	if (!m_hWnd)
		return;

	ShowWindow(m_hWnd, nCmdShow);
	// TODO: Change nCmdShow to SW_SHOWMAXIMIZED to default to fullscreen.

	SetWindowLongPtr(m_hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	GetClientRect(m_hWnd, &rc);


	// デバイスリソースの作成
	DeviceResources* pDeviceResources = DeviceResources::GetInstance();
	pDeviceResources->RegisterDeviceNotify(this);

	pDeviceResources->SetWindow(m_hWnd, w, h);

	pDeviceResources->CreateDeviceResources();
	CreateDeviceDependentResources();
	
	pDeviceResources->CreateWindowSizeDependentResources();
	CreateWindowSizeDependentResources();

	// フルスクリーンの設定をする
	//if (MessageBox(NULL, L"フルスクリーンにしますか?", L"スクリーンの設定", MB_YESNO) == IDYES)
	//{
	//	// Yes: フルスクリーンモードに設定
	//	pDeviceResources->GetSwapChain()->SetFullscreenState(true, NULL);
	//}
	//else
	//{
	//	// No: ウィンドウモードに設定
	//	pDeviceResources->GetSwapChain()->SetFullscreenState(false, NULL);
	//}
}

/// <summary>
/// ウィンドウプロシージャー
/// </summary>
/// <param name="hWnd"></param>
/// <param name="message"></param>
/// <param name="wParam"></param>
/// <param name="lParam"></param>
/// <returns></returns>
LRESULT Framework::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	// フレームワーク
	Framework* f = reinterpret_cast<Framework*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_GETMINMAXINFO:
	{
		auto info = reinterpret_cast<MINMAXINFO*>(lParam);
		info->ptMinTrackSize.x = 320;
		info->ptMinTrackSize.y = 200;
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_INPUT:
	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEWHEEL:
	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
	case WM_MOUSEHOVER:
		Mouse::ProcessMessage(message, wParam, lParam);
		break;

	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		Keyboard::ProcessMessage(message, wParam, lParam);
		break;

	case WM_SYSKEYDOWN:
		Keyboard::ProcessMessage(message, wParam, lParam);
		break;

	case WM_MENUCHAR:
		return MAKELRESULT(0, MNC_CLOSE);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

/// <summary>
/// Direct3D初期化処理
/// </summary>
void Framework::InitializeD3D()
{
	// ゲームの初期化処理
	Initialize();
}

/// <summary>
/// Direct3D
/// </summary>
void Framework::FinalizeD3D()
{
	// ゲームの終了処理
	Finalize();
}

/// <summary>
/// 
/// </summary>
void Framework::Tick()
{
	m_timer.Tick([&]()
	{
		// ゲームの更新
		Update(m_timer);
	});

	// Direct3D描画処理
	RenderD3D();
}

/// <summary>
/// デバイスロスト時に行う処理
/// </summary>
void Framework::OnDeviceLost()
{
}

/// <summary>
/// デバイス復活処理
/// </summary>
void Framework::OnDeviceRestored()
{
	CreateDeviceDependentResources();
	CreateWindowSizeDependentResources();
}

/// <summary>
/// 
/// </summary>
void MyLibrary::Framework::OnWindowMoved()
{
	auto r = DeviceResources::GetInstance()->GetOutputSize();
	DeviceResources::GetInstance()->WindowSizeChanged(r.right, r.bottom);
}

/// <summary>
/// ウィンドウサイズの変更
/// </summary>
/// <param name="width">ウィンドウ幅</param>
/// <param name="height">ウィンドウ高さ</param>
void Framework::OnWindowSizeChanged(int width, int height)
{
	auto r = DeviceResources::GetInstance()->GetOutputSize();
	DeviceResources::GetInstance()->WindowSizeChanged(r.right, r.bottom);
}

/// <summary>
/// ウィンドウサイズのデフォルトサイズを取得
/// </summary>
/// <param name="width">ウィンドウ幅</param>
/// <param name="height">ウィンドウ高さ</param>
void Framework::GetDefaultSize(int& width, int& height) const
{
	width = m_screenWidth;
	height = m_screenHeight;
}

/// <summary>
/// 描画
/// </summary>
void Framework::RenderD3D()
{
	// Don't try to render anything before the first Update.
	if (m_timer.GetFrameCount() == 0)
	{
		return;
	}

	Clear();

	DeviceResources::GetInstance()->PIXBeginEvent(L"Render");
	auto context = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// ////////////////////////////////////////////////////
	// ここから描画処理を記述する
	// ////////////////////////////////////////////////////

	// ゲームの描画処理
	Render();

	// デバッグテキストの描画
	DebugText::GetInstance()->Draw();
	GameText::GetInstance()->Draw();

	// ////////////////////////////////////////////////////
	// ここまで
	// ////////////////////////////////////////////////////

	DeviceResources::GetInstance()->PIXEndEvent();
	// Show the new frame.
	DeviceResources::GetInstance()->Present();
}

/// <summary>
/// 画面をクリア
/// </summary>
void Framework::Clear()
{
	DeviceResources::GetInstance()->PIXBeginEvent(L"Clear");

	// Clear the views.
	auto context = DeviceResources::GetInstance()->GetD3DDeviceContext();
	auto renderTarget = DeviceResources::GetInstance()->GetRenderTargetView();
	auto depthStencil = DeviceResources::GetInstance()->GetDepthStencilView();

	context->ClearRenderTargetView(renderTarget, m_screenColor);
	context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	context->OMSetRenderTargets(1, &renderTarget, depthStencil);

	// ビューぽートの設定
	D3D11_VIEWPORT viewport = DeviceResources::GetInstance()->GetScreenViewport();
	context->RSSetViewports(1, &viewport);

	DeviceResources::GetInstance()->PIXEndEvent();
}

/// <summary>
/// デバイスの作成処理
/// </summary>
void Framework::CreateDeviceDependentResources()
{
	// デバイス
	ID3D11Device* pDevice = DeviceResources::GetInstance()->GetD3DDevice();
	// デバイスコンテキスト
	ID3D11DeviceContext* pContext = DeviceResources::GetInstance()->GetD3DDeviceContext();

	// デバッグテキストの初期化
	DebugText::GetInstance()->Initialize(pDevice, pContext);
	GameText::GetInstance()->Initialize(pDevice, pContext);
}

/// <summary>
/// ウィンドウサイズの作成処理
/// </summary>
void Framework::CreateWindowSizeDependentResources()
{
	// ウインドウサイズからアスペクト比を算出する
	RECT size = DeviceResources::GetInstance()->GetOutputSize();
	float aspectRatio = float(size.right) / float(size.bottom);

	// 画角を設定
	float fovAngleY = XMConvertToRadians(45.0f);
}
