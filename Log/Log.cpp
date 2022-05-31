// Log.cpp : DLL の初期化ルーチンを定義します。
//
//aaaaa

#include "pch.h"
#include "framework.h"
#include "Log.h"
#include "LogComm.h"
#include "LogInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CArray <CLogInfo*>* m_patLogInfoList = nullptr;

/// <summary>
/// ログ出力先親フォルダを確認
/// </summary>
/// <param name="pszDirPath">ログ出力先親フォルダのパス</param>
/// <param name="pszFileName">ログ出力先ファイル名に使用する</param>
/// <param name="nLine">ソースファイル行数</param>
/// <param name="nIndex">ログ出力に使用するインデックス</param>
/// <param name="nFormatType">ログ出力フォーマット 0:システムログ　1：通信ログ</param>
/// <return>0：正常終了 0以外：エラー</return>
int SetOutputDirPath(TCHAR cDirPath[MAX_PATH], TCHAR cLogFileName[_MAX_FNAME], int& nIndex, int nFormatType )
{
	// 出力先親フォルダが存在するか確認
	CString  csDirPath = cDirPath;
	CFileFind cFileFind;
	// 0以外：正常終了
	if (cFileFind.FindFile(csDirPath) == 0)
	{
		DWORD dwResult = GetLastError();
		// フォルダが存在しないためエラー
		return NOT_FOUND_FOLDER;
	}
	// ログ出力先ファイル名が空白でないか確認
	CString csFileName = cLogFileName;
	if (csFileName.IsEmpty() == true)
	{
		// ファイル名が空白""のためエラー
		return EMPTY_FILE_NAME;
	}
	// ログ出力先ファイル名に禁止文字を使用していないか確認
	CLogComm cLogComm;
	if (cLogComm.CheckFileName(cLogFileName) == FALSE)
	{
		// ファイル名に禁止文字が使用されているためエラー
		return BAN_CHAR_FILE_NAME;
	}
	// 初回
	if (m_patLogInfoList == nullptr)
	{
		nIndex = 0;
		// インスタンス生成
		m_patLogInfoList = new CArray<CLogInfo*>();
		// 配列からすべての要素を削除
		m_patLogInfoList->RemoveAll();
	}

	// インデックスの値を確認
	if (m_patLogInfoList->GetCount() > 0) 
	{
		// インデックスの数だけループ
		for (int i = 0; i <= m_patLogInfoList->GetCount() - 1; i++) 
		{
			// 登録済みか確認
			if (m_patLogInfoList->ElementAt(i)->GetDirPath() == csDirPath && m_patLogInfoList->ElementAt(i)->GetLogFileName() == csFileName)
			{
				// インデックスの値をセット
				nIndex = i;
				return LOG_SUCCESS;
			}
		}
	}

	// インスタンス生成
	CLogInfo* cLogInfo = new CLogInfo(cDirPath, cLogFileName, nFormatType);

	// 配列の末尾に要素を追加
	m_patLogInfoList->Add(cLogInfo);
	
	// インデックスの値を設定
	nIndex = (unsigned int)m_patLogInfoList->GetCount() - 1;
	return LOG_SUCCESS;
}

/// <summary>
/// ログ出力
/// </summary>
/// <param name="nIndex">ログ出力に使用するインデックス</param>
/// <param name="szSourceFileName">ソースファイル名</param>
/// <param name="nSourceLine">ソース行数</param>
/// <param name="szFunctionName">関数名</param>
/// <return>0：正常終了 0以外：エラー</return>
int WriteLog(int nIndex, TCHAR szLogText[MAX_LOG_TEXT], TCHAR szSourceFileName[_MAX_FNAME], int nSourceLine, TCHAR szFunctionName[_MAX_FNAME])
{
	
	TLogInfo tLogInfo;
	CLogComm cLogComm;
	//yyyy/mm/dd hh:mm:ss.000 [LogLevel] (SourceFileName.cpp:SourceLine) FunctionName LogText
	tLogInfo.csLogTime = cLogComm.GetTime();
	tLogInfo.csSourceFileName = szSourceFileName;
	tLogInfo.nSoourceLine = nSourceLine;
	tLogInfo.csFunctionName = szFunctionName;
	tLogInfo.csLogText = szLogText;
	// ソースファイル名の整形
	tLogInfo.csSourceFileName = tLogInfo.csSourceFileName.Right(tLogInfo.csSourceFileName.GetLength() - tLogInfo.csSourceFileName.ReverseFind(_T('\\')) - 1);

	// ログ出力内容の整形
	CString strText;
	strText.Format(_T("%s\t[LogLevel]\t(%s:%d)\t%s\t%s\r\n"),
		tLogInfo.csLogTime,
		tLogInfo.csSourceFileName,
		(unsigned)tLogInfo.nSoourceLine,
		tLogInfo.csFunctionName,
		szLogText);
	TCHAR* BufferToData = (TCHAR*)(strText.GetBuffer());
	UINT Count = strText.GetLength() * sizeof(TCHAR);

	CString csPath;
	csPath.Format(_T("%s\\%s.log"),
		m_patLogInfoList->ElementAt(nIndex)->GetDirPath(),
		m_patLogInfoList->ElementAt(nIndex)->GetLogFileName());
	CFile cFile;
	cFile.Open(csPath, CFile::modeWrite | CFile::modeCreate| CFile::modeNoTruncate);
	cFile.SeekToEnd();
	cFile.Write(BufferToData, Count);



	return 0;
}

/// <summary>
/// インスタンスクラス
/// </summary>
class CInstanceClass
{
public:
	// コンストラクタ
	CInstanceClass()
	{

	};
	// デストラクタ
	~CInstanceClass()
	{
		if (m_patLogInfoList != nullptr)
		{
			for (int i=0; i < m_patLogInfoList->GetCount(); i++)
			{

				CLogInfo* pLogInfo = m_patLogInfoList->GetAt(i);
				delete pLogInfo;
			}
			m_patLogInfoList->RemoveAll();
			delete m_patLogInfoList;
			m_patLogInfoList = NULL;
		}

	}

};

CInstanceClass cInstanceClass;


