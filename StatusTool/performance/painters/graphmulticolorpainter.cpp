#include "graphmulticolorpainter.h"
#include "painterutils.h"
#include <stdio.h>
#include <iostream>


GraphMultiColorPainter::GraphMultiColorPainter(QPaintDevice * widget)
    :   PerformancePainter(widget)

{
    //Add more colors for more cpus later
    //Initializing colors
    _color1 =(QColor(0,255,0,255));
    _color2 = (QColor(0,180,0,0));

    //init colors
    _colors.clear();
    _colors.push_back(QColor(  255, 255, 0));
    _colors.push_back(QColor( 255, 127, 0));
    _colors.push_back(QColor( 255, 0, 0));
    _colors.push_back(QColor( 127, 255, 0));

    _colors.push_back(QColor(  0, 255, 0));
    _colors.push_back(QColor( 0, 255, 127));
    _colors.push_back(QColor( 0, 255, 255));
    _colors.push_back(QColor(  0, 127, 255));
    
    _colors.push_back(QColor( 0, 0, 255));
    _colors.push_back(QColor( 127, 0, 255));
    _colors.push_back(QColor( 255, 0, 255));
    _colors.push_back(QColor( 255, 0, 127));
}





void GraphMultiColorPainter::checkColors( )
{
    //Lets check if we have enough color for all the data
    int currSize = _colors.size();
    int numberOfColors = _cache.size();

    //if the color we need are less then the current available colors lets get out
    if (numberOfColors <= currSize)
        return;

    //if not lets create random colors
    for(int i = 0; i < (numberOfColors - currSize) ; ++i)
    {
        QColor temp(int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    int(rand() * float(COLOR_RANGE) / RAND_MAX),
                    255);

        _colors.push_back(temp);

    }
}


void GraphMultiColorPainter::paint()
{
    //checkColors
    checkColors();

    QColor _back = QColor(0,180,0,0);

    //Create a new painter
    QPainter qpN(_widget);

    //Draw gird and BG
    drawBackground(qpN);
    drawGrid(qpN);

    //Compute size of the data and step size
    int cacheSize = _cache.size();
    qpN.setBrush(_back);
    qpN.drawRoundedRect(0 ,0, _width -2, _height-1,
                        3, 3, Qt::AbsoluteSize);

    bool legendOnOff = (MIN_LEGEND_WIDTH * size) <= _width;


    for(int i = 0 ; i < cacheSize; ++i)
    {
       //lets use our utils to draw the graph
       _back = _colors[cacheSize -i-1];
       _back.setAlpha(80);
       painterUtils:: drawRectangleGraph(qpN,0,
                                         _width,_height,_cache[cacheSize -i-1],
                                        _colors[cacheSize -i-1],_back);

       //paint legend
       if (legendOnOff )
       {
                QString text = QString("#") + QString::number(cacheSize -i-1);
                qpN.drawText(MIN_LEGEND_WIDTH *(cacheSize -i-1) +5,15,text);

       }
    }


}


