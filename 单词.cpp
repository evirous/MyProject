// 单词.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "单词.h"
#include "afxdialogex.h"
#include"Dict.h"


// 单词 对话框

IMPLEMENT_DYNAMIC(单词, CDialogEx)

单词::单词(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Word, pParent)
{
	
}

单词::~单词()
{
}

void 单词::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(单词, CDialogEx)
	ON_BN_CLICKED(IDC_wordy, &单词::OnBnClickedwordy)
	ON_BN_CLICKED(IDC_wordn, &单词::OnBnClickedwordn)
END_MESSAGE_MAP()

// 单词 消息处理程序
BOOL 单词::OnInitDialog() {//显示英文及注释
	CString cs = _T("");
	cs = (setword.Eng).c_str();
	SetDlgItemText(IDC_word1,cs) ;
	if (setword.usual.Head != NULL) {
		cs = ( setword.usual.Head->Wo).c_str();
		SetDlgItemText(IDC_word2,cs);
	}
	return TRUE;
}
void 单词::OnBnClickedwordy()//修改英文及注释
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* settext = (CEdit*)GetDlgItem(IDC_word1);
	CString ssr;
	settext->GetWindowText(ssr);
	setword.Eng=CStringA(ssr);
	s1= CStringA(ssr);
	settext = (CEdit*)GetDlgItem(IDC_word2);
	settext->GetWindowText(ssr);
	string add = CStringA(ssr);
	s2 = add;
	setword.Addusual(add);
	if(setword.Eng!=""){Y = 1;}
	单词::OnOK();
}



void 单词::OnBnClickedwordn()
{
	// TODO: 在此添加控件通知处理程序代码
	单词::OnOK();
}
