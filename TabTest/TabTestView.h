
// TabTestView.h: CTabTestView 类的接口
//

#pragma once


class CTabTestView : public CView
{
protected: // 仅从序列化创建
	CTabTestView() noexcept;
	DECLARE_DYNCREATE(CTabTestView)

// 特性
public:
	CTabTestDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTabTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOptions();

protected:
	int m_nWidth;
	int m_nHeight;
	int m_nUnits;
};

#ifndef _DEBUG  // TabTestView.cpp 中的调试版本
inline CTabTestDoc* CTabTestView::GetDocument() const
   { return reinterpret_cast<CTabTestDoc*>(m_pDocument); }
#endif

