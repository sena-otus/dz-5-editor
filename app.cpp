#include "app.h"
#include "tcanvas.h"
#include "item2d.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include <memory>

App::App()
  : m_menu(), m_sketch()
{
  m_menu.addItem("Create new sketch", [this] {createNew   ();});
  m_menu.addItem("Import sketch"    , [this] {importSketch();});
  m_menu.addItem("Export sketch"    , [this] {exportSketch();});
  m_menu.addItem("Add line"         , [this] {addLine     ();});
  m_menu.addItem("Add circle"       , [this] {addCircle   ();});
  m_menu.addItem("Delete last"      , [this] {delLast     ();});
  m_menu.addItem("Exit"             , [this] {appexit     ();});
  m_tcanvasptr = std::make_shared<TextCanvas>();
  m_sketch.setCanvas(m_tcanvasptr);
}

void App::importSketch()
{
  std::ifstream ifs(m_fname);
  boost::archive::text_iarchive ia(ifs);
  ia >> m_sketch;
}

void App::exportSketch()
{
  std::ofstream ofs(m_fname);
  boost::archive::text_oarchive oa(ofs);
  oa << m_sketch;
}
