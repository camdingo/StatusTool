#include "barspainter.h"
#include <painters/painterutils.h>
#include <iostream>

BarsPainter::BarsPainter(QPaintDevice * widget) 
    :   PerformancePainter(widget)

{
    // Initializing colors
    _color1 = (QColor(0,255,0,255));
    _color2 = (QColor(255,0,0,255));
}

void BarsPainter::paint()
{
    //Create a new painter
    QPainter qpN(_widget);
    //Draw gird and BG
    drawBackground(qpN);
    drawGrid(qpN);

    //Set a white color for the main rectangle
    qpN.setPen(QColor(255,255,255,255));


    //Compute size of the data and step size
    int size = _cache.size();
    if (size <= 0)
    {
        std::cout<<"ERROR : NO DATA PROVIDED, CACHE SIZE IS 0"<<std::endl;
        return;
    }

    float steps = (_width-size ) / (size);

    int subSize = _cache[0].size();
    //Lets loop for each bar needed to be drawn
    for(int i = 0 ; i < size;i++)
    {
        //Let set the background color (zero alpha is transparent)
        qpN.setBrush(QColor(100,100,100,0));

        //Lets draw the container rectangle
        qpN.drawRoundedRect((steps*(i))+(i*2) ,0,(steps),_height-1,
                         3,3,Qt::AbsoluteSize);

        //Lets theck if the size is big enough to contain the percentage value
        //Then lets draw the actual rectangle
        if (steps > 80)
        {
            painterUtils::drawRectangleBar(qpN, i * steps + 3 + i * 2, steps,
               _height, _cache[i][subSize - 1], true,
                _color1,
                _color2);
        }
        else
        {
            painterUtils::drawRectangleBar(qpN, i * steps + 3 + i * 2, steps,
                _height, _cache[i][subSize - 1], false,
                _color1,
                _color2);
        }
    }
}
