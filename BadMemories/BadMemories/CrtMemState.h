#pragma once

#include <fstream>
#include <sstream>

class CrtMemState
{
public:
	CrtMemState();
	~CrtMemState();
	void Now();
	CrtMemState operator- (const CrtMemState& inRhs) const;
	bool operator== (const CrtMemState& inRhs) const;
public:
	_CrtMemState memState;
	static std::stringstream dump;
	static int YourReportHook(int reportType, char *message, int *returnValue);
};


template<class _Elem, class _Traits>
std::basic_ostream< _Elem, _Traits >& operator << (
	std::basic_ostream< _Elem, _Traits >& stream,
	const CrtMemState& inRhs)
{
	//0 bytes in 0 Free Blocks.
	//400 bytes in 1 Normal Blocks.
	//0 bytes in 0 CRT Blocks.
	//0 bytes in 0 Ignore Blocks.
	//0 bytes in 0 Client Blocks.
	//Largest number used : 0 bytes.
	//Total allocations : 400 bytes.

	//std::stringbuf  buf;                          // stringstream—p‚Ìstreambuf
	//std::streambuf* prev = std::cout.rdbuf(&buf); // streambuf‚ð‚·‚°‚©‚¦‚é

	//cout << "test";
	//std::cout.rdbuf(prev);                        // streambuf‚ðŒ³‚É–ß‚·

	//stream << buf.str();

	//_CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, YourReportHook);
	CrtMemState::dump.clear();

	_CrtSetReportHook2(_CRT_RPTHOOK_INSTALL, CrtMemState::YourReportHook);
	//_CrtSetReportHookW2(_CRT_RPTHOOK_INSTALL, CrtMemState::YourReportHook);

	_CrtMemDumpStatistics(&(inRhs.memState));

	_CrtSetReportHook2(_CRT_RPTHOOK_REMOVE, CrtMemState::YourReportHook);
	//_CrtSetReportHookW2(_CRT_RPTHOOK_REMOVE, CrtMemState::YourReportHook);

	//FILE* fp = std::freopen("temp.txt", "w", stderr);

	//printf("test");
	//_CrtMemDumpStatistics(&(inRhs.memState));


	//std::fclose(fp);
	//std::freopen("con", "w", stderr);

	//string temp;
	//{
	//	std::ifstream ifs("temp.txt");
	//	ifs >> temp;
	//}
	//std::remove("temp.txt");

	return stream << CrtMemState::dump.str();
}