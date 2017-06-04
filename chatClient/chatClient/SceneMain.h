#pragma once
#include "ClientScene.h"
class SceneMain :	public ClientScene
{
public:
	SceneMain(HWND,HDC,HINSTANCE);
	~SceneMain();

	virtual void DrawScene();
	void Init() override;
	int Update() override;

	CurrentScene m_CurrentScene;

private:
	HWND m_EditID;
	HWND m_EditPASSWORD;

	TCHAR m_ID[128];
	TCHAR m_PASSWORD[128];


	HWND m_hWnd;
	HINSTANCE m_hInstance;
	HDC m_memoryDC;
};

