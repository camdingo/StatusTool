#include <QPainter>
#include <QLinearGradient>
#include <painters/painterutils.h>
#include "performancewidget.h"


PerformanceWidget::PerformanceWidget(QWidget *parent) 
    :   QWidget(parent)
    ,   _timer(nullptr)
    ,   _painter(nullptr)
    ,   _dataQuery(nullptr)

{
    //Setup the timer
    _timer = new QTimer (this);
    connect(_timer, SIGNAL(timeout()),this,  SLOT(updateData()));
    connect(_timer, SIGNAL(timeout()),this,  SLOT(repaint()));
    _timer->start(SLOW_UPDATE);
}


void PerformanceWidget::paintEvent(QPaintEvent *e)
{
    Q_UNSUSED(e);

    if (!_dataQuery)
        return;

    _painter->setData(_dataQuery->_cache);
    _painter->paint();


}


void PerformanceWidget::setSpeed(const SPEED speed)
{
    _timer->stop();
    _timer->start(speed);
}


PerformanceWidget::~PerformanceWidget()
{
    delete _timer;
}


void PerformanceWidget::setDataQuery(DataQuery *dataQ)
{
    _dataQuery = dataQ;
}

void PerformanceWidget::resizeEvent(QResizeEvent *e)
{
    Q_UNUSED(e);

    if (_painter)
         _painter->setGeometry(width(),height());

}


void PerformanceWidget::updateData()
{
    if (_dataQuery)
        _dataQuery->getData();
    else
        std::cout<<"ERROR : NO DATA QUERY DEVICE PROVIDED"<<std::endl;

}


void PerformanceWidget::setPainter(PerformancePainter *painter)
{
    _painter = painter;
    _painter->setGeometry(width(),height());
    updateData();
}
