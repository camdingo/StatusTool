#include "graphpainter.h"
#include "painterutils.h"
#include <stdio.h>
#include <iostream>
GraphPainter::GraphPainter(QPaintDevice * widget)
    :   PerformancePainter(widget)

{
    // Initializing colors
    _color1 =(QColor(0,255,0,255));
    _color2 = (QColor(0,180,0,120));

}



void GraphPainter::paint()
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
    int sizeLess  = size -1;

    if (sizeLess <= 0)
    {
        sizeLess = 1;

    }
    float steps = (_width- _cache.size() ) / (size);
    for(int i = 0 ; i < (size);i++)
    {
        //Let set needed colors for the background and borer
        qpN.setPen(QColor(244,244,244,255));
        qpN.setBrush(QColor(100,100,100,0));
        qpN.drawRoundedRect((steps*(i))+(i*2) ,0,(steps),_height-1,
                         3,3,Qt::AbsoluteSize);

       //lets use our utils to draw the graph
       painterUtils:: drawRectangleGraph(qpN,(steps*(i))+(i*2)-1,
                                         steps,_height,_cache[i],
                                         _color1,_color2);


        }


}


