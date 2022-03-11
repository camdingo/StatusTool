#ifndef RAMWIDGET_H
#define RAMWIDGET_H

#include <widgets/performancewidget.h>
#include <dataQuery/ramdataquery.h>

class RamWidget : public PerformanceWidget
{
public :
    /// Constants defining the draw mode
    enum DRAW_MODE
    {
        /// Draw the data as bar/s
        DRAW_BARS = 0,
        /// Draw the data as graph/s
        DRAW_GRAPH = 1
    };


public:
    RamWidget(QWidget *parent);
    ~RamWidget();

    void setDisplayMode(const DRAW_MODE mode);
private:
    RamDataQuery _dataQuery;
    BarsPainter *_barsP;
    GraphPainter *_graphP;
    int _displayMode;
};

#endif // RAMWIDGET_H
