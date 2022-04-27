#include "pch.h"
#include "LogInfo.h"



CLogInfo::CLogInfo(wchar_t cDirPath[MAX_PATH], wchar_t cLogFileName[_MAX_FNAME], int nFormatType)
{
	m_csDirPath = cDirPath;
	m_csLogFileName = cLogFileName;
	m_nFormatType = nFormatType;



}

/// <summary>
/// メンバ変数にインデックスを設定
/// </summary>
/// <param name="nIndex">登録するインデックスに使用</param>
/// <return></return>
void CLogInfo::SetIndex(int nIndex)
{
	
}

int CLogInfo::GetIndex()
{
	return 0;
}

void CLogInfo::SetDirPath(CString csDirPath)
{ 
	m_csDirPath = csDirPath;
}

CString CLogInfo::GetDirPath()
{
	return m_csDirPath;
}

void CLogInfo::SetLogFileName(CString csLogFileName)
{
	m_csLogFileName = csLogFileName;
}

CString CLogInfo::GetLogFileName()
{
	return m_csLogFileName;
}
