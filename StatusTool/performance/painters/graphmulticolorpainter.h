#ifndef GRAPHMULTICOLORPAINTER_H
#define GRAPHMULTICOLORPAINTER_H

#include "performancepainter.h"


class GraphMultiColorPainter : public PerformancePainter
{
public:

    GraphMultiColorPainter(QPaintDevice * widget);

    ~GraphMultiColorPainter(){}

    /// Reimplemented paint function
    void paint();

private:
    ///This procedrue checks that we have enough color to produce the graph
    void checkColors();


private :
    //List of colors used for the graph
    std::vector<QColor> _colors;

    //Constant for the color range
    static const int COLOR_RANGE = 255;

    //Constant for the minimum legend with, this is whats the minimum space required for each
    // number of the legend
    static const int MIN_LEGEND_WIDTH = 30;


};



#endif // GRAPHMULTICOLORPAINTER_H
