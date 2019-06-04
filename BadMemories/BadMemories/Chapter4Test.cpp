#include "pch.h"

#include <string>

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


TEST(Chapter4, _1) {
	string str = "100";

	string* str2 = ReallocString(&str);

	delete str2;
}


TEST(Chapter4, _2) {
	string* str1 = new string("100");

	string* str2 = ReallocString(str1);

	str2->append("101");

	cout << *str1 << endl;
	cout << *str2 << endl;

	ASSERT_EQ("100", *str1);
	ASSERT_EQ(*str2, "100101");
}

