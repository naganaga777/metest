#include "pch.h"
#include <string.h>
#include "StringEditCStyle.h"

/// <summary>
/// 
/// </summary>
/// <param name="srcChar"></param>
/// <param name="desChar"></param>
/// <param name="startIndex"></param>
/// <param name="endIndex"></param>
void Replace(char srcChar[], char desChar[], int startIndex, int endIndex)
{
	int count = 0;
	for (int index = startIndex; index <= endIndex; ++index)
	{
		srcChar[index] = desChar[count];
		count++;
	}
	/*[メモ２]
	char inStr[] = "HelloWorld!";//配列の先頭ポインタを渡すと、例外は発生しない
	char inStr = "HelloWorld!";//ポインタだとアクセス違反が発生する 
	[原因]
	ダブルクォーテーション""で囲まれた文字列を文字列リテラルという。
	文字列リテラルは、プログラムの実行開始時に特殊な領域に文字列配列として確保される。
	このメモリ領域は、スタックやヒープとは別の領域で、内容の書き換えができない領域である。
	書き込み付加の領域に、書き込みを行おうとしていたので、アクセス違反で例外が飛んでいた。

	[対策]
	不具合を出さないために、char*で文字列リテラルを宣言するときは、 const char* として初期化する。
	const 修飾しておけば、コンパイルで気づける。
	*/
}

/// <summary>
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
char* HelloWorldToHelloJapan(char ioString[])
{
	char tmp[] = "Japan?";
	int startIndex = 5;
	int endIndex = 10;
	Replace(ioString, tmp, startIndex, endIndex);
	return ioString;
}

/// <summary>
/// 文字列、HelloWorld!をByeWorld!に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
char* HelloWorldToByeWorld(char* ioString)
{
	char tmp[] = "Bye";
	int startIndex = 0;
	int endIndex = 10;
	Replace(ioString, tmp, startIndex, endIndex);
	return ioString;
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
