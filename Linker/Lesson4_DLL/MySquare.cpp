/**********************************************************/
/* Lesson4 - MySquare.cpp                                 */
/* 関数をDLLに分離してみよう                              */
/**********************************************************/
//#define MYSQUARE_EXPORTS

#include "MySquare.h"

//
// mySquareメソッドの定義
//
int __stdcall mySquare(int in_val)
{
	return (in_val * in_val * in_val);      // ver1.0
	//return (in_val * in_val);             // ver1.1(bug fix)
}
