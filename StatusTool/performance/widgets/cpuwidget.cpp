#include <widgets/cpuwidget.h>

CpuWidget::CpuWidget(QWidget *parent) 
    :   PerformanceWidget(parent)
    ,   _dataQuery(CpuDataQuery())
    ,   _displayMode(DRAW_GRAPH)
    ,   _multi(true)
    ,   _index(0)

{
    //Set what data quary we want
    setDataQuery(&m_dataQuery);

    //set data query default config
    m_dataQuery.setMulti(m_multi);
    m_dataQuery.setIndex(m_index);

    //initialize all the painters
    _graphP = new GraphPainter(this);
    _multiP = new GraphMultiColorPainter(this);
    _barsP =  new BarsPainter(this);

    //Initialize painter
    setDisplayMode(DRAW_GRAPH_MULTI_COLOR);
}


void CpuWidget::setDisplayMode(const DRAW_MODE mode)
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
        case 2:
        {
            setPainter(_multiP);
            break;
        }

    }
}

void CpuWidget::setMulti(bool value)
{
    _multi = value;
    _dataQuery.setMulti(m_multi);

}

void CpuWidget::setIndex(int value)
{
    if (value <= _dataQuery.getNumberOfCores())
    {
        _index = value;
        _dataQuery.setIndex(value);
    }
    else
        std::cout<<"ERROR : value exiding number of cores .... skipping"<<std::endl;


}

CpuWidget::~CpuWidget()
{
    delete _graphP;
    delete _barsP;
    delete _multiP;

}
