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
