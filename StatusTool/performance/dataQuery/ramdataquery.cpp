#include "ramdataquery.h"

RamDataQuery::RamDataQuery()
{
    m_cache.resize(1);
}

void RamDataQuery::getData()
{
    _mem.getMemoryUsage();
    _mem.getOrderedMemoryUsageCache(m_cache[0]);
}
