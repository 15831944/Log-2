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
