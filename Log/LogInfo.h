#pragma once





struct TLogInfo
{
public:
	CString csLogTime; // ログ日時
	CString csLogLevel; // ログレベル
	CString csSourceFileName; // ソースファイル名
	int nSoourceLine; // 行数
	CString csFunctionName; // 関数名
	CString csLogText; // ログ内容
	int nIndex; // インデックス
	TLogInfo()
	{
		csLogTime = "";
		csLogLevel = "";
		csSourceFileName = "";
		nSoourceLine = 0;
		csFunctionName = "";
		csLogText = "";
		nIndex = 0;
	}
};


class CLogInfo
{
public:
	// コンストラクタ
	CLogInfo(wchar_t cDirPath[MAX_PATH], wchar_t cLogFileName[_MAX_FNAME], int nFormatType);

	/// <summary>
	/// メンバ変数にインデックスを設定
	/// </summary>
	/// <param name="nIndex">登録するインデックスに使用</param>
	/// <return></return>
	void SetIndex(int nIndex);

	/// <summary>
	/// メンバ変数のインデックスを取得
	/// </summary>
	/// <return>登録したインデックス</return>
	int GetIndex();


	/// <summary>
	/// メンバ変数の出力先親フォルダのパスを設定
	/// </summary>
	/// <param name="nIndex">出力先親フォルダのパス</param>
	/// <return></return>
	void SetDirPath(CString csDirPath);

	CString GetDirPath();

	/// <summary>
	/// メンバ変数の出力先親フォルダのパスを設定
	/// </summary>
	/// <param name="nIndex">出力先親フォルダのパス</param>
	/// <return></return>
	void SetLogFileName(CString cLogFileName);

	CString GetLogFileName();

	// メンバー変数
	CString m_csDirPath; // ログ出力先親フォルダパス
	CString m_csLogFileName; // ログ出力先ファイル名
	int m_nFormatType;
};
