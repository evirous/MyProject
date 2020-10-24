// 选择.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "选择.h"
#include "afxdialogex.h"
#include"Dict.h"


// 选择 对话框

IMPLEMENT_DYNAMIC(选择, CDialogEx)

选择::选择(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Choose, pParent)
{
	YN = 0;
}

选择::~选择()
{
}

void 选择::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(选择, CDialogEx)
	ON_EN_CHANGE(IDC_C1, &选择::OnEnChangeC1)
	ON_BN_CLICKED(IDCANCEL, &选择::OnClose)
	ON_BN_CLICKED(IDC_B1, &选择::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &选择::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &选择::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &选择::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &选择::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &选择::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &选择::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &选择::OnBnClickedB8)
	ON_BN_CLICKED(IDC_Next, &选择::OnBnClickedNext)
	ON_BN_CLICKED(IDC_Finish, &选择::OnBnClickedFinish)
END_MESSAGE_MAP()


// 选择 消息处理程序
const CString C1=_T("回答正确！"), C2=_T("回答错误，正确选项是：");
BOOL 选择::OnInitDialog() {
	YN = 0;
	SetDlgItemText(IDC_C1,Title);//为所有控件修改名称
	SetDlgItemText(IDC_B1, B[0]);
	SetDlgItemText(IDC_B2, B[1]);
	SetDlgItemText(IDC_B3, B[2]);
	SetDlgItemText(IDC_B4, B[3]);
	SetDlgItemText(IDC_B5, B[4]);
	SetDlgItemText(IDC_B6, B[5]);
	SetDlgItemText(IDC_B7, B[6]);
	SetDlgItemText(IDC_B8, B[7]);
	J = 0;
	return TRUE;
}
void 选择::OnClose() {
	Fini = 1;
	选择::OnOK();
}
void 选择::Just(int n) {//判断是否正确
	if (J == 0) {
		if (n == Right) { SetDlgItemText(IDC_C2, C1); YN = 1; }
		else { SetDlgItemText(IDC_C2, C2 + B[Right]); YN = -1; }
		J = 1;
	}
}
void 选择::OnEnChangeC1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void 选择::OnBnClickedB1()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(0);
}


void 选择::OnBnClickedB2()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(1);
}


void 选择::OnBnClickedB3()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(2);
}


void 选择::OnBnClickedB4()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(3);
}


void 选择::OnBnClickedB5()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(4);
}


void 选择::OnBnClickedB6()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(5);
}


void 选择::OnBnClickedB7()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(6);
}


void 选择::OnBnClickedB8()
{
	// TODO: 在此添加控件通知处理程序代码
	Just(7);
}


void 选择::OnBnClickedNext()
{
	// TODO: 在此添加控件通知处理程序代码
	Fini = 0;
	选择::OnOK();
}


void 选择::OnBnClickedFinish()
{
	// TODO: 在此添加控件通知处理程序代码
	Fini = 1;
	选择::OnOK();
}
