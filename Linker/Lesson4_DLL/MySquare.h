/**********************************************************/
/* Lesson4 - MySquare.h                                   */
/* 関数をDLLに分離してみよう                              */
/**********************************************************/

// イキナリ感のあるキーワードが多数出てくる。
// 今は「呪文」とみなしておく。
// 興味があれば調べさせる。
//
// クラスのエクスポートは、、、知らないほうが幸せかな。
// CIPで使いまくってるけど。
#ifdef MYSQUARE_EXPORTS
#define MYSQUARE_API __declspec(dllexport)
#else
#define MYSQUARE_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

//
// mySquareメソッドの宣言
//
MYSQUARE_API
int __stdcall mySquare(int in_val);

#ifdef __cplusplus
}
#endif
