#include "pch.h"
#include <string.h>
#include "StringEditCStyle.h"

/// <summary>
/// �������u�����郁�\�b�h
/// </summary>
/// <param name="srcChar">�����������̕�����</param>
/// <param name="desChar">�u�����镶����</param>
/// <param name="startIndex">�u��������������̍ŏ��̃C���f�b�N�X</param>
/// <param name="endIndex">�u��������������̍Ō�̃C���f�b�N�X</param>
void Replace(char srcChar[], char desChar[], int startIndex, int endIndex)
{

	int count = 0;
	desChar[sizeof(desChar) - 1] = '\0';
	for (int currentIndex = startIndex; currentIndex <= endIndex; ++currentIndex)
	{
		if ('\0' == desChar[count])
		{
			Erase(srcChar, count, endIndex);
			break;
		}
		srcChar[currentIndex] = desChar[count];
		count++;
	}
	/*[�����Q]
	char inStr[] = "HelloWorld!";//�z��̐擪�|�C���^��n���ƁA��O�͔������Ȃ�
	char inStr = "HelloWorld!";//�|�C���^���ƃA�N�Z�X�ᔽ����������
	[����]
	�_�u���N�H�[�e�[�V����""�ň͂܂ꂽ������𕶎��񃊃e�����Ƃ����B
	�����񃊃e�����́A�v���O�����̎��s�J�n���ɓ���ȗ̈�ɕ�����z��Ƃ��Ċm�ۂ����B
	���̃������̈�́A�X�^�b�N��q�[�v�Ƃ͕ʂ̗̈�ŁA���e�̏����������ł��Ȃ��̈�ł���B
	�������ݕt���̗̈�ɁA�������݂��s�����Ƃ��Ă����̂ŁA�A�N�Z�X�ᔽ�ŗ�O�����ł����B

	[�΍�]
	�s����o���Ȃ����߂ɁAchar*�ŕ����񃊃e������錾����Ƃ��́A const char* �Ƃ��ď���������B
	const �C�����Ă����΁A�R���p�C���ŋC�Â���B
	*/
}

/// <summary>
/// ������z��̓���͈͂̃C���f�b�N�X���폜
/// </summary>
/// <param name="srcChar">������z��</param>
/// <param name="startIndex">�폜�Ώۂ̍ŏ��̃C���f�b�N�X</param>
/// <param name="endIndex">�폜�Ώۂ̍Ō�̃C���f�N�X</param>
void Erase(char srcChar[], int startIndex, int endIndex)
{
	int currentIndex = startIndex;
	int eraseIndex = startIndex;
	while (endIndex >= currentIndex)
	{
		Erase(srcChar, eraseIndex);
		currentIndex++;
	}
}


/// <summary>
/// ������z��̓���̃C���f�b�N�X���폜
/// </summary>
/// <param name="srcChar">������z��</param>
/// <param name="index">�폜�Ώۂ̃C���f�b�N�X</param>
void Erase(char srcChar[], int index)
{
	int currentIndex = index;
	while ('\0' != srcChar[currentIndex++])
	{
		srcChar[currentIndex - 1] = srcChar[currentIndex];
	}
}

/// <summary>
/// ������z��ɕ�����}������֐�
/// </summary>
/// <param name="srcChar">�}����̕�����z��</param>
/// <param name="indeX">�}������C���f�N�X</param>
/// <param name="insertChar">�}�����镶��</param>
/// <returns>������z��̐擪�|�C���^</returns>
char* Insert(char srcChar[], int indeX, char insertChar)
{
	char retCharArray[256] ="";
	Copy(srcChar, retCharArray);//�R�s�[

	retCharArray[indeX] = insertChar;
	int currentIndex = indeX;
	while ('\0' != srcChar[currentIndex])
	{
		currentIndex++;
		retCharArray[currentIndex] = srcChar[currentIndex - 1];
	}
	return retCharArray;
}

/// <summary>
/// ������z����R�s�[����֐�
/// DeepCopy�ŎQ�Ɛ悲�ƕς���
/// </summary>
/// <param name="srcChar">�R�s�[���̕�����z��</param>
/// <param name="desChar">�R�s�[��̕�����z��iout�j</param>
void Copy(char srcChar[], char desChar[])
{
	int currentIndex = 0;
	while ('\0' != srcChar[currentIndex])
	{
		desChar[currentIndex]= srcChar[currentIndex];
		currentIndex++;
	}
}


/// <summary>
/// ������AHelloWorld!��HelloJapan?�ɕϊ�����B
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
/// </summary>
/// <param name="ioString">�ϊ��O��̕�����</param>
char* HelloWorldToHelloJapan(char ioString[])
{
	char tmp[256] = "Japan?";
	int startIndex = 5;
	int endIndex = 10;
	Replace(ioString, tmp, startIndex, endIndex);
	return ioString;
}

/// <summary>
/// ������AHelloWorld!��ByeWorld!�ɕϊ�����B
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
/// </summary>
/// <param name="ioString">�ϊ��O��̕�����</param>
char* HelloWorldToByeWorld(char ioString[])
{
	//char byeChar[] = "Bye"; �ˁ@HelloWorldToByeWorld�𔲂����Ƃ���Stack around the variable 'xxx' was corrupted.�̗�O�������B
	char byeChar[10] = "Bye";
	int startIndex = 0;
	int endIndex = 4;
	Replace(ioString, byeChar, startIndex, endIndex);
	return ioString;
}

/// <summary>
/// ������AHelloWorld!��Hello!World!�ɕϊ�����B
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
/// </summary>
/// <param name="ioString">�ϊ��O��̕�����</param>
char* HelloWorldToHelloWorld(char ioString[])
{
	char insertChar = '!';
	int insertIndex = 5;
	return Insert(ioString, insertIndex, insertChar);
}
