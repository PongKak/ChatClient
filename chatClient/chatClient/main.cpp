#include "stdafx.h"
#include "SceneManager.h"
#include "SceneMain.h"
#include "SceneChannel.h"
#include "main.h"

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex))
		return 0;

	wcex.lpfnWndProc = (WNDPROC)MainWndProc;
	wcex.lpszClassName = TEXT("MainScene");
	if (!RegisterClassEx(&wcex))
		return 0;


	wcex.lpfnWndProc = (WNDPROC)ChannelWndProc;
	wcex.lpszClassName = TEXT("ChannelScene");
	if (!RegisterClassEx(&wcex))
		return 0;


	wcex.lpfnWndProc = (WNDPROC)LobbyWndProc;
	wcex.lpszClassName = TEXT("LobbyScene");
	if (!RegisterClassEx(&wcex))
		return 0;


	m_hInstance = hInstance;

	HWND	hWnd = CreateWindowEx(WS_EX_APPWINDOW
		, szWindowClass
		, szTitle
		, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, 800
		, 600
		, NULL
		, NULL
		, hInstance
		, NULL);

	if (!hWnd)
		return 0;

	ShowWindow(hWnd, nCmdShow);
	


	MSG			msg;

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			Render();
		}
	}

	return (int)msg.wParam;
}

// 메시지 처리 함수
LRESULT CALLBACK WndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch (message)
	{
		case WM_CREATE:
		{

			m_HDC = GetDC(hWnd);
			m_memoryDC = CreateCompatibleDC(m_HDC);
			m_pSceneManager = new SceneManager(hWnd,m_memoryDC,m_hInstance);
			break;

		}
		case WM_PAINT:
		{

			break;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
				case (UINT)menu::login::LOGIN:
				{
				}
			}

		}

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK MainWndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch (message)
	{
	case WM_CREATE:
	{
		break;

	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			case (UINT)menu::login::LOGIN:
			{
				m_pSceneManager->ChangeScene(CurrentScene::ChannelScene);
			}
		}

	}

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK ChannelWndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch (message)
	{
	case WM_CREATE:
	{
		break;

	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			case(UINT)menu::channel::LOGOUT:
			{
				m_pSceneManager->ChangeScene(CurrentScene::MainScene);
				break;
			}
			case(UINT)menu::channel::JOIN:
			{
				m_pSceneManager->ChangeScene(CurrentScene::LobbyScene);
				break;
			}
		}

	}

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK LobbyWndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch (message)
	{
	case WM_CREATE:
	{
		break;

	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			case(UINT)menu::lobby::LOGOUT:
			{
				m_pSceneManager->ChangeScene(CurrentScene::MainScene);
				break;
			}
			case(UINT)menu::lobby::CHANNELOUT:
			{
				m_pSceneManager->ChangeScene(CurrentScene::ChannelScene);
				break;
			}
		}

	}

	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}


void Render()
{
	m_pSceneManager->update();
	auto hr = BitBlt(m_HDC, 0, 0, 800, 600, m_memoryDC, 0, 0, SRCCOPY);

}

