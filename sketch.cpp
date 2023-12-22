#include "sketch.h"
#include "line.h"
#include "circle.h"

#include <memory>
#include <utility>


void SketchModel::addLine(v2d &&start, v2d &&end, const int lineColor)
{
  m_items.push_back(std::make_shared<Line>(std::forward<v2d>(start), std::forward<v2d>(end), lineColor));
}


void SketchModel::addCircle(v2d &&center, const double R, const int lineColor)
{
  m_items.push_back(std::make_shared<Circle>(std::forward<v2d>(center), R, lineColor));
}


void SketchModel::setCanvas(std::shared_ptr<AbstractCanvas> acp)
{
  m_acp = std::move(acp);
}


void SketchModel::draw() const
{
  m_acp->drawCaption();
  std::for_each(m_items.begin(), m_items.end(), [this](const auto &item){item->draw(*m_acp);});
}


void SketchModel::delLast()
{
  if(!m_items.empty()) {m_items.pop_back();}
}


// here follows boost serialization magic:
#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(SketchModel)
