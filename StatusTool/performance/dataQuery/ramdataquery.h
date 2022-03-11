#ifndef RAMDATAQUERY_H
#define RAMDATAQUERY_H

#include <dataQuery/queryresource.h>
#include <dataQuery/dataquery.h>

class RamDataQuery : public DataQuery
{
public:
    RamDataQuery();
    ~RamDataQuery(){}

    void getData();

private :
    /// The class used for general memory query
    MemoryQuery _mem;

};


#endif // RAMDATAQUERY_H
