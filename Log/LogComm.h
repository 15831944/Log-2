#pragma once
class CLogComm
{
public:
	CLogComm();

	/// <summary>
	/// �t�@�C�����ɋ֎~�������g�p����Ă��Ȃ������m�F
	/// </summary>
	/// <param name="pszFileName">���O�o�͐�t�@�C�����Ɏg�p����</param>
	/// <return>TRUE�F�֎~�����Ȃ� FALSE�F�֎~��������</return>
	BOOL CheckFileName(char cFileName[_MAX_FNAME] );
	
	/// <summary>
	/// ���O�o�͗p�����̎擾
	/// </summary>
	/// <return>����</return>
	CString GetTime();
};

