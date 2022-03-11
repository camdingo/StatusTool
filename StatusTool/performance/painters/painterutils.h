#ifndef PAINTERUTILS_H
#define PAINTERUTILS_H
#include <QPainter>

class painterUtils
{
public:
    painterUtils();

    static void drawRectangleGraph(QPainter &qp ,int const &startPos,
                                   int const &width,int const &height,
                                   std::vector<float>  &data,
                                   QColor &lineColor , QColor &bodyColor);

    static void drawRectangleBar(QPainter &qp ,int const &startPos,
                          int const &width,int const &height ,const float value
                          , bool drawText,QColor &color1 , QColor &color2);


};

#endif // PAINTERUTILS_H
