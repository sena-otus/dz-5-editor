#pragma once

#include "tcanvas.h"
#include "v2d.h"
#include "sketch.h"
#include "menu.h"
#include <functional>
#include <random>

/** @brief controller class */
class AppCtrl
{
public:
  AppCtrl();

  int randomInt();

  void createNew();

  void importSketch();

  void exportSketch();

  void addLine();

  void addCircle();

  void delLast();

  void appexit();

  void run();

private:
  Menu m_menu;
  std::string m_fname{"sketch.txt"};
  std::shared_ptr<TextCanvas> m_tcanvasptr;
  SketchModel m_sketch;
  bool m_exitFlag{false};
  std::random_device m_rd;     ///! Only used once to initialise (seed) engine
  std::mt19937 m_rng;    ///! Random-number engine used (Mersenne-Twister)
  std::uniform_int_distribution<int> m_uniDistr; ///! produces random ints, uniformly distributed on the interval
};
