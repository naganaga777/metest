#include "pch.h"
#include "StringChapter2.h"

/// <summary>
/// �f�t�H���g�R���X�g���N�^
/// </summary>
StringChapter2::StringChapter2()
{
	//m_string= new string("HelloWorld!");
	m_string = "HelloWorld!";
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
StringChapter2::StringChapter2(string inputString)
{
	//this->m_string = new string;
	m_string = inputString;
}

/// <summary>
/// ������̒u��
/// ��Replace�̃��b�p�[
/// </summary>
/// <param name="desStr"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
/// <returns></returns>
StringChapter2 StringChapter2::Replace(string desStr,int startIndex, int endIndex)
{
	string srcStr = this->GetString();
	srcStr.replace(startIndex, endIndex, desStr);

	return StringChapter2(srcStr);

}
