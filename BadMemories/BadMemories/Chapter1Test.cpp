#include "pch.h"

#include "StringEditCStyle.h"
using namespace std;



/// Chapter1-1
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理はHelloWorldToHelloJapan()に実装すること。
/// HelloWorldToHelloJapanのI/F（引数・戻り）は適宜変更してよい。
/// 下記テストコードの指定範囲は適宜変更すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
TEST(Chapter1, _1_EditStringC) {
	char* helloworld = nullptr;
	{//ここから変更可
		char inStr[] = "HelloWorld!";//配列の先頭ポインタを渡すと、例外は発生しない
		//char inStr = "HelloWorld!";//ポインタだとアクセス違反が発生する 
		helloworld = HelloWorldToHelloJapan(inStr);

	}//ここまで変更可

	EXPECT_STREQ(helloworld, "HelloJapan?");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');

	/*
	[メモ１]
	EXPECT_EQはポインタの比較。「アドレス」と「型」
	*/
}


/// Chapter1-2
/// 文字列、HelloWorld!をByeWorld!に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理はHelloWorldToByeWorld()に実装すること。
/// HelloWorldToByeWorldのI/F（引数・戻り）は適宜変更してよい。
/// 下記テストコードの指定範囲は適宜変更すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
TEST(Chapter1, _2_EditStringC) {
	char* helloworld = nullptr;
	{//ここから変更可
		char inStr[] = "HelloWorld!";
		helloworld = HelloWorldToByeWorld(inStr);
	}//ここまで変更可

	//EXPECT_EQ(helloworld, "ByeWorld!");
	EXPECT_STREQ(helloworld, "ByeWorld!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}

/// Chapter1-3
/// 文字列、HelloWorld!をHello!World!に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理はHelloWorldToHelloWorld()に実装すること。
/// HelloWorldToHelloWorldのI/F（引数・戻り）は適宜変更してよい。
/// 下記テストコードの指定範囲は適宜変更すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
TEST(Chapter1, _3_EditStringC) {
	char* helloworld = nullptr;
	{//ここから変更可
		HelloWorldToHelloJapan(helloworld);
	}//ここまで変更可

	EXPECT_EQ(helloworld, "Hello!World!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}