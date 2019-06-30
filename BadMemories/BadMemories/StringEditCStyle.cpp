#include "pch.h"
#include <string.h>
#include "StringEditCStyle.h"


/// <summary>
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
char* HelloWorldToHelloJapan(char* ioString)
{

	char* retStr=nullptr;
	retStr = strtok(ioString, "W");
	char* strJapan = "Japan?";
	strcat(retStr, strJapan);
	return retStr;
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
