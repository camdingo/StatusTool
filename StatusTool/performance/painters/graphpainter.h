#ifndef GRAPHPAINTER_H
#define GRAPHPAINTER_H

#include "performancepainter.h"

class GraphPainter : public PerformancePainter
{
public:
    GraphPainter(QPaintDevice * widget);
    ~GraphPainter(){}

    void paint();
};

#endif // GRAPHPAINTER_H
