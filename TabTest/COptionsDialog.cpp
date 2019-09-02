// COptionsDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "TabTest.h"
#include "COptionsDialog.h"
#include "afxdialogex.h"


// COptionsDialog 对话框

IMPLEMENT_DYNAMIC(COptionsDialog, CDialogEx)

COptionsDialog::COptionsDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPTIONS, pParent)
{

}

COptionsDialog::~COptionsDialog()
{
}

void COptionsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COptionsDialog, CDialogEx)
END_MESSAGE_MAP()


// COptionsDialog 消息处理程序
