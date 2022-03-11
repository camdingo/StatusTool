#include "cpudataquery.h"

CpuDataQuery::CpuDataQuery() 
    :   DataQuery()
{
}

void CpuDataQuery::getData()
{
    _cpuQuery.getCPUs();

    //if we draw a single graph we only get the cache for the
    //current cpu and store it in m_singleCache
    if (!_multi)
    {
        _cpuQuery.getOrderedCpuCache(_index, _cache);
    }
    else
    {
        //if we draw a cache for all cpus then we grab all the cpu caches
        //and store the result in m_cache
        _cpuQuery.getOrderedCpusCache(_cache);
    }
}

int CpuDataQuery::getNumberOfCores()
{
    return _cpuQuery.getNumberOfCores();
}
