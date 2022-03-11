 #ifndef PERFORMANCEPAINTER_H
#define PERFORMANCEPAINTER_H

#include <QPainter>

class PerformancePainter
{

public:

    PerformancePainter( QPaintDevice * widget);

    virtual ~PerformancePainter(){}

    ///The virtual paint method that needs to be reimplemented in the subclasses
    virtual void paint(){}

    void drawBackground(QPainter& qp);
    void drawGrid(QPainter& qp);

    void setGeometry(const int width, const int height) { _width = width; _height = height;}
    void setData(std::vector<std::vector<float> > cache) { _cache = cache; }
    void setDrawGrid(const bool value) { _drawGrid = value; }
    void setBackgroundColor(QColor color) { _backgroundColor = color; }
    void setGridColor(QColor color) { _gridColor = color; }
    void setColor1(QColor color) { _color1 = color; }
    void setColor2(QColor color) { _color2 = color; }

protected :
    int _width;
    int _height;

    int _gridHeightStep;
    int _gridWidthStep;

    int _drawGrid;

    QColor _gridColor;
    QColor _backgroundColor;

    QColor _color1;
    QColor _color2;

    QPaintDevice * _widget;

    std::vector<std::vector<float> >  _cache;

};

#endif // PERFORMANCEPAINTER_H