#include "pch.h"

#include <string>
#include "CrtMemState.h"
#include "CrtMemDiffChecker.h"

using namespace std;

string* newString1()
{
	return new string("100");
}

TEST(Chapter3, _1) {
	CRT_MEM_CHECK;

	string* str = newString1();
}

string* newString2()
{
	return new string[100];
}
TEST(Chapter3, _2) {
	CRT_MEM_CHECK;

	string* str = newString2();
	delete str;
}

string* newString3()
{
	string temp("100");
	return &temp;
}

TEST(Chapter3, _3) {
	CRT_MEM_CHECK;
	string* str = newString3();
	delete str;
}

shared_ptr<string> newString4()
{
	return shared_ptr<string>(new string[100]);
}

TEST(Chapter3, _4) {
	CRT_MEM_CHECK;
	shared_ptr<string> str = newString4();
}

unique_ptr<string> newString5()
{
	return unique_ptr<string>(new string[100]);
}

TEST(Chapter3, _5) {
	CRT_MEM_CHECK;
	unique_ptr<string> str = newString5();
}
