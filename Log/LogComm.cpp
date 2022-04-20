#include "pch.h"
#include "LogComm.h"
CLogComm::CLogComm()
{
}
/// <summary>
/// ファイル名に禁止文字が使用されていないかを確認
/// </summary>
/// <param name="pszFileName">ログ出力先ファイル名に使用する</param>
/// <return>TRUE：禁止文字なし FALSE：禁止文字あり</return>
BOOL CLogComm::CheckFileName(char cLogFileName[_MAX_FNAME])
{
	CString csFileName;
	csFileName = cLogFileName;
	int nResult = csFileName.FindOneOf("\\/:+?\"<>|");
	if (nResult != -1) 
	{
		return FALSE;
	}
	return TRUE;
}

/// <summary>
/// ログ出力用日時の取得
/// </summary>
/// <return>日時</return>
CString CLogComm::GetTime()
{
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	CString csTime;
	csTime.Format("%04d/%02d/%02d\t%02d:%02d:%02d.%03d",
		systime.wYear,
		systime.wMonth,
		systime.wDay,
		systime.wHour,
		systime.wMinute,
		systime.wSecond,
		systime.wMilliseconds);
	return csTime;
}
