#include<windows.h>
#include<d3d12.h>
#include<dxgi1_6.h>
#include<cassert>
#include<vector>
#include<string>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi1_6.lib")

// �E�B���h�E�v���V�[�W��
LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
	switch (msg)
	{
		//�E�B���h�E���j�����ꂽ
	case WM_DESTROY:
		//OS�ɑ΂��āA�A�v���̏I����`����
		PostQuitMessage(0);
		return 0;
	}

	//�W���̃��b�Z�[�W�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	OutputDebugStringA("Hello,DirectX!!\n");
	//�E�B���h�E�T�C�Y
	const int window_width = 1280; //��
	const int window_height = 720; //�c

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;     //�E�B���h�E�v���V�[�W����ݒ�
	w.lpszClassName = L"DirectXGame";		 //�E�B���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);	 //�E�B���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW); //�J�[�\���w��

	//�E�B���h�E�N���X��OS�ɓo�^����
	RegisterClassEx(&w);
	//�E�B���h�E�T�C�Y{ X���W Y���W ���� ���� }
	RECT wrc = { 0,0,window_width,window_height };
	//�����ŃT�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName,//�N���X��)
		L"DirectXGame",         //�^�C�g���o�[�̕\��
		WS_OVERLAPPEDWINDOW,    //�W���I�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,          //�\��X���W(OS�ɔC����)
		CW_USEDEFAULT,          //�\��Y���W(OS�ɔC����)
		wrc.right - wrc.left,   //�E�B���h�E����
		wrc.bottom - wrc.top,   //�E�B���h�E����
		nullptr,				//�e�E�B���h�E�n���h��
		nullptr,				//���j���[�n���h��
		w.hInstance,			//�Ăяo���A�v���P�[�V�����n���h��
		nullptr);				//�I�v�V����

	//�E�B���h�E��\����Ԃɂ���
	ShowWindow(hwnd, SW_SHOW);

	MSG msg{}; //���b�Z�[�W	

	//DirectX �����������@��������

	HRESULT result;
	ID3D12Device* device = nullptr;
	IDXGIFactory7* dxgiFactory = nullptr;
	IDXGISwapChain4* swapChain = nullptr;
	ID3D12CommandAllocator* cmdAllocator = nullptr;
	ID3D12GraphicsCommandList* CommandList = nullptr;
	ID3D12CommandQueue* CommandQueue = nullptr;
	ID3D12DescriptorHeap* rtvHeap = nullptr;

	//DirectX �����������@�����܂�

		//�Q�[�����[�v
		while (true)
		{
			//���b�Z�[�W������H
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);  //�L�[���̓��b�Z�[�W�̏���
				DispatchMessage(&msg);   //�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
			}

			//�~�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
			if (msg.message == WM_QUIT)
			{
				break;
			}

			//DirectX���t���[�������@��������

			//DirectX���t���[�������@�����܂�
		}

	//�E�B���h�E�N���X��o�^����
	UnregisterClass(w.lpszClassName, w.hInstance);

	return 0;
}
