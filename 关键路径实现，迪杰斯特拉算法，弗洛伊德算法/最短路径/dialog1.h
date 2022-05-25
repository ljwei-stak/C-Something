#if !defined(AFX_DIALOG1_H__20E4D4AC_15A3_4171_B010_2CB4BC9AD67B__INCLUDED_)
#define AFX_DIALOG1_H__20E4D4AC_15A3_4171_B010_2CB4BC9AD67B__INCLUDED_

#include "sheji2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dialog1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cdialog1 dialog

class Cdialog1 : public CDialog
{
// Construction
public:
	void CreateMGraph1(MGraph *G,int n);
	void Floyd(MGraph *G,int n);
	void Dijkstra(MGraph *G,int vl,int n);
	void CreateMGraph(MGraph *G,int n,int e);
	Cdialog1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cdialog1)
	enum { IDD = IDD_DIALOG1 };
	CListBox	m_fuluo;
	CListBox	m_dijie;
	int		m_n;
	int		m_e;
	int		m_i;
	int		m_j;
	int		m_w;
	int		m_v;
	int		m_vv;
	int		m_ww;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cdialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cdialog1)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG1_H__20E4D4AC_15A3_4171_B010_2CB4BC9AD67B__INCLUDED_)
