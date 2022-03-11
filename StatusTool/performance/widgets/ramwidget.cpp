#include "ramwidget.h"

RamWidget::RamWidget(QWidget *parent) 
    :   PerformanceWidget(parent)
    ,   _dataQuery(RamDataQuery())
{
    //Set what data quary we want
    setDataQuery(&_dataQuery);

    //Let s initialize all the painters
    _graphP = new GraphPainter(this);
    _barsP =  new BarsPainter(this);

    //Initialize painter
    setDisplayMode(DRAW_BARS);
}

void RamWidget::setDisplayMode(const DRAW_MODE mode)
{
    _displayMode = mode;

    switch (_displayMode) 
    {
        case 0:
        {
            setPainter(_barsP);
            break;
        }
        case 1:
        {
            setPainter(_graphP);
            break;
        }
    }
}


RamWidget::~RamWidget()
{
    delete _graphP;
    delete _barsP;
}
