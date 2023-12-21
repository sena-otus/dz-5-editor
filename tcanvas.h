#pragma once

#include "abstractcanvas.h"
#include <iostream>


class TextCanvas: public AbstractCanvas
{
public:
  void drawLine(int x1, int y1, int x2, int y2, int color)
  {
    std::cout << "Line(P(" << x1 << "," << y1 << "), P(" << x2 << "," << y2 << "), C(" << color << "))\n";
  }
  void drawCircle(int x, int y, int r, int color)
  {
    std::cout << "Circle(P(" << x << "," << y << "), R(" << r << "), C(" << color << "))\n";
  }
};
