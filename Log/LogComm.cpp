#include "pch.h"
#include "LogComm.h"
CLogComm::CLogComm()
{
}
/// <summary>
/// �t�@�C�����ɋ֎~�������g�p����Ă��Ȃ������m�F
/// </summary>
/// <param name="pszFileName">���O�o�͐�t�@�C�����Ɏg�p����</param>
/// <return>TRUE�F�֎~�����Ȃ� FALSE�F�֎~��������</return>
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
/// ���O�o�͗p�����̎擾
/// </summary>
/// <return>����</return>
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
