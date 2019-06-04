/****************************************************/
/* Lesson1 - main.cpp                               */
/* 処理を関数に分離してみよう                       */
/****************************************************/

#include "iostream"

//
// mySquareメソッドのプロトタイプ宣言
// 入力値の2乗を返す
//
int mySquare(int in_val);

//
// エントリポイント
//
int main(void)
{
	std::cout << mySquare(2) << std::endl;
	
	return 0;
}


//
// mySquareメソッドの定義
//
int mySquare(int in_val)
{
	return (in_val * in_val);
}

