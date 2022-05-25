// sheji2View.h : interface of the CSheji2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHEJI2VIEW_H__F01FD347_A169_4414_873D_03FA8EF5EA4D__INCLUDED_)
#define AFX_SHEJI2VIEW_H__F01FD347_A169_4414_873D_03FA8EF5EA4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSheji2View : public CView
{
protected: // create from serialization only
	CSheji2View();
	DECLARE_DYNCREATE(CSheji2View)

// Attributes
public:
	CSheji2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheji2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSheji2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSheji2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sheji2View.cpp
inline CSheji2Doc* CSheji2View::GetDocument()
   { return (CSheji2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEJI2VIEW_H__F01FD347_A169_4414_873D_03FA8EF5EA4D__INCLUDED_)
