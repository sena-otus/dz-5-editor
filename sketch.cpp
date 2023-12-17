#include "sketch.h"
#include "line.h"
#include "circle.h"

#include <memory>


void Sketch::addLine(v2d &&start, v2d &&end)
{
  m_items.push_back(std::make_shared<Line>(std::forward<v2d>(start), std::forward<v2d>(end)));
}

void Sketch::addCircle(v2d &&center, const double R)
{
  m_items.push_back(std::make_shared<Circle>(std::forward<v2d>(center), R));
}

void Sketch::delFirst()
{
  if(m_items.empty()) {m_items.pop_back();}
}


// here follows boost serialization magic:
#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Sketch)
