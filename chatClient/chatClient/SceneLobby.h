#pragma once
#include "ClientScene.h"
class SceneLobby :
	public ClientScene
{
public:
	SceneLobby(HWND,HDC,HINSTANCE);
	~SceneLobby();

	virtual void DrawScene();

	void Init() override;
	int Update() override;


	CurrentScene m_CurrentScene;

	HWND m_hWnd;
	HINSTANCE m_hInstance;
	HDC m_memoryDC;
};

