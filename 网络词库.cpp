// 网络词库.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "网络词库.h"
#include "afxdialogex.h"
#include"Dict.h"
#include"保存.h"
#include<wininet.h>


// 网络词库 对话框


IMPLEMENT_DYNAMIC(网络词库, CDialogEx)

网络词库::网络词库(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Web, pParent)
{

}

网络词库::~网络词库()
{
}

void 网络词库::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(网络词库, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &网络词库::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_Web1, &网络词库::OnEnChangeWeb1)
	ON_EN_CHANGE(IDC_Web2, &网络词库::OnEnChangeWeb2)
	ON_BN_CLICKED(IDCANCEL, &网络词库::OnClose)
	ON_BN_CLICKED(IDC_BUTTON2, &网络词库::OnBnClickedButton2)
END_MESSAGE_MAP()

CEdit* edit;
// 网络词库 消息处理程序
BOOL 网络词库::OnInitDialog() {
	edit = (CEdit*)GetDlgItem(IDC_BUTTON2);
	edit->ShowWindow(FALSE);
	return TRUE;
}
void 网络词库::OnClose() {
	网络词库::OnOK();
}

void 网络词库::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	DWORD flag;
	BOOL con = InternetGetConnectedState(&flag, 0);//检测是否连接网络
	if (con) {
		CEdit* Text;
		CString str;
		Text = (CEdit*)GetDlgItem(IDC_Web1);
		Text->GetWindowText(str);
		w.Eng = CStringA(str);
		w.Find();
		Text = (CEdit*)GetDlgItem(IDC_Web2);
		Text->SetWindowText(w.show());
		edit->ShowWindow(1);
	}
	else MessageBox(_T("请检查您的网络连接！"));
}



void 网络词库::OnEnChangeWeb1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码
}


void 网络词库::OnEnChangeWeb2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void 网络词库::OnBnClickedButton2()//打开保存页面
{
	// TODO: 在此添加控件通知处理程序代码
	保存 B;
	B.W = w;
	B.DoModal();
}
