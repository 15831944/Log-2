#pragma once





struct TLogInfo
{
public:
	CString csLogTime; // ���O����
	CString csLogLevel; // ���O���x��
	CString csSourceFileName; // �\�[�X�t�@�C����
	int nSoourceLine; // �s��
	CString csFunctionName; // �֐���
	CString csLogText; // ���O���e
	int nIndex; // �C���f�b�N�X
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
	// �R���X�g���N�^
	CLogInfo(wchar_t cDirPath[MAX_PATH], wchar_t cLogFileName[_MAX_FNAME], int nFormatType);

	/// <summary>
	/// �����o�ϐ��ɃC���f�b�N�X��ݒ�
	/// </summary>
	/// <param name="nIndex">�o�^����C���f�b�N�X�Ɏg�p</param>
	/// <return></return>
	void SetIndex(int nIndex);

	/// <summary>
	/// �����o�ϐ��̃C���f�b�N�X���擾
	/// </summary>
	/// <return>�o�^�����C���f�b�N�X</return>
	int GetIndex();


	/// <summary>
	/// �����o�ϐ��̏o�͐�e�t�H���_�̃p�X��ݒ�
	/// </summary>
	/// <param name="nIndex">�o�͐�e�t�H���_�̃p�X</param>
	/// <return></return>
	void SetDirPath(CString csDirPath);

	CString GetDirPath();

	/// <summary>
	/// �����o�ϐ��̏o�͐�e�t�H���_�̃p�X��ݒ�
	/// </summary>
	/// <param name="nIndex">�o�͐�e�t�H���_�̃p�X</param>
	/// <return></return>
	void SetLogFileName(CString cLogFileName);

	CString GetLogFileName();

	// �����o�[�ϐ�
	CString m_csDirPath; // ���O�o�͐�e�t�H���_�p�X
	CString m_csLogFileName; // ���O�o�͐�t�@�C����
	int m_nFormatType;
};
