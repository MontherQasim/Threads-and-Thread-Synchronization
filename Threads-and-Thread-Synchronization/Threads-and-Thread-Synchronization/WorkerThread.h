#pragma once

#define WM_FACTORIAL_COMPLETE (WM_USER + 1)

struct FactorialThreadData
{
    int nInput;
    CWnd* pNotifyWnd;
};

UINT FactorialWorkerThread(LPVOID pParam);