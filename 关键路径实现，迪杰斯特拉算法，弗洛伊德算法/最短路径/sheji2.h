// sheji2.h : main header file for the SHEJI2 application
//

#if !defined(AFX_SHEJI2_H__F61035EA_F0A9_4FF3_AAC3_5E35FACB334C__INCLUDED_)
#define AFX_SHEJI2_H__F61035EA_F0A9_4FF3_AAC3_5E35FACB334C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSheji2App:
// See sheji2.cpp for the implementation of this class
//

class CSheji2App : public CWinApp
{
public:
	CSheji2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheji2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSheji2App)
	afx_msg void OnAppAbout();
	afx_msg void Oninput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#define MVNum 50
#define Maxint 32767
#define FALSE 0
#define TRUE 1
typedef struct{
	char vexs[MVNum];
	int arcs[MVNum][MVNum];
}MGraph;




/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEJI2_H__F61035EA_F0A9_4FF3_AAC3_5E35FACB334C__INCLUDED_)
