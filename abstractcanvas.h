#pragma once

/**
 * @brief abstract interface to graphical device.
 * Real class must implement drawing functions
 * */
class AbstractCanvas
{
public:
    /** @brief destructor better be virtual for the base class */
  virtual ~AbstractCanvas() = default;

    /** @brief draw caption */
  virtual void drawCaption() = 0;

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
