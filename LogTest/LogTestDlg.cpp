
// LogTestDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "LogTest.h"
#include "LogTestDlg.h"
#include "afxdialogex.h"

#include "../Log/Log.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#include <format>


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CLogTestDlg ダイアログ



CLogTestDlg::CLogTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, DirPath);
	DDX_Control(pDX, IDC_EDIT5, Result);
	DDX_Control(pDX, IDC_EDIT3, Index);
	DDX_Control(pDX, IDC_EDIT2, FileName);
	DDX_Control(pDX, IDC_EDIT7, Index_W);
	DDX_Control(pDX, IDC_EDIT10, Result_W);
}

BEGIN_MESSAGE_MAP(CLogTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLogTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLogTestDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CLogTestDlg メッセージ ハンドラー

BOOL CLogTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	OnShowWindow();

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CLogTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CLogTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CLogTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// SetOutputDirPath関数の呼び出し
void CLogTestDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	

	CString csDirPath;
	this->DirPath.GetWindowText(csDirPath);
	char* pszDirPath = new char[MAX_PATH];
	ZeroMemory(pszDirPath, MAX_PATH);
	pszDirPath = csDirPath.GetBuffer();
	
	CString csFileName;
	this->FileName.GetWindowText(csFileName);
	
	char* pszFileName = new char[MAX_PATH];
	ZeroMemory(pszFileName, MAX_PATH);
	pszFileName = csFileName.GetBuffer();


	CString csIndex = 0;
	int nIndex = _ttoi(_T(csIndex));
	int nResult = SetOutputDirPath(pszDirPath, pszFileName, nIndex, 0);
	csIndex.Format("%d", nIndex);
	this->Index.SetWindowText(csIndex);
	this->Index_W.SetWindowText(csIndex);
	CString csResult;
	csResult.Format("%d", nResult);
	this->Result.SetWindowText(csResult);

}

void CLogTestDlg::OnShowWindow()
{

	CString csDirePath = "C:\\Test\\Log";
	this->DirPath.SetWindowText(csDirePath);

	CString csFileName = "TestFile";
	this->FileName.SetWindowText(csFileName);

}

// WriteLogの書き出し
void CLogTestDlg::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	char szLogtext[MAX_LOG_TEXT] = "test";
	char szFunctionName[_MAX_FNAME] = "LogFunction";
	CString csIndex = 0;
	int nIndex = _ttoi(_T(csIndex));
	int nResult = 0;
	nResult = WriteLog(nIndex, szLogtext, __FILE__, __LINE__, szFunctionName);
	CString csResult;
	csResult.Format("%d", nResult);
	this->Result_W.SetWindowText(csResult);
}
