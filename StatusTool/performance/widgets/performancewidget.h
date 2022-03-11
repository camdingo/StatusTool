#ifndef PERFORMANCEWIDGET_H
#define PERFORMANCEWIDGET_H

#include <QWidget>
#include <QTimer>

#include <dataQuery/queryresource.h>
#include <dataQuery/cpudataquery.h>

#include <painters/graphpainter.h>
#include <painters/barspainter.h>
#include <painters/graphmulticolorpainter.h>


class PerformanceWidget : public QWidget
{
    Q_OBJECT

public :

    enum SPEED //in ms
    {
      FAST_UPDATE = 250,
      MEDIUM_UPDATE = 500,
      SLOW_UPDATE = 1000
    };

public:
    explicit PerformanceWidget(QWidget *parent = 0);

    ~PerformanceWidget();

    void paintEvent(QPaintEvent *e);

    void setSpeed( const SPEED speed);

    void resizeEvent(QResizeEvent *e);

    void setDataQuery(DataQuery *dataQ);
    void setPainter(PerformancePainter *painter);

private slots:
    void updateData();

private :
    QTimer * _timer;

    PerformancePainter * _painter;

    DataQuery * _dataQuery;
};




#endif // PERFORMANCEWIDGET_H
