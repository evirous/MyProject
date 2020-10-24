// 练习模式.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "练习模式.h"
#include "afxdialogex.h"
#include"Dict.h"
#include"选择.h"


// 练习模式 对话框

IMPLEMENT_DYNAMIC(练习模式, CDialogEx)

练习模式::练习模式(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Train, pParent)
{
}

练习模式::~练习模式()
{
}

void 练习模式::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(练习模式, CDialogEx)
	ON_BN_CLICKED(IDC_TrY, &练习模式::OnBnClickedTry)
	ON_BN_CLICKED(IDCANCEL, &练习模式::OnClose)
	ON_BN_CLICKED(IDC_ETC, &练习模式::OnBnClickedEtc)
	ON_BN_CLICKED(IDC_CTE, &练习模式::OnBnClickedCte)
	ON_BN_CLICKED(IDC_ETE, &练习模式::OnBnClickedEte)
	ON_BN_CLICKED(IDC_JZTK, &练习模式::OnBnClickedJztk)
	ON_EN_CHANGE(IDC_Tr1, &练习模式::OnEnChangeTr1)
END_MESSAGE_MAP()


// 练习模式 消息处理程序
void 练习模式::OnEnChangeTr1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void 练习模式::OnClose() {//清空所有链表
	LLL.Write(DDL[nn]);
	LLL.DelAll();
	DDL.DelAll();
	练习模式::OnOK();
}
BOOL 练习模式::OnInitDialog() {
	srand((unsigned)time(NULL));//重置随机种子
	DDL.Read();
	SetDlgItemText(IDC_Tr1, DDL.show());
	LEdit = (CEdit*)GetDlgItem(IDC_ETC); LEdit->ShowWindow(FALSE);
	LEdit = (CEdit*)GetDlgItem(IDC_CTE); LEdit->ShowWindow(FALSE);
	LEdit = (CEdit*)GetDlgItem(IDC_ETE); LEdit->ShowWindow(FALSE);
	LEdit = (CEdit*)GetDlgItem(IDC_JZTK); LEdit->ShowWindow(FALSE);
	return TRUE;
}

void 练习模式::OnBnClickedTry()//检测并读取词库
{
	// TODO: 在此添加控件通知处理程序代码
	nn = GetDlgItemInt(IDC_Tr2);
	if (nn <= 0 || nn > DDL.Len()) { SetDlgItemText(IDC_Tr2,_T("该词库不存在！")); return; }
	LLL.Read(DDL[nn]);
	if (LLL.Lack()) {
		MessageBox(_T("词库单词数量不足，请更换词库或添加单词！"));
		LLL.DelAll();
		return;
	}
	if (LLL.Finish()) {
		if (MessageBox(_T("所有单词已学习完毕，是否重新学习？", MB_YESNO)) == 6)LLL.ReStart();
		else {
			LLL.DelAll();
			return;
		}
	}
	LEdit = (CEdit*)GetDlgItem(IDC_ETC); LEdit->ShowWindow(1);
	LEdit = (CEdit*)GetDlgItem(IDC_CTE); LEdit->ShowWindow(1);
	LEdit = (CEdit*)GetDlgItem(IDC_ETE); LEdit->ShowWindow(1);
	LEdit = (CEdit*)GetDlgItem(IDC_JZTK); LEdit->ShowWindow(1);
	LEdit = (CEdit*)GetDlgItem(IDC_TrY); LEdit->ShowWindow(FALSE);
}

void 练习模式::Choose(int n) {//选择一个符合条件的单词
		for (;;) {
			LX[0] = rand() % LLL.length();
			if (LLL[LX[0]].Select(n))break;
		}
	for (int i=0;i<7;i++) {
		for (;;) {
			int b = 0;
			LX[i + 1] = rand() % LLL.length();
			for (int j = 0;j<=i;j++) {
				if (LX[i+1] == LX[j]) { b = 1; break; }
			}
			if (b == 0)break;
		}
	}
}
void 练习模式::OnBnClickedEtc()//打乱顺序为选择页面中各变量赋值，打开选择页面
{
	// TODO: 在此添加控件通知处理程序代码
	选择 X;
	for (;;) {
		Choose(0);
		X.Title = (LLL[LX[0]].Eng).c_str();
		X.Right = rand() % 8;
		temp = LX[0];
		LX[0] = LX[X.Right];
		LX[X.Right] = temp;
		for (int i = 0; i < 8; i++) {
			X.B[i] = ((LLL[LX[i]].usual.Head->Wo).substr(0,13)).c_str();
		}
		X.DoModal();
		if (X.YN == 1) { LLL[X.Right].AddScore(); }
		if (X.YN == -1) { LLL[X.Right].DelScore(); }
		if (X.Fini == 1)break;

	}
}


void 练习模式::OnBnClickedCte()//打乱顺序为选择页面中各变量赋值，打开选择页面
{
	// TODO: 在此添加控件通知处理程序代码
	选择 X;
	for (;;) {
		Choose(0);
		X.Title = (LLL[LX[0]].usual.Head->Wo).c_str();
		X.Right = rand() % 8;
		temp = LX[0];
		LX[0] = LX[X.Right];
		LX[X.Right] = temp;
		for (int i = 0; i < 8; i++) {
			X.B[i] = (LLL[LX[i]].Eng).c_str();
		}
		X.DoModal();
		if (X.YN == 1) { LLL[X.Right].AddScore(); }
		if (X.YN == -1) { LLL[X.Right].DelScore(); }
		if (X.Fini == 1)break;

	}
}


void 练习模式::OnBnClickedEte()//打乱顺序为选择页面中各变量赋值，打开选择页面
{
	// TODO: 在此添加控件通知处理程序代码
	选择 X;
	for (;;) {
		Choose(1);
		X.Title = (LLL[LX[0]].entoen.Head->Wo).c_str();
		X.Right = rand() % 8;
		temp = LX[0];
		LX[0] = LX[X.Right];
		LX[X.Right] = temp;
		for (int i = 0; i < 8; i++) {
			X.B[i] = (LLL[LX[i]].Eng).c_str();
		}
		X.DoModal();
		if (X.YN == 1) { LLL[X.Right].AddScore(); }
		if (X.YN == -1) { LLL[X.Right].DelScore(); }
		if (X.Fini == 1)break;

	}
}


void 练习模式::OnBnClickedJztk()//打乱顺序为选择页面中各变量赋值，打开选择页面
{
	// TODO: 在此添加控件通知处理程序代码
	选择 X;
	for (;;) {
		Choose(2);
		string eg = LLL[LX[0]].profes.Head->EG;
		int f=eg.find(LLL[LX[0]].Eng);
		string EG = eg.substr(0, f ) + "______" + eg.substr(f+ LLL[LX[0]].Eng.length());
		X.Title = (EG).c_str();
		X.Right = rand() % 8;
		temp = LX[0];
		LX[0] = LX[X.Right];
		LX[X.Right] = temp;
		for (int i = 0; i < 8; i++) {
			X.B[i] = (LLL[LX[i]].Eng).c_str();
		}
		X.DoModal();
		if (X.YN == 1) { LLL[X.Right].AddScore(); }
		if (X.YN == -1) { LLL[X.Right].DelScore(); }
		if (X.Fini == 1)break;

	}
}



