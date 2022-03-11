#include "performancepainter.h"
#include <iostream>

PerformancePainter::PerformancePainter(QPaintDevice * widget) 
    :  
    ,   _width(100)
    ,   _height(100)
    ,   _gridHeightStep(15)
    ,   _gridWidthStep(30)
    ,   _drawGrid(true)
    ,   _gridColor(QColor(180,180,180,180))
    ,   _backgroundColor(QColor(40,40,40,255))
    ,   _color1(QColor(0,230,0,255))
    ,   _color2(QColor(0,230,0,255))
    ,   _widget(widget)

{
}


void PerformancePainter::drawBackground(QPainter &qp)
{
    //  //Declare a painter and a pen used for drawing
    qp.setPen(QColor(255,255,255,255));
    qp.setBrush(_backgroundColor);

    //Draw the background
    qp.drawRoundedRect(0, 0, _width - 1, _height - 1, 3, 3, Qt::AbsoluteSize);
}


void PerformancePainter::drawGrid(QPainter &qp)
{
    //Draw grid
    if (_drawGrid == false)
        return;

    //Set pen color
    qp.setPen(_gridColor);

    //Compute height and width steps
    int stepHeight = _height / _gridHeightStep;
    int stepWidth = _width / _gridWidthStep;


    //TODO fix logic? 
    //Draw horizontal lines
    for (int i = 0; i < stepWidth + 1; ++i)
    {
      qp.drawLine((_gridWidthStep * i) + 2, 1, (_gridWidthStep * i) + 2, _height - 1);
    }

    //Draw vertical lines
    for (int i = 0; i < stepHeight + 1; ++i)
    {
      qp.drawLine(4, (_gridHeightStep * i) + 2, _width - 4, (_gridHeightStep * i) + 2);
    }

}
