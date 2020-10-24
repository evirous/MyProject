#pragma once
#include"Dict.h"

// 本地词库 对话框

class 本地词库 : public CDialogEx
{
	DECLARE_DYNAMIC(本地词库)

public:
	int Page;
	int NumD;
	int NumL;
	int First;
	int Second;
	int Worng;
	DList D;
	List L;
	本地词库(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~本地词库();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Local };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void OnEnChangeLocal1();
	afx_msg void OnClose();
	afx_msg void OnBnClickedLocalb1();
	afx_msg void OnEnChangeLocal2();
	afx_msg void OnBnClickedReturn();
};
