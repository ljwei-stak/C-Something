// sheji2Doc.cpp : implementation of the CSheji2Doc class
//

#include "stdafx.h"
#include "sheji2.h"

#include "sheji2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSheji2Doc

IMPLEMENT_DYNCREATE(CSheji2Doc, CDocument)

BEGIN_MESSAGE_MAP(CSheji2Doc, CDocument)
	//{{AFX_MSG_MAP(CSheji2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSheji2Doc construction/destruction

CSheji2Doc::CSheji2Doc()
{
	// TODO: add one-time construction code here

}

CSheji2Doc::~CSheji2Doc()
{
}

BOOL CSheji2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSheji2Doc serialization

void CSheji2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSheji2Doc diagnostics

#ifdef _DEBUG
void CSheji2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSheji2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSheji2Doc commands
