#pragma once
#include"Word.h"

// 单词 对话框

class 单词 : public CDialogEx
{
	DECLARE_DYNAMIC(单词)

public:
	int Y ;
	Word setword;
	string s1, s2;
	单词(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~单词();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Word };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL 单词::OnInitDialog();
	afx_msg void OnBnClickedwordy();
	afx_msg void OnBnClickedwordn();
};
