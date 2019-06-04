#include "pch.h"

#include <string>
#include "CrtMemState.h"
#include "CrtMemDiffChecker.h"

using namespace std;

string* newString1()
{
	return new string("100");
}

/// Chapter3-1
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter3, _1)）に対し行うこと。
/// newString1()は修正禁止
TEST(Chapter3, _1) {
	CRT_MEM_CHECK; //この行は修正禁止

	string* str = newString1();
}

string* newString2()
{
	return new string[100];
}

/// Chapter3-2
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter3, _2)）に対し行うこと。
/// newString2()は修正禁止
TEST(Chapter3, _2) {
	CRT_MEM_CHECK; //この行は修正禁止

	string* str = newString2();
	delete str;
}

string* newString3()
{
	string temp("100");
	return &temp;
}

/// Chapter3-3
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter3, _3)）/newString3()に対し行うこと。
TEST(Chapter3, _3) {
	CRT_MEM_CHECK; //この行は修正禁止
	string* str = newString3();
	delete str;
}

shared_ptr<string> newString4()
{
	return shared_ptr<string>(new string[100]);
}

/// Chapter3-4
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter3, _4)）/newString4()に対し行うこと。
TEST(Chapter3, _4) {
	CRT_MEM_CHECK; //この行は修正禁止
	shared_ptr<string> str = newString4();
}

unique_ptr<string> newString5()
{
	return unique_ptr<string>(new string[100]);
}

/// Chapter3-5
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter3, _5)）/newString5()に対し行うこと。
TEST(Chapter3, _5) {
	CRT_MEM_CHECK; //この行は修正禁止
	unique_ptr<string> str = newString5();
}
