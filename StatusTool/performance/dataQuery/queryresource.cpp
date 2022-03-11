#include "queryresource.h"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <sstream>

CpuQuery::CpuQuery()
    :   _percent(0.0)
    ,   _cacheSize(30)
    ,   _cacheStartIndex(0)
{
    //Initializing number of cores
     _numberOfCores = sysconf(_SC_NPROCESSORS_ONLN);

     //Initializing cache vectors
     _lastTotalUser = std::vector<int>(_numberOfCores + 1,0);
     _lastTotalUserLow = std::vector<int>(_numberOfCores + 1,0);
     _lastTotalSys = std::vector<int>(_numberOfCores + 1,0);
     _lastTotalIdle = std::vector<int>(_numberOfCores + 1,0);

     _percentages = std::vector<std::vector<float> >
             (_numberOfCores + 1, std::vector<float>(_cacheSize,0));

     //Init data
     getCPUs();

}

void CpuQuery::getCPUs()
{
    //Initialize if stram
    std::ifstream filess("/proc/stat");
    std::string line;

    i = 0;

    while (std::getline(filess, line))
    {

        //loop the cores
        if (i <= _numberOfCores)
        {

            //storing the cache index
            int currCacheIndex = _cacheStartIndex-1;
            if (currCacheIndex < 0)
            {
                currCacheIndex = _cacheSize -1;
            }

            std::stringstream ss;
            //get the cpu name
            ss <<line;

            //Get different data usage
            ss >> _tempStr;
            ss >> _totalUser;
            ss >> _totalUserLow;
            ss >> _totalSys;
            ss >> _totalIdle;

            //Compute the percentage
            if (    _totalUser < _lastTotalUser[i] 
                ||  _totalUserLow < _lastTotalUserLow[i] 
                ||  _totalSys < _lastTotalSys[i] 
                ||  _totalIdle < _lastTotalIdle[i]
                )
            {
                //Overflow detection. Just skip this value.
                _percent = -1.0;
                _percentages[i][currCacheIndex] = _percent;
            }
            else
            {
                _total = (_totalUser -_lastTotalUser[i]) +
                        (_totalUserLow - _lastTotalUserLow[i]) +
                    (_totalSys - _lastTotalSys[i]);
                _percent = _total;
                _total += (_totalIdle - _lastTotalIdle[i]);

                //Check if we got a valid result
                if (_total > 0 )
                {
                    _percent /= _total;
                    _percent *= 100;
                }
                else
                {
                    _percent = 0;
                }

                //store the data in correct cache index
                _percentages[i][currCacheIndex] = _percent;
            }

            //store the data in the cache for next iteration
            _lastTotalUser[i] = _totalUser;
            _lastTotalUserLow[i] = _totalUserLow;
            _lastTotalSys[i] = _totalSys;
            _lastTotalIdle[i] = _totalIdle;

        }
        else
        {
            break;
        }

        ++i;
    }

    //loop the cache index
    ++_cacheStartIndex;
    if ( _cacheStartIndex > (_cacheSize -1))
    {
        _cacheStartIndex = 0;
    }
}

void CpuQuery::getInstantCPU(const int &coreIDx ,
                             std::vector<std::vector<float> > &cache)
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(1);

    //store the data in the cache if ithe core idx is a valid index
    if (coreIDx <= _numberOfCores +1)
        cache[0][0] = _percentages[coreIDx][_cacheStartIndex];

    else
        cache[0][0] = -1;
}

void CpuQuery::getAllInstantCPUs(std::vector<std::vector<float> >& cache)
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(_numberOfCores + 1);

    //store correct data
    for (int i = 0; i < _numberOfCores + 1; ++i)
    {
        cache[0][i] = _percentages[i][_cacheStartIndex];
    }
}

const std::vector<float>& CpuQuery::getCpuCache(const int &coreIDx)
{
    return _percentages[coreIDx];
}

void CpuQuery::getOrderedCpuCache(const int &coreIDx , std::vector<std::vector<float> > &cache )
{
    //resize incoming cache
    cache.resize(1);
    cache[0].resize(_cacheSize);

    //reorder wanted cache and store it correctly in the target cache
    reorderCache(_percentages[coreIDx] , cache[0]);
}

void CpuQuery::getOrderedCpusCache(std::vector<std::vector<float> > &cache)
{
    //resize incoming cache
    cache.resize(_numberOfCores + 1);
    for (int j = 0 ; j < _numberOfCores + 1; ++j)
    {
        cache[j].resize(_cacheSize);
        reorderCache(_percentages[j] , cache[j]);
    }
}

void CpuQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
    //let s make a copy of the internal start index so we can use it to loop it
    int tempIndex = _cacheStartIndex - 1;
    //loop cache size
    for (i = 0; i < _cacheSize; ++i)
    {
        target[i] = source[tempIndex];
        ++tempIndex;

        if (tempIndex > (_cacheSize - 1))
        {
            tempIndex = 0;
        }
    }

}

int CpuQuery::getNumberOfCores()
{
    return sysconf(_SC_NPROCESSORS_ONLN);
}


MemoryQuery::MemoryQuery() 
    :   _memoryUnit(GIGA_BYTE) 
    ,   _cacheSize(30)
    ,   _cacheStartIndex(0)

{
    _cache.resize(_cacheSize);
}

float MemoryQuery::getTotalMem()
{
    long bytes = sysconf( _SC_PHYS_PAGES) * sysconf( _SC_PAGESIZE );
    return convertMemory(bytes);
}



float MemoryQuery::getUsedMem()
{
    long bytes =    (sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE))
                -   (sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE));

    return convertMemory(bytes);
}


float MemoryQuery::getFreeMemory()
{
    long bytes = sysconf( _SC_AVPHYS_PAGES) * sysconf( _SC_PAGESIZE );
    return convertMemory(bytes);
}


float MemoryQuery::getMemoryUsage()
{
    float percentage = float(getUsedMem())/getTotalMem()*100.0f;
    int currCacheIndex = _cacheStartIndex-1;
    if (currCacheIndex < 0)
    {
        currCacheIndex = _cacheSize - 1;
    }
    
    _cache[currCacheIndex] = percentage;

    //loop the cache index
    ++_cacheStartIndex;
    if ( _cacheStartIndex > (_cacheSize -1))
    {
        _cacheStartIndex = 0;
    }

    return percentage;
}

float MemoryQuery::convertMemory( long bytes)
{
    float toReturn = 0;
    switch(_memoryUnit)
    {
        case 0:
            toReturn = float(bytes) / MEGA_BYTE_MULT;
            break;
        case 1:
            toReturn = float(bytes) / GIGA_BYTE_MULT;
            break;

    }

    return toReturn;
}


const std::vector<float>&  MemoryQuery::getMemoryUsageCache()
{
    return _cache;
}

void MemoryQuery::getOrderedMemoryUsageCache(std::vector<float>  &cache)
{
    //resize incoming cache
    cache.resize(_cacheSize);

    //reorder wanted cache and store it correctly in the target cache
    reorderCache(_cache , cache);
}

void MemoryQuery::reorderCache(std::vector<float> &source, std::vector<float> &target)
{
    //let s make a copy of the internal start index so we can use it to loop it
    int tempIndex = int(_cacheStartIndex)-1;
    //loop cache size
    for (int i = 0 ; i < _cacheSize; ++i)
    {

        target[i] = source[tempIndex];
        ++tempIndex;

        if ( tempIndex > (_cacheSize-1 ))
        {
            tempIndex = 0;
        }
    }
}
