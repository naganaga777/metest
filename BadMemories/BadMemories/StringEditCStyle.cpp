#include "pch.h"
#include <string.h>
#include "StringEditCStyle.h"

/// <summary>
/// 文字列を置換するメソッド
/// </summary>
/// <param name="srcChar">書き換え元の文字列</param>
/// <param name="desChar">置換する文字列</param>
/// <param name="startIndex">置換したい文字列の最初のインデックス</param>
/// <param name="endIndex">置換したい文字列の最後のインデックス</param>
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
/// 文字列配列の特定範囲のインデックスを削除
/// </summary>
/// <param name="srcChar">文字列配列</param>
/// <param name="startIndex">削除対象の最初のインデックス</param>
/// <param name="endIndex">削除対象の最後のインデクス</param>
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
/// 文字列配列の特定のインデックスを削除
/// </summary>
/// <param name="srcChar">文字列配列</param>
/// <param name="index">削除対象のインデックス</param>
void Erase(char srcChar[], int index)
{
	int currentIndex = index;
	while ('\0' != srcChar[currentIndex++])
	{
		srcChar[currentIndex - 1] = srcChar[currentIndex];
	}
}

/// <summary>
/// 文字列配列に文字を挿入する関数
/// </summary>
/// <param name="srcChar">挿入先の文字列配列</param>
/// <param name="indeX">挿入するインデクス</param>
/// <param name="insertChar">挿入する文字</param>
/// <returns>文字列配列の先頭ポインタ</returns>
char* Insert(char srcChar[], int indeX, char insertChar)
{
	char retCharArray[256] ="";
	Copy(srcChar, retCharArray);//コピー

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
/// 文字列配列をコピーする関数
/// DeepCopyで参照先ごと変える
/// </summary>
/// <param name="srcChar">コピー元の文字列配列</param>
/// <param name="desChar">コピー先の文字列配列（out）</param>
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
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
char* HelloWorldToHelloJapan(char ioString[])
{
	char tmp[256] = "Japan?";
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
char* HelloWorldToByeWorld(char ioString[])
{
	//char byeChar[] = "Bye"; ⇒　HelloWorldToByeWorldを抜けたときにStack around the variable 'xxx' was corrupted.の例外が発生。
	char byeChar[10] = "Bye";
	int startIndex = 0;
	int endIndex = 4;
	Replace(ioString, byeChar, startIndex, endIndex);
	return ioString;
}

/// <summary>
/// 文字列、HelloWorld!をHello!World!に変換する。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
/// </summary>
/// <param name="ioString">変換前後の文字列</param>
char* HelloWorldToHelloWorld(char ioString[])
{
	char insertChar = '!';
	int insertIndex = 5;
	return Insert(ioString, insertIndex, insertChar);
}
