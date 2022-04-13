// Log.h : Log DLL のメイン ヘッダー ファイル
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル

#if DLL_EXPORTS
#define DLL_API extern "C" __declspec(dllexport)
#else
#define DLL_API extern "C" __declspec(dllimport)
#endif

#define LOG_SUCCESS 0 // ログ成功
#define MAX_LOG_TEXT 100 // テキストの最大値


// CLogApp
// このクラスの実装に関しては Log.cpp をご覧ください
//
//
//VC_DLL_EXPORTS class CLogApp : public CWinApp
//{
//public:
//	CLogApp();
//
//// オーバーライド
//public:
//	virtual BOOL InitInstance();
//
//	DECLARE_MESSAGE_MAP()
//};
enum ELogLevel
{
	LOG_DEBUG = 1, // デバッグ
	LOG_INFO, // ガイダンス
	LOG_WARNING, // 警告
	LOG_ERROR // エラー
};


/// <summary>
/// ログ出力先親フォルダを確認
/// </summary>
/// <param name="pszDirPath">ログ出力先親フォルダのパス</param>
/// <param name="pszFileName">ログ出力に使用するファイル名（プロセス名）</param>
/// <param name="nIndex">ログ出力に使用するインデックス</param>
/// <param name="nFormatType">ログ出力フォーマット 0:システムログ　1：通信ログ</param>
/// <return>0：正常終了 0以外：エラー</return>
DLL_API int SetOutputDirPath(char cDirPath[MAX_PATH], char cLogFileName[_MAX_FNAME], int& nIndex, int nFormatType = 0);


/// <summary>
/// ログ出力
/// </summary>
/// <param name="nIndex">ログ出力に使用するインデックス</param>
/// <param name="szLogText">ログテキスト</param>
/// <param name="szSourceFileName">ソースファイル名</param>
/// <param name="nSourceLine">ソース行数</param>
/// <param name="szFunctionName">関数名</param>
/// <return>0：正常終了 0以外：エラー</return>
DLL_API int WriteLog(int nIndex, char cLogText[MAX_LOG_TEXT], char cSourceFileName[_MAX_FNAME], int nSourceLine, char cFunctionName[_MAX_FNAME]);