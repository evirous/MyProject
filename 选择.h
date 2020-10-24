#pragma once


// 选择 对话框

class 选择 : public CDialogEx
{
	DECLARE_DYNAMIC(选择)

public:
	CString B[8];
	CString Title;
	int Right,YN,Fini,J;
	选择(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~选择();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Choose };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL 选择::OnInitDialog();
	afx_msg void OnClose();
	afx_msg void Just(int n);
	afx_msg void OnEnChangeC1();
	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedFinish();
};
