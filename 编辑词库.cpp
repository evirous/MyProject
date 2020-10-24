// 编辑词库.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "编辑词库.h"
#include "afxdialogex.h"
#include"Dict.h"
#include"单词.h"
#include"文件浏览.h"
#include<wininet.h>



// 编辑词库 对话框

IMPLEMENT_DYNAMIC(编辑词库, CDialogEx)

编辑词库::编辑词库(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SetDict, pParent)
{
	page = 1;
	First = 1;
}

编辑词库::~编辑词库()
{
}

void 编辑词库::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(编辑词库, CDialogEx)
	ON_BN_CLICKED(IDC_SetY, &编辑词库::OnBnClickedSety)
	ON_BN_CLICKED(IDC_Setname, &编辑词库::OnBnClickedSetname)
	ON_BN_CLICKED(IDC_Setdel, &编辑词库::OnBnClickedSetdel)
	ON_BN_CLICKED(IDC_Setadd, &编辑词库::OnBnClickedSetadd)
	ON_BN_CLICKED(IDC_Setchange, &编辑词库::OnBnClickedSetchange)
	ON_BN_CLICKED(IDCANCEL, &编辑词库::OnClose)
	ON_BN_CLICKED(IDC_Setall, &编辑词库::OnBnClickedSetall)
	ON_BN_CLICKED(IDC_SetDelAll, &编辑词库::OnBnClickedSetdelall)
END_MESSAGE_MAP()


// 编辑词库 消息处理程序

BOOL 编辑词库::OnInitDialog() {//初始化
	if (First == 1) {//第一次进入页面，读取词库表
		DD.Read();
		First = 0;
	}
		SetDlgItemText(IDC_Set1, _T("0、新建词库\r\n")+DD.showvalue());//设置界面显示与不显示部分
		Edit = (CEdit*)GetDlgItem(IDC_Setadd);Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_Setdel); Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_Setchange); Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_Setall); Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_Setname); Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_SetDelAll); Edit->ShowWindow(FALSE);
		Edit = (CEdit*)GetDlgItem(IDC_SetY); Edit->ShowWindow(1);
	return TRUE;
}

void 编辑词库::OnClose() {//写入与清空链表
	if (page == 2) {
		if(number==0){ LL.Write(DD[0]); }
		else { LL.Write(DD[number + 2]); }
		page = 1;
	}
	DD.Write();
	LL.DelAll();
	DD.DelAll();
	编辑词库::OnOK();
}
void 编辑词库::OnBnClickedSety()//读取词库并显示
{
	// TODO: 在此添加控件通知处理程序代码
	if (page == 1) {
		number = GetDlgItemInt(IDC_Set2);
		if (number<0 || number>(DD.Len()-2)) { SetDlgItemText(IDC_Set2, _T("该词库不存在！")); return; }
		if (number == 0) {//如果新建词库，设置词库名称
			DD.Add("dictionary-"+DD.Len());
		}
		else { LL.Read(DD[number+2]); }
		SetDlgItemText(IDC_Set1, LL.show());
		Edit = (CEdit*)GetDlgItem(IDC_Setadd); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_Setdel); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_Setchange); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_Setall); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_Setname); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_SetDelAll); Edit->ShowWindow(1);
		Edit = (CEdit*)GetDlgItem(IDC_SetY); Edit->ShowWindow(0);
		page = 2;
	}
}


void 编辑词库::OnBnClickedSetname()//修改词库名称
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* text=(CEdit*)GetDlgItem(IDC_Set2);
	CString sstr;
	text->GetWindowText(sstr);
	string sss,s= CStringA(sstr);
	if (number == 0) { sss = DD[0]; if (DD.Change(number, s)) { rename(sss.c_str(), DD[number].c_str()); MessageBox(_T("词库名称修改成功！")); } }
	else { if (DD.Change(number + 2, s)) { sss = DD[number + 2]; rename(sss.c_str(), DD[number + 2].c_str()); MessageBox(_T("词库名称修改成功！")); } else MessageBox(_T("该名称已存在，请更换名称！")); }
	
}


void 编辑词库::OnBnClickedSetdel()//删除单词
{
	// TODO: 在此添加控件通知处理程序代码
	if(GetDlgItemInt(IDC_Set2)<=0|| GetDlgItemInt(IDC_Set2) >LL.length()){ SetDlgItemText(IDC_Set2, _T("该单词不存在！")); return; }
	LL.Del(GetDlgItemInt(IDC_Set2));
	SetDlgItemText(IDC_Set1, LL.show());
}


void 编辑词库::OnBnClickedSetadd()//增添单词
{
	// TODO: 在此添加控件通知处理程序代码
	单词 D;
	D.DoModal();
	if (D.Y == 1) {
		LL.save(D.setword);
		D.Y = 0;
		SetDlgItemText(IDC_Set1, LL.show());
	}
}


void 编辑词库::OnBnClickedSetchange()//修改单词
{
	// TODO: 在此添加控件通知处理程序代码
	单词 DC;
	string S1, S2;
	if (GetDlgItemInt(IDC_Set2) <= 0 || GetDlgItemInt(IDC_Set2) > LL.length()) { SetDlgItemText(IDC_Set2, _T("该词库不存在！")); return; }
	DC.setword = LL[GetDlgItemInt(IDC_Set2)-1];
	DC.DoModal();
	if (DC.Y == 1) {
		S1 = DC.s1;
		S2 = DC.s2;
		LL.Del(GetDlgItemInt(IDC_Set2));
		Word w;
		w.Eng = S1, w.Addusual(S2);
		LL.save(w);
		DC.Y = 0;
		SetDlgItemText(IDC_Set1, LL.show());
	}
}


void 编辑词库::OnBnClickedSetall()//批量导入
{
	// TODO: 在此添加控件通知处理程序代码
	文件浏览 L;
	L.DoModal();
	if (L.WorL == 0)return;
	if (L.WorL == 1) {
		DWORD flag;
		BOOL con = InternetGetConnectedState(&flag, 0);
		if (con) {
			string s = CStringA(L.thefile);
			LL.DaoruW(s);
			L.WorL = 0;
			SetDlgItemText(IDC_Set1, LL.show());
		}
		else MessageBox(_T("请检查您的网络连接！"));
	}
	if (L.WorL == 2) {
		string s = CStringA(L.thefile);
		LL.DaoruL(s);
		L.WorL = 0;
		SetDlgItemText(IDC_Set1, LL.show());
	}
}


void 编辑词库::OnBnClickedSetdelall()//删除词库
{
	// TODO: 在此添加控件通知处理程序代码
	if (number == 0)DD.Del(number);
	else DD.Del(number + 2);
	MessageBox(_T("删除成功！"));
	page = 1;
	LL.DelAll();
	编辑词库::OnInitDialog();
}
