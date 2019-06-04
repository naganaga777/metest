#include "pch.h"

#include <string>
#include "CrtMemDiffChecker.h"

using namespace std;

class base1
{
	int member1 = 100;

public:
	virtual int getMember() const { return member1; }
};

class sub1 : public base1
{
	int member2[2] = { 101, 102 };

public:
	int getMember() const { return member2[1]; }
};

class sub2 : public base1
{
	int* member3 = nullptr;

public:
	sub2() { member3 = new int(103); }
	~sub2() { delete member3; }
	int getMember() const { return *member3; }
};

class sub3 : public base1
{
	long member4 = 104;

public:
	int getMember() const { return member4; }
};



TEST(Chapter5, _1) {
	CRT_MEM_CHECK; //‚±‚Ìs‚ÍC³‹Ö~

	sub1 tempA;

	auto getMem1 = [](const base1 a) { return a.getMember(); };

	ASSERT_EQ(tempA.getMember(), getMem1(tempA));
}

TEST(Chapter5, _2) {
	CRT_MEM_CHECK; //‚±‚Ìs‚ÍC³‹Ö~

	sub2 tempA;

	auto getMem1 = [](const base1 a) { return a.getMember(); };

	ASSERT_EQ(tempA.getMember(), getMem1(tempA));
}

//TEST(Chapter5, _3) {
//	CRT_MEM_CHECK; //‚±‚Ìs‚ÍC³‹Ö~
//
//	sub3 tempA;
//
//	auto getMem1 = [](const base1 a) { return a.getMember(); };
//
//	ASSERT_EQ(tempA.getMember(), getMem1(tempA));
//}

TEST(Chapter5, _4) {
	CRT_MEM_CHECK; //‚±‚Ìs‚ÍC³‹Ö~

	sub2 tempA;

	auto getMem1 = [](const sub2 a) { return a.getMember(); };

	ASSERT_EQ(tempA.getMember(), getMem1(tempA));
}
