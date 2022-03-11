#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <widgets/performancewidget.h>

#include <dataQuery/cpudataquery.h>

#include <painters/barspainter.h>
#include <painters/graphmulticolorpainter.h>
#include <painters/graphpainter.h>

class CpuWidget : public PerformanceWidget
{
    Q_OBJECT

public :

    enum DRAW_MODE
    {
        DRAW_BARS = 0,
        DRAW_GRAPH = 1,
        DRAW_GRAPH_MULTI_COLOR = 2
    };

    CpuWidget(QWidget *parent);
    ~CpuWidget();

    void setDisplayMode(const DRAW_MODE mode);
    void setMulti(bool value);
    void setIndex(int value);

private :
    CpuDataQuery _dataQuery;

    BarsPainter *_barsP;
    GraphPainter *_graphP;
    GraphMultiColorPainter *_multiP;

    int _displayMode;
    bool _multi;
    int _index;

};

#endif // CPUWIDGET_H
