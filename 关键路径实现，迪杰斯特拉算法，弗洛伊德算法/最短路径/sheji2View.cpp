// sheji2View.cpp : implementation of the CSheji2View class
//

#include "stdafx.h"
#include "sheji2.h"

#include "sheji2Doc.h"
#include "sheji2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSheji2View

IMPLEMENT_DYNCREATE(CSheji2View, CView)

BEGIN_MESSAGE_MAP(CSheji2View, CView)
	//{{AFX_MSG_MAP(CSheji2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSheji2View construction/destruction

CSheji2View::CSheji2View()
{
	// TODO: add construction code here

}

CSheji2View::~CSheji2View()
{
}

BOOL CSheji2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSheji2View drawing

void CSheji2View::OnDraw(CDC* pDC)
{
	CSheji2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSheji2View printing

BOOL CSheji2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSheji2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSheji2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSheji2View diagnostics

#ifdef _DEBUG
void CSheji2View::AssertValid() const
{
	CView::AssertValid();
}

void CSheji2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSheji2Doc* CSheji2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSheji2Doc)));
	return (CSheji2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSheji2View message handlers
