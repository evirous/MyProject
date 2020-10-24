// 本地词库.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "本地词库.h"
#include "afxdialogex.h"
#include"Dict.h"
#include"保存.h"


// 本地词库 对话框

IMPLEMENT_DYNAMIC(本地词库, CDialogEx)

本地词库::本地词库(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Local, pParent)
{
	Page = 0;
	First = 1;
	Second = 1;
	Worng = 0;
}

本地词库::~本地词库()
{
}

void 本地词库::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(本地词库, CDialogEx)
	ON_EN_CHANGE(IDC_Local1, &本地词库::OnEnChangeLocal1)
	ON_BN_CLICKED(IDC_LocalB1, &本地词库::OnBnClickedLocalb1)
	ON_EN_CHANGE(IDC_Local2, &本地词库::OnEnChangeLocal2)
	ON_BN_CLICKED(IDC_Return, &本地词库::OnBnClickedReturn)
	ON_BN_CLICKED(IDCANCEL, &本地词库::OnClose)
END_MESSAGE_MAP()


// 本地词库 消息处理程序

BOOL 本地词库::OnInitDialog() {//初始化
	if (Page == 0) {//第一页：选择词库
		if (Worng==0) {
			if (First == 1) { D.Read(); First = 0; }
			SetDlgItemText(IDC_Local1, D.show());
		}
		else SetDlgItemText(IDC_Local2, _T("该词库不存在！"));
		SetDlgItemText(IDC_LocalB1, _T("确定"));
	}
	if (Page == 1) {//第二页：选择单词
		if (Worng == 0) {
			if (Second == 1) { L.Read(D[NumD]); Second = 0; }
			SetDlgItemText(IDC_Local1, L.show());
		}
		else SetDlgItemText(IDC_Local2, _T("该单词不存在！"));
		SetDlgItemText(IDC_LocalB1, _T("确定"));
	}
	if (Page == 2) {//第三页：查看单词，可以保存到其他词库
		SetDlgItemText(IDC_Local1, L[NumL-1].show());
		SetDlgItemText(IDC_LocalB1, _T("保存"));
	}
	return TRUE;
}
void 本地词库::OnClose() {
	Page = 0;
	First = 1;
	Second = 1;
	Worng = 0;
	L.DelAll();
	D.DelAll();
	本地词库::OnOK();
}


void 本地词库::OnEnChangeLocal1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码
}


void 本地词库::OnBnClickedLocalb1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Page == 0) {//第一页：显示所有词库
		NumD = GetDlgItemInt(IDC_Local2);
		if (NumD <= D.Len() && NumD > 0) {
			Page=1;
			Second = 1;
			Worng = 0;
		}
		else Worng = 1;
		OnInitDialog();
		return;
	}
	if (Page == 1) {//第二页：显示词库单词
		NumL = GetDlgItemInt(IDC_Local2);
		if (NumL <= L.length() && NumL > 0) {
			Page = 2;
			Worng = 0;
		}
		else Worng = 1;
		OnInitDialog();
		return;
	}
	if (Page == 2) {//第三页：可以保存
		保存 BC;
		BC.W = L[NumL - 1];
		BC.DoModal();
		return;
	}

}


void 本地词库::OnEnChangeLocal2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void 本地词库::OnBnClickedReturn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Page == 2 ) {
		Page--;
		OnInitDialog();
		return;
	}
	if (Page == 1) {
		Page--;
		L.DelAll();
		OnInitDialog();
		return;
	}
	if (Page == 0) {
		OnClose();
		return;
	}
}
