/****************************************************/
/* Lesson2 - main.cpp                               */
/* main.cppとは別のファイルに関数定義を分離する     */
/****************************************************/

#include "iostream"
#include "MySquare.h"

//
// エントリポイント
//
int main(void)
{
	std::cout << mySquare(2) << std::endl;

	return 0;
}

