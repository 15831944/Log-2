#pragma once
class CLogComm
{
public:
	CLogComm();

	/// <summary>
	/// ファイル名に禁止文字が使用されていないかを確認
	/// </summary>
	/// <param name="pszFileName">ログ出力先ファイル名に使用する</param>
	/// <return>TRUE：禁止文字なし FALSE：禁止文字あり</return>
	BOOL CheckFileName(char cFileName[_MAX_FNAME] );
	
	/// <summary>
	/// ログ出力用日時の取得
	/// </summary>
	/// <return>日時</return>
	CString GetTime();
};

