#pragma once
#include"Dict.h"

// 网络词库 对话框

class 网络词库 : public CDialogEx
{
	DECLARE_DYNAMIC(网络词库)

public:
	Word w;
	网络词库(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~网络词库();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Web };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeWeb1();
	afx_msg void OnEnChangeWeb2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClose();
	virtual BOOL 网络词库::OnInitDialog();
};
