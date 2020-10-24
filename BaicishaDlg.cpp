
// BaicishaDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Baicisha.h"
#include "BaicishaDlg.h"
#include "afxdialogex.h"
#include"学习模式.h"
#include"练习模式.h"
#include"编辑词库.h"
#include"Dict.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBaicishaDlg 对话框



CBaicishaDlg::CBaicishaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BAICISHA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaicishaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBaicishaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBaicishaDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON3, &CBaicishaDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CBaicishaDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CBaicishaDlg 消息处理程序

BOOL CBaicishaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();               //首次运行程序，建立百词杀文件夹
	if (0 != _access("d:\\Baicisha", 0)) {
		_mkdir("d:\\Baicisha");
		DList Dic;
		Dic.Add("CET4");
		Dic.Add("CET6");
		Dic.Write();
	}
	// 将“关于...”菜单项添加到系统菜单中。
	CFont* p=new CFont;
	p->CreatePointFont(400, _T("宋体"));//设置文字
	GetDlgItem(IDC_STATIC)->SetFont(p);
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBaicishaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBaicishaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBaicishaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBaicishaDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	学习模式 S;
	S.DoModal();
}




void CBaicishaDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	编辑词库 B;
	B.DoModal();
}


void CBaicishaDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	练习模式 L;
	L.DoModal();
}
