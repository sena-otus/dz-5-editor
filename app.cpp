#include "app.h"
#include "item2d.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>


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
