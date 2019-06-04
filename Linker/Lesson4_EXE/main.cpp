/**********************************************************/
/* Lesson4 - main.cpp                                     */
/* 関数をDLLに分離してみよう                              */
/**********************************************************/

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
