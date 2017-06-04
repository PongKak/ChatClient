#pragma once
#include "ClientScene.h"

class SceneChannel :public ClientScene
{
public:
	SceneChannel(HWND, HDC,HINSTANCE);
	~SceneChannel();

	virtual void DrawScene();
	
	void Init() override;
	int Update() override;



	CurrentScene m_CurrentScene;

	HWND m_EditAMOLANG;


	HWND m_hWnd;
	HINSTANCE m_hInstance;
	HDC m_memoryDC;

	HWND m_ChannelList;

};

