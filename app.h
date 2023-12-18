#pragma once

#include "v2d.h"
#include "sketch.h"
#include "menu.h"
#include <functional>

class App
{
public:
  App();

  void createNew()
  {
    m_sketch.clear();
  }

  void importSketch();

  void exportSketch();

  void addLine()
  {
      // TODO: get line coors from user
    m_sketch.addLine(v2d{.x=1,.y=1}, v2d{.x=0,.y=0});
  }

  void addCircle()
  {
      // TODO: get circle coors from user
    m_sketch.addCircle(v2d{.x=10,.y=10}, 15);
  }

  void delLast()
  {
    m_sketch.delLast();
  }

  void appexit()
  {
    m_exitFlag = true;
  }

  void run()
  {
    while(!m_exitFlag) { m_menu.show(); }
  }

private:
  Menu m_menu;
  std::string m_fname{"sketch.txt"};
  Sketch m_sketch;
  bool m_exitFlag{false};
};
