#include "pch.h"
#include "WorkerThread.h"

static unsigned long long CalculateFactorial(int n, volatile LONG* pContinue)
{
    if (*pContinue == 0)
        return -1;
    if (n <= 1)
        return 1;
    return n * CalculateFactorial(n - 1, pContinue);
}

UINT FactorialWorkerThread(LPVOID pParam)
{
    FactorialThreadData* pData = static_cast<FactorialThreadData*>(pParam);

    if (!pData)
        return 0;

    if (pData->nInput > 40 || pData->nInput < 0 || !pData->pContinue || *(pData->pContinue))
    {
        delete pData;
        return 0;
    }
    unsigned long long result = CalculateFactorial(pData->nInput, pData->pContinue);

    delete pData;
    return 0;
}