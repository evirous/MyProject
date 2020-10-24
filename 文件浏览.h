#pragma once


// 文件浏览 对话框

class 文件浏览 : public CDialogEx
{
	DECLARE_DYNAMIC(文件浏览)

public:
	int WorL;
	CString thefile;
	文件浏览(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~文件浏览();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_File };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_file;
	afx_msg void OnBnClickedFileb1();
	afx_msg void OnBnClickedFileb2();
	afx_msg void OnBnClickedButton1();
};
