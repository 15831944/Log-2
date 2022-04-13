
// LogTestDlg.h : ヘッダー ファイル
//

#pragma once


// CLogTestDlg ダイアログ
class CLogTestDlg : public CDialogEx
{
// コンストラクション
public:
	CLogTestDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnShowWindow();
	afx_msg void OnBnClickedButton2();
private:
	CEdit DirPath;
	// 戻り値
	CEdit Result;
	CEdit Index;
	CEdit FileName;
	CEdit Index_W;
public:
	CEdit Result_W;
};
