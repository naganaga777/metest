#include "pch.h"

#include "StringEditCStyle.h"




/// Chapter1-1
/// 文字列、HelloWorld!をHelloJapan?に変換する。
/// 本テストをパスするコードを実装する。
/// 変換処理はHelloWorldToHelloJapan()に実装すること。gsgmgms
/// HelloWorldToHelloJapanのI/F（引数・戻り）は適宜変更してよい。
/// 下記テストコードの指定範囲は適宜変更すること。
/// Inputの文字列がHelloWorld!であることは前提としてよい。
/// Cの範囲で実装すること。C標準ライブラリ・Win32APIは使用可。
TEST(Chapter1, _1_EditStringC) {
	char* helloworld = nullptr;
	{//ここから変更可
		helloworld = "HelloWorld!";
		HelloWorldToHelloJapan(helloworld);
	}//ここまで変更可

	EXPECT_EQ(helloworld, "HelloJapan?");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
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
		HelloWorldToHelloJapan(helloworld);
	}//ここまで変更可

	EXPECT_EQ(helloworld, "ByeWorld!");
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