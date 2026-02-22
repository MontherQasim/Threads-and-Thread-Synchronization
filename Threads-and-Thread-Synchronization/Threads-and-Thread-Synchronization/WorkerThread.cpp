#include "pch.h"
#include "WorkerThread.h"

static unsigned long long CalculateFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * CalculateFactorial(n - 1);
}

UINT FactorialWorkerThread(LPVOID pParam)
{
    FactorialThreadData* pData = static_cast<FactorialThreadData*>(pParam);

    if (pData->nInput > 40 || pData->nInput < 0)
    {
        delete pData;
        return 0;
    }

    unsigned long long result = CalculateFactorial(pData->nInput);

    delete pData;
    return 0;
}