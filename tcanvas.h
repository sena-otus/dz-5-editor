#pragma once

#include "abstractcanvas.h"
#include <iostream>


/**
*  @brief implements canvas for the text-mode
*  That is a Viewer from MVC pattern (another viewer is class Menu).
*  */

class TextCanvas: public AbstractCanvas
{
public:
      /** @brief draw caption */
  void drawCaption() override
  {
    std::cout << "\nCanvas\n******\n";
  }

    /** @brief draw line
     *  @param x1 starting pixel X coordinate
     *  @param y1 starting pixel Y coordinate
     *  @param x2 ending pixel X coordinate
     *  @param y2 ending pixel Y coordinate
     *  @param color line color
     * */
  void drawLine(int x1, int y1, int x2, int y2, int color) override
  {
    std::cout << "Line(P(" << x1 << "," << y1 << "), P(" << x2 << "," << y2 << "), C(" << color << "))\n";
  }

    /** @brief draw circle
     *  @param x1 center pixel X coordinate
     *  @param y1 center pixel Y coordinate
     *  @param radius circle radius
     *  @param color line color
     * */
  void drawCircle(int x, int y, int r, int color) override
  {
    std::cout << "Circle(P(" << x << "," << y << "), R(" << r << "), C(" << color << "))\n";
  }
};
