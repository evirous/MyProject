#pragma once


// 学习模式 对话框

class 学习模式 : public CDialogEx
{
	DECLARE_DYNAMIC(学习模式)

public:
	学习模式(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~学习模式();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Study };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
