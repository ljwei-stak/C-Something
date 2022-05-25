// sheji2Doc.h : interface of the CSheji2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHEJI2DOC_H__FD244057_B040_45A0_A9AB_AFD970B2FF87__INCLUDED_)
#define AFX_SHEJI2DOC_H__FD244057_B040_45A0_A9AB_AFD970B2FF87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSheji2Doc : public CDocument
{
protected: // create from serialization only
	CSheji2Doc();
	DECLARE_DYNCREATE(CSheji2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheji2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSheji2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSheji2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEJI2DOC_H__FD244057_B040_45A0_A9AB_AFD970B2FF87__INCLUDED_)
