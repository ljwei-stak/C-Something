// GameOfProject.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGameOfProjectApp:
// �йش����ʵ�֣������ GameOfProject.cpp
//

class CGameOfProjectApp : public CWinApp
{
public:
	CGameOfProjectApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGameOfProjectApp theApp;