#pragma once

#define CRT_MEM_CHECK CrtMemDiffChecker __CrtMemDiffChecker__;

class CrtMemDiffChecker
{
public:
	CrtMemDiffChecker();
	~CrtMemDiffChecker();
private:
	_CrtMemState memStateBegin;
};

