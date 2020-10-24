#pragma once
#include"Dict.h"

// 保存 对话框

class 保存 : public CDialogEx
{
	DECLARE_DYNAMIC(保存)

public:
	DList DS;
	List LS;
	Word W;
	int Num;
	int New ;
	int Er ;
	保存(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~保存();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Save };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL 保存::OnInitDialog();
	afx_msg void OnEnChangeSave1();
	afx_msg void OnEnChangeSave2();
	afx_msg void OnBnClickedSaveb1();
	afx_msg void OnBnClickedSaveb2();
	afx_msg void OnClose();
};
