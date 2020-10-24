#pragma once

#include"Dict.h"
// 练习模式 对话框

class 练习模式 : public CDialogEx
{
	DECLARE_DYNAMIC(练习模式)

public:
	int temp;
	int nn;
	DList DDL;
	List LLL;
	CEdit* LEdit;
	int LX[8];
	练习模式(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~练习模式();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Train };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTry();
	afx_msg void Choose(int n);
	afx_msg void OnClose();
	virtual BOOL 练习模式::OnInitDialog();
	afx_msg void OnBnClickedEtc();
	afx_msg void OnBnClickedCte();
	afx_msg void OnBnClickedEte();
	afx_msg void OnBnClickedJztk();
	afx_msg void OnEnChangeTr1();
};
