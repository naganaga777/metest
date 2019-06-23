#include "pch.h"
#include "StringEditCStyle.h"


char* ConvertString(int startIndex, int endIndex, char* ioString, char* convertString)
{

	int count = 0;
	for (int i = startIndex; i < endIndex; i++)
	{
		ioString[i] = convertString[count];//例外発生。なぜ？？
		count++;
	}
	return ioString;
}


/// <summary>
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
void HelloWorldToHelloJapan(char* ioString)
{
	//1.変換する文字列のインデックスを特定
	//2.
	char* str = "Japan?";
	char* tmp;
	ioString = ConvertString(5, 11, ioString, str);
}

/// <summary>
/// 文字列、HelloWorld!をByeWorld!に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
void HelloWorldToByeWorld(char* ioString)
{

}

/// <summary>
/// 文字列、HelloWorld!をHello!World!に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
void HelloWorldToHelloWorld(char* ioString)
{

}
