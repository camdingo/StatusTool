#ifndef DATAQUERY_H
#define DATAQUERY_H
#include <iostream>
#include <stdio.h>
#include <vector>

class DataQuery
{
public:
    DataQuery();
    virtual ~DataQuery(){}

    virtual void getData(){}

    void setIndex(int index) { _index = index; }
    void setMulti(bool multi) { _multi = multi; }


public:
    int _index;
    bool _multi;

    /// The cache used to store all the data
    std::vector<std::vector<float> > _cache;
};

#endif // DATAQUERY_H
