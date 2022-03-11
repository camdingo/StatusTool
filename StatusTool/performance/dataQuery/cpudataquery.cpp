#include "cpudataquery.h"

CpuDataQuery::CpuDataQuery() 
    :   DataQuery()
{
}

void CpuDataQuery::getData()
{
    _cpu.getCPUs();

    //if we draw a single graph we only get the cache for the
    //current cpu and store it in m_singleCache
    if (_multi == 0)
    {
        _cpu.getOrderedCpuCache(_index, _cache);
    }
    //if we draw a cache for all cpus then we grab all the cpu caches
    //and store the result in m_cache
    else
    {
        _cpu.getOrderedCpusCache(_cache);
    }
}

int CpuDataQuery::getNumberOfCores()
{
    return _cpu.getNumberOfCores();

}
