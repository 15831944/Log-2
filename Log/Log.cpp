// Log.cpp : DLL の初期化ルーチンを定義します。
//

#include "pch.h"
#include "framework.h"
#include "Log.h"
#include "LogComm.h"
#include "LogInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: この DLL が MFC DLL に対して動的にリンクされる場合、
//		MFC 内で呼び出されるこの DLL からエクスポートされたどの関数も
//		関数の最初に追加される AFX_MANAGE_STATE マクロを
//		持たなければなりません。
//
//		例:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 通常関数の本体はこの位置にあります
//		}
//
//		このマクロが各関数に含まれていること、MFC 内の
//		どの呼び出しより優先することは非常に重要です。
//		it は、次の範囲内で最初のステートメントとして表示されるべきです
//		らないことを意味します、コンストラクターが MFC
//		DLL 内への呼び出しを行う可能性があるので、オブ
//		ジェクト変数の宣言よりも前でなければなりません。
//
//		詳細については MFC テクニカル ノート 33 および
//		58 を参照してください。
//

//// CLogApp
//
//BEGIN_MESSAGE_MAP(CLogApp, CWinApp)
//END_MESSAGE_MAP()
//
//
//// CLogApp の構築
//
//CLogApp::CLogApp()
//{
//	// TODO: この位置に構築用コードを追加してください。
//	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
//}
//
//
//// 唯一の CLogApp オブジェクト
//
//CLogApp theApp;
//
//
//// CLogApp の初期化
//
//BOOL CLogApp::InitInstance()
//{
//	CWinApp::InitInstance();
//
//	return TRUE;
//}



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
int SetOutputDirPath(char cDirPath[MAX_PATH], char cLogFileName[_MAX_FNAME], int& nIndex, int nFormatType )
{
	// 出力先親フォルダが存在するか確認
	CString  csDirPath;
	csDirPath = _T(cDirPath);
	CFileFind cFileFind;
	BOOL bFileCheck = cFileFind.FindFile(csDirPath);  // 0以外：正常終了
	if (bFileCheck == 0)
	{
		DWORD dwResult = GetLastError();
		// フォルダが存在しないためエラー
		return -1;
	}
	// ログ出力先ファイル名が空白でないか確認
	CString csFileName;
	csFileName.Format("%s", cLogFileName);
	bool bEmptyCheck = csFileName.IsEmpty();
	if (bEmptyCheck == true) 
	{
		// ファイル名が空白""のためエラー
		return -2;
	}
	// ログ出力先ファイル名に禁止文字を使用していないか確認
	CLogComm cLogComm;
	BOOL bCheckFileName = cLogComm.CheckFileName(cLogFileName);
	if (bCheckFileName == FALSE) 
	{

		// ファイル名に禁止文字が使用されているためエラー
		return -3;
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
		// 
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
	nIndex = (unsigned int)m_patLogInfoList->GetCount() - 1;
	


	return LOG_SUCCESS;
}

/// <summary>
/// ログ出力
/// </summary>
/// <param name="nIndex">ログ出力に使用するインデックス</param>
/// <param name="szSourceFileName">ソースファイル名</param>
/// <param name="nSourceLine">ソース行数</param>
/// /// <param name="szFunctionName">関数名</param>
/// <return>0：正常終了 0以外：エラー</return>
int WriteLog(int nIndex, char szLogText[MAX_LOG_TEXT], char szSourceFileName[_MAX_FNAME], int nSourceLine, char szFunctionName[_MAX_FNAME])
{
	
	TLogInfo tLogInfo;
	
	tLogInfo.csFunctionName;


	return 0;
}
;

