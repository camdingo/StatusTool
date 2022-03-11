#include "dataquery.h"

DataQuery::DataQuery()
    :   _index(0)
    ,   _multi(0)
{
}


void DataQuery::setIndex(int index)
{
    _index = index;
}

void DataQuery::setMulti( bool value)
{
    _multi = value;
}

