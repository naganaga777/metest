#include "pch.h"
#include "CrtMemDiffChecker.h"


CrtMemDiffChecker::CrtMemDiffChecker()
{
	_CrtMemCheckpoint(&memStateBegin);
}


CrtMemDiffChecker::~CrtMemDiffChecker()
{
	_CrtMemState memStateEnd;
	_CrtMemCheckpoint(&memStateEnd);

	_CrtMemState memStateDiff;
	EXPECT_EQ(0, _CrtMemDifference(&memStateDiff, &memStateBegin, &memStateEnd));
	// else just do this to dump the leaked blocks to stdout.
	if (_CrtMemDifference(&memStateDiff, &memStateBegin, &memStateEnd)) {
		_CrtMemDumpStatistics(&memStateDiff);
	}
}
