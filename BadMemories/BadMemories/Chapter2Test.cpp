#include "pch.h"
#include "StringChapter2.h"
#include <string>
#include <vector>
using namespace std;

/// Chapter2-1
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理は下記テストコードの指定範囲に実装すること。
/// 適宜関数化または、クラス化すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// C++で実装すること。C標準ライブラリ・Win32APIは使用不可。
TEST(Chapter2, _1_EditStringCPP) {
	string expect;
	{//ここから変更可
		StringChapter2 stringChapter2;
		expect = stringChapter2.Replace("Japan?", 5, 10).GetString();
	}//ここまで変更可

	EXPECT_STREQ(expect.c_str(), "HelloJapan?");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}


/// Chapter2-2
/// 文字列、HelloWorld!をByeWorld!に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理は下記テストコードの指定範囲に実装すること。
/// 適宜関数化または、クラス化すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// C++で実装すること。C標準ライブラリ・Win32APIは使用不可。
TEST(Chapter2, _2_EditStringCPP) {
	string expect;
	{//ここから変更可
	}//ここまで変更可

	EXPECT_EQ(expect.c_str(), "ByeWorld!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}

/// Chapter2-3
/// 文字列、HelloWorld!をHello!World!に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理は下記テストコードの指定範囲に実装すること。
/// 適宜関数化または、クラス化すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// C++で実装すること。C標準ライブラリ・Win32APIは使用不可。
TEST(Chapter2, _3_EditStringCPP) {
	string expect;
	{//ここから変更可
	}//ここまで変更可

	EXPECT_EQ(expect.c_str(), "Hello!World!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}