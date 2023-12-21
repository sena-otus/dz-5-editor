#pragma once

class AbstractCanvas
{
public:
  virtual ~AbstractCanvas() = default;
  virtual void drawLine(int x1, int y1, int x2, int y2, int color) = 0;
  virtual void drawCircle(int x1, int y1, int radius, int color) = 0;
};
