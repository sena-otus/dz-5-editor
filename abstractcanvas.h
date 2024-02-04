#pragma once

#include <string>

/**
 * @brief abstract interface to graphical device.
 * Real class must implement drawing functions
 * */
class AbstractCanvas
{
public:
  AbstractCanvas() = default;
  AbstractCanvas(const AbstractCanvas &) = default;
  AbstractCanvas(AbstractCanvas &&) = default;
  AbstractCanvas& operator=(const AbstractCanvas &) = default;
  AbstractCanvas& operator=(AbstractCanvas &&) = default;
     /** @brief destructor better be virtual for the base class */
  virtual ~AbstractCanvas() = default;

    /** @brief draw text */
  virtual void drawText(int x, int y, const std::string &txt) = 0;

    /** @brief draw line
     *  @param x1 starting pixel X coordinate
     *  @param y1 starting pixel Y coordinate
     *  @param x2 ending pixel X coordinate
     *  @param y2 ending pixel Y coordinate
     *  @param color line color
     * */
  virtual void drawLine(int x1, int y1, int x2, int y2, int color) = 0;

    /** @brief draw circle
     *  @param x1 center pixel X coordinate
     *  @param y1 center pixel Y coordinate
     *  @param radius circle radius
     *  @param color line color
     * */
  virtual void drawCircle(int x1, int y1, int radius, int color) = 0;
};
