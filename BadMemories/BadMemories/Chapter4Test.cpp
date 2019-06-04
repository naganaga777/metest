#include "pch.h"

#include <string>
#include "CrtMemDiffChecker.h"

using namespace std;

string* ReallocString(string* inStr)
{
	string* temp = nullptr;
	if(inStr != nullptr){
		temp = new string(*inStr);
		delete inStr;
	}
	return temp;
}

/// Chapter4-1
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter4, _1)に対し行うこと。
/// ReallocString()は修正禁止
TEST(Chapter4, _1) {
	CRT_MEM_CHECK; //この行は修正禁止

	string str = "100";

	string* str2 = ReallocString(&str);

	str2->append("101");

	ASSERT_EQ("100", str);
	ASSERT_EQ(*str2, "100101");

	delete str2;
}

/// Chapter4-2
/// 本テストをパスするコードを実装する。
/// 修正はテストコード（TEST(Chapter4, _2)に対し行うこと。
/// ReallocString()は修正禁止
TEST(Chapter4, _2) {
	string* str1 = new string("100");

	string* str2 = ReallocString(str1);

	str2->append("101");

	cout << *str1 << endl;
	cout << *str2 << endl;

	ASSERT_EQ("100", *str1);
	ASSERT_EQ(*str2, "100101");
}

