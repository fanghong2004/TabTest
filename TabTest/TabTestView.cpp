
// TabTestView.cpp: CTabTestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TabTest.h"
#endif

#include "TabTestDoc.h"
#include "TabTestView.h"
#include "COptionsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabTestView

IMPLEMENT_DYNCREATE(CTabTestView, CView)

BEGIN_MESSAGE_MAP(CTabTestView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPTIONS, &CTabTestView::OnFileOptions)
END_MESSAGE_MAP()

// CTabTestView 构造/析构

CTabTestView::CTabTestView() noexcept
{
	// TODO: 在此处添加构造代码
	m_nWidth = 4;
	m_nHeight = 2;
	m_nUnits = 0;
}

CTabTestView::~CTabTestView()
{
}

BOOL CTabTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTabTestView 绘图

void CTabTestView::OnDraw(CDC* pDC)
{
	CTabTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBrush brush(RGB(255, 0, 255));
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	switch (m_nUnits)
	{
	case 0:
		pDC->SetMapMode(MM_LOENGLISH);
		pDC->Rectangle(0, 0, m_nWidth * 100, -m_nHeight * 100);
		break;
	case 1:
		pDC->SetMapMode(MM_LOMETRIC);
		pDC->Rectangle(0, 0, m_nWidth * 100, -m_nHeight * 100);
		break;
	case 2:
		pDC->SetMapMode(MM_TEXT);
		pDC->Rectangle(0, 0, m_nWidth, m_nHeight);
		break;
	}
	pDC->SelectObject(pOldBrush);
}


// CTabTestView 打印

BOOL CTabTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTabTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTabTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTabTestView 诊断

#ifdef _DEBUG
void CTabTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTabTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabTestDoc* CTabTestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabTestDoc)));
	return (CTabTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CTabTestView 消息处理程序


void CTabTestView::OnFileOptions()
{
	// TODO: 在此添加命令处理程序代码
	COptionsDialog dlg;
	dlg.DoModal();


}
