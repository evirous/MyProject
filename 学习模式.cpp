// 学习模式.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "学习模式.h"
#include "afxdialogex.h"
#include"本地词库.h"
#include"网络词库.h"
#include"Dict.h"

// 学习模式 对话框

IMPLEMENT_DYNAMIC(学习模式, CDialogEx)

学习模式::学习模式(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Study, pParent)
{

}

学习模式::~学习模式()
{
}

void 学习模式::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(学习模式, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &学习模式::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &学习模式::OnBnClickedButton2)
END_MESSAGE_MAP()


// 学习模式 消息处理程序


void 学习模式::OnBnClickedButton1()//打开本地词库
{
	// TODO: 在此添加控件通知处理程序代码
	本地词库 B;
	B.DoModal();
}


void 学习模式::OnBnClickedButton2()//打开网络词库
{
	// TODO: 在此添加控件通知处理程序代码
	网络词库 W;
	W.DoModal();
}
