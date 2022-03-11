#ifndef BARSPAINTER_H
#define BARSPAINTER_H
#include <painters/performancepainter.h>

class BarsPainter : public PerformancePainter
{
public:
    BarsPainter(QPaintDevice * widget);
    ~BarsPainter(){}

    ///Reimplemented paint function
    void paint();

};


#endif // BARSPAINTER_H

