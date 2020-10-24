#pragma once

#include"Dict.h"
// 编辑词库 对话框

class 编辑词库 : public CDialogEx
{
	DECLARE_DYNAMIC(编辑词库)

public:
	int	page;
	int number;
	int First;
	DList DD;
	List LL;
	CEdit* Edit;
	编辑词库(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~编辑词库();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SetDict };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL 编辑词库::OnInitDialog();
	afx_msg void OnBnClickedSety();
	afx_msg void OnBnClickedSetname();
	afx_msg void OnBnClickedSetdel();
	afx_msg void OnBnClickedSetadd();
	afx_msg void OnBnClickedSetchange();
	afx_msg void OnClose();
	afx_msg void OnBnClickedSetall();
	afx_msg void OnBnClickedSetdelall();
};
