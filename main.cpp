#include<windows.h>
#include<d3d12.h>
#include<dxgi1_6.h>
#include<cassert>
#include<vector>
#include<string>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi1_6.lib")

// ウィンドウプロシージャ
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//メッセージに応じてゲーム固有の処理を行う
	switch (msg)
	{
		//ウィンドウが破棄された
	case WM_DESTROY:
		//OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}

	//標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	OutputDebugStringA("Hello,DirectX!!\n");
	//ウィンドウサイズ
	const int window_width = 1280; //横
	const int window_height = 720; //縦

	//ウィンドウクラスの設定
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;     //ウィンドウプロシージャを設定
	w.lpszClassName = L"DirectXGame";		 //ウィンドウクラス名
	w.hInstance = GetModuleHandle(nullptr);	 //ウィンドウハンドル
	w.hCursor = LoadCursor(NULL, IDC_ARROW); //カーソル指定

	//ウィンドウクラスをOSに登録する
	RegisterClassEx(&w);
	//ウィンドウサイズ{ X座標 Y座標 横幅 立幅 }
	RECT wrc = { 0,0,window_width,window_height };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウオブジェクトの生成
	HWND hwnd = CreateWindow(w.lpszClassName,//クラス名)
		L"DirectXGame",         //タイトルバーの表示
		WS_OVERLAPPEDWINDOW,    //標準的なウィンドウスタイル
		CW_USEDEFAULT,          //表示X座標(OSに任せる)
		CW_USEDEFAULT,          //表示Y座標(OSに任せる)
		wrc.right - wrc.left,   //ウィンドウ横幅
		wrc.bottom - wrc.top,   //ウィンドウ立幅
		nullptr,				//親ウィンドウハンドル
		nullptr,				//メニューハンドル
		w.hInstance,			//呼び出しアプリケーションハンドル
		nullptr);				//オプション

	//ウィンドウを表示状態にする
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; //メッセージ	

	//DirectX 初期化処理　ここから

	HRESULT result;
	ID3D12Device* device = nullptr;
	IDXGIFactory7* dxgiFactory = nullptr;
	IDXGISwapChain4* swapChain = nullptr;
	ID3D12CommandAllocator* cmdAllocator = nullptr;
	ID3D12GraphicsCommandList* CommandList = nullptr;
	ID3D12CommandQueue* CommandQueue = nullptr;
	ID3D12DescriptorHeap* rtvHeap = nullptr;

	//DirectX 初期化処理　ここまで

		//ゲームループ
		while (true)
		{
			//メッセージがある？
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);  //キー入力メッセージの処理
				DispatchMessage(&msg);   //プロシージャにメッセージを送る
			}

			//×ボタンで終了メッセージが来たらゲームループを抜ける
			if (msg.message == WM_QUIT)
			{
				break;
			}

			//DirectX毎フレーム処理　ここから

			//DirectX毎フレーム処理　ここまで
		}

	//ウィンドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);

	return 0;
}
