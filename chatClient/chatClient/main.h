#pragma once

class SceneManager;

#define szWindowClass	TEXT("Chat")
#define szTitle			TEXT("Chat Client")

LRESULT CALLBACK WndProc(HWND hWnd	, UINT message	, WPARAM wParam	, LPARAM lParam);
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChannelWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LobbyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


void Render();


HDC m_HDC;
HDC m_memoryDC;
HINSTANCE m_hInstance;
SceneManager* m_pSceneManager;


