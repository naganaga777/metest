#include "pch.h"
#include "CrtMemState.h"


CrtMemState::CrtMemState()
{
	Now();
}


CrtMemState::~CrtMemState()
{
}

void CrtMemState::Now()
{
	_CrtMemCheckpoint(&memState);
}

CrtMemState CrtMemState::operator-(const CrtMemState & inRhs) const
{
	CrtMemState diff;
	_CrtMemDifference(&(diff.memState), &(this->memState), &(inRhs.memState));
	return diff;
}

bool CrtMemState::operator==(const CrtMemState & inRhs) const
{
	CrtMemState diff;
	return 0 == _CrtMemDifference(&(diff.memState), &(this->memState), &(inRhs.memState));
}

std::stringstream CrtMemState::dump;

/// <summary> CRTメモリ検知イベントハンドラ </summary>
/// <param name="reportType"> 処理タイプ </param>
/// <param name="message"> CRTからの出力メッセージ </param>
/// <param name="returnValue">  </param>
/// <returns> TRUE: _CrtSetReportHookを呼び出さない, FALSE: 呼び出す  </returns>
int CrtMemState::YourReportHook(int reportType, char * message, int * returnValue)
{
	switch (reportType)
	{
	case _CRT_ASSERT:
	{
		break;
	}
	case _CRT_WARN:
	{
		// メモリリークの場合は。ここで、自分のログ出力関数でファイル出力すれば良い。
		// このサンプルではコンソールに出力する。
		dump << message;
		break;
	}
	case _CRT_ERROR:
	{
		// assert等が呼ばれた場合
		break;
	}
	default:
	{
		break;
	}
	}

	// FALSEを返すと_CrtSetReportHookで登録したハンドラを呼び出す。
	return FALSE;
}
