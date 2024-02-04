#include "app.h"
#include "tcanvas.h"
#include "item2d.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include <memory>

const int horsize = 500;

AppCtrl::AppCtrl()
  : m_menu(), m_sketch(), m_rng(m_rd()), m_uniDistr(0, horsize)
{
  m_menu.addItem("Create new sketch", [this] {createNew   ();});
  m_menu.addItem("Import sketch"    , [this] {importSketch();});
  m_menu.addItem("Export sketch"    , [this] {exportSketch();});
  m_menu.addItem("Add line"         , [this] {addLine     ();});
  m_menu.addItem("Add circle"       , [this] {addCircle   ();});
  m_menu.addItem("Delete last added", [this] {delLast     ();});
  m_menu.addItem("Exit"             , [this] {appexit     ();});
  m_tcanvasptr = std::make_shared<TextCanvas>();
}

int AppCtrl::randomInt()
{
  return m_uniDistr(m_rng);
}

void AppCtrl::createNew()
{
  m_sketch.clear();
}


void AppCtrl::importSketch()
{
  std::ifstream ifs(m_fname);
  boost::archive::text_iarchive ia(ifs);
  ia >> m_sketch;
  std::cout << "impored from '" << m_fname << "'" << std::endl;
}

void AppCtrl::exportSketch()
{
  std::ofstream ofs(m_fname);
  boost::archive::text_oarchive oa(ofs);
  oa << m_sketch;
  std::cout << "exported to '" << m_fname << "'" << std::endl;
}

void AppCtrl::addLine()
{
    // simulate input from user by random generator
  const int color = randomInt();
  m_sketch.addLine(v2d{.x=randomInt(),.y=randomInt()}, v2d{.x=randomInt(),.y=randomInt()}, color);
}

void AppCtrl::addCircle()
{
    // simulate input from user by random generator
  const int R = randomInt();
  const int color = randomInt();
  m_sketch.addCircle(v2d{.x=randomInt(),.y=randomInt()}, R, color);
}

void AppCtrl::delLast()
{
  m_sketch.delLast();
}

void AppCtrl::appexit()
{
  m_exitFlag = true;
}

void AppCtrl::run()
{
  while(!m_exitFlag) {
    m_sketch.draw(*m_tcanvasptr);
    m_menu.show();

    std::string userInput;
    std::cin >> userInput;
    m_menu.processUserInput(userInput);
  }
}
