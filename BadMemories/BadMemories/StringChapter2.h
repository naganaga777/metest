#pragma once
#include <string>
#include <vector>
using namespace std;

class StringChapter2
{
public:
	StringChapter2();
	StringChapter2(string inputString);
	//~StringChapter2();

	StringChapter2 Replace(string desStr, int startIndex, int endIndex);

public:
	string GetString()
	{
		return m_string;
	}
private:
	 string m_string;


};

