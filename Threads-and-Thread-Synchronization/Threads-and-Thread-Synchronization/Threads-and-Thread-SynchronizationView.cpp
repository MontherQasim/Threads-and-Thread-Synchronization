
// Threads-and-Thread-SynchronizationView.cpp : implementation of the CThreadsandThreadSynchronizationView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Threads-and-Thread-Synchronization.h"
#endif

#include "Threads-and-Thread-SynchronizationDoc.h"
#include "Threads-and-Thread-SynchronizationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CThreadsandThreadSynchronizationView

IMPLEMENT_DYNCREATE(CThreadsandThreadSynchronizationView, CView)

BEGIN_MESSAGE_MAP(CThreadsandThreadSynchronizationView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CThreadsandThreadSynchronizationView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CThreadsandThreadSynchronizationView construction/destruction

CThreadsandThreadSynchronizationView::CThreadsandThreadSynchronizationView() noexcept
{
	// TODO: add construction code here

}

CThreadsandThreadSynchronizationView::~CThreadsandThreadSynchronizationView()
{
}

BOOL CThreadsandThreadSynchronizationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CThreadsandThreadSynchronizationView drawing

void CThreadsandThreadSynchronizationView::OnDraw(CDC* /*pDC*/)
{
	CThreadsandThreadSynchronizationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CThreadsandThreadSynchronizationView printing


void CThreadsandThreadSynchronizationView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CThreadsandThreadSynchronizationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CThreadsandThreadSynchronizationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CThreadsandThreadSynchronizationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CThreadsandThreadSynchronizationView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CThreadsandThreadSynchronizationView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CThreadsandThreadSynchronizationView diagnostics

#ifdef _DEBUG
void CThreadsandThreadSynchronizationView::AssertValid() const
{
	CView::AssertValid();
}

void CThreadsandThreadSynchronizationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CThreadsandThreadSynchronizationDoc* CThreadsandThreadSynchronizationView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CThreadsandThreadSynchronizationDoc)));
	return (CThreadsandThreadSynchronizationDoc*)m_pDocument;
}
#endif //_DEBUG


// CThreadsandThreadSynchronizationView message handlers
