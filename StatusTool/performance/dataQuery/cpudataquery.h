#ifndef CPUDATAQUERY_H
#define CPUDATAQUERY_H
#include <dataQuery/dataquery.h>
#include <dataQuery/queryresource.h>

/** @brief This class is used to read cpu data for the widget
  *
  * This class subclass DataQuery absatract class, it specialize it in order
  * to read the cpu data.
  * This class performs different queryies based on two values sets in the class
  * which are L
  * \li index : defines which cpu to read if multi is off , ranges for the number
                of cores
  * \li multi : If set to on it will generate data for all the different cores plus
                the average of the cpus
                Meaning if set to on the size of the  cache will be numberOfCores +1
                the average cpus is stored at index 0
  */

class CpuDataQuery : public DataQuery
{
public:
    CpuDataQuery();
    ~CpuDataQuery(){}

    void getData();
    int getNumberOfCores();

private:
    /// The class used for general cpu query
    CpuQuery _cpu;

};

#endif // CPUDATAQUERY_H
