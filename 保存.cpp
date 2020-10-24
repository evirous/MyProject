// 保存.cpp: 实现文件
//

#include "pch.h"
#include "Baicisha.h"
#include "保存.h"
#include"Dict.h"
#include "afxdialogex.h"


// 保存 对话框

IMPLEMENT_DYNAMIC(保存, CDialogEx)

保存::保存(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Save, pParent)
{
	New = 0;
	Er = 0;
}

保存::~保存()
{
}

void 保存::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(保存, CDialogEx)
	ON_EN_CHANGE(IDC_Save1, &保存::OnEnChangeSave1)
	ON_EN_CHANGE(IDC_Save2, &保存::OnEnChangeSave2)
	ON_BN_CLICKED(IDC_Saveb1, &保存::OnBnClickedSaveb1)
	ON_BN_CLICKED(IDC_Saveb2, &保存::OnBnClickedSaveb2)
	ON_BN_CLICKED(IDCANCEL, &保存::OnClose)
END_MESSAGE_MAP()


// 保存 消息处理程序
BOOL 保存::OnInitDialog() {//初始化
	if (Er == 0) {
		if (New == 0) {//第一次进入，新建词库
			DS.Read();
			SetDlgItemText(IDC_Save1, _T("0、新建词库\r\n") + DS.showvalue());
		}
		if (New == 1) {//第二次进入：设置词库名称
			SetDlgItemText(IDC_Save1, _T("请输入词库名称"));
		}
	}
	else { SetDlgItemText(IDC_Save2, _T("该词库不存在！")); Er = 0; }
	return TRUE;
}
void 保存::OnClose() {
	New = 0;
	LS.DelAll();
	DS.DelAll();
	保存::OnOK();
}
void 保存::OnEnChangeSave1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void 保存::OnEnChangeSave2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void 保存::OnBnClickedSaveb1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (New == 0) {//第一次进入
		Num = GetDlgItemInt(IDC_Save2);
		if (Num<0 || Num>(DS.Len()-2)) { Er = 1; 保存::OnInitDialog(); return; }//如果输入数字超出范围，返回并提示错误
		else {
			if (Num == 0) { New = 1; OnInitDialog();  return; }//新建词库
			else {//读取已有词库
				LS.Read(DS[Num+2]);
				LS.save(W);
				LS.Write(DS[Num+2]);
				保存::OnClose();
				return;
			}
		}
	}
	if (New == 1) {//第二次进入，保存单词
		CEdit* Txt;
		CString s;
		Txt = (CEdit*)GetDlgItem(IDC_Save2);
		Txt->GetWindowText(s);
		USES_CONVERSION;
		DS.Add(W2A(s));
		LS.save(W);
		LS.Write(DS[0]);
		DS.Write();
		保存::OnClose();
		return;
	}
}


void 保存::OnBnClickedSaveb2()//取消
{
	// TODO: 在此添加控件通知处理程序代码
	保存::OnClose();
	return;
}
