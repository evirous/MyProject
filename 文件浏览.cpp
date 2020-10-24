// 文件浏览.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "文件浏览.h"
#include "afxdialogex.h"


// 文件浏览 对话框

IMPLEMENT_DYNAMIC(文件浏览, CDialogEx)

文件浏览::文件浏览(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_File, pParent)
{
	WorL = 0;
}

文件浏览::~文件浏览()
{
}

void 文件浏览::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_File1, m_file);
}


BEGIN_MESSAGE_MAP(文件浏览, CDialogEx)
	ON_BN_CLICKED(IDC_FileB1, &文件浏览::OnBnClickedFileb1)
	ON_BN_CLICKED(IDC_FileB2, &文件浏览::OnBnClickedFileb2)
	ON_BN_CLICKED(IDC_BUTTON1, &文件浏览::OnBnClickedButton1)
END_MESSAGE_MAP()


// 文件浏览 消息处理程序


void 文件浏览::OnBnClickedFileb1()//打开文件浏览框
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("所有文件(*.*)|*.*||"), NULL, NULL, FALSE);
	if (dlg.DoModal() == IDOK)//如果用户在文件对话框中点击了“确定”按钮
	{
		thefile = dlg.GetPathName();//获取文件路径到

		m_file.SetWindowText(thefile);//显示文件路径到编辑框

	}
}



void 文件浏览::OnBnClickedFileb2()
{
	// TODO: 在此添加控件通知处理程序代码
	WorL = 1;
	文件浏览::OnOK();
}


void 文件浏览::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	WorL = 2;
	文件浏览::OnOK();
}
