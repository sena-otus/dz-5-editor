#include "line.h"

Line::Line(v2d && start, v2d && end, const int lineColor)
  : Item2d(lineColor),
    m_start(std::forward<v2d>(start)),
    m_end(std::forward<v2d>(end))
{
}

void Line::draw(AbstractCanvas &ac) const
{
  ac.drawLine(m_start.x, m_start.y, m_end.x, m_end.y, lineColor());
}


// here follows boost serialization magic:
#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Line)
