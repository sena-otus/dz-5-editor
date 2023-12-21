#include "abstractcanvas.h"
#include "circle.h"

Circle::Circle(v2d && center, const int R, const int lineColor)
  : Item2d(lineColor),
    m_center(center),
    m_R(R)
{
}

void Circle::draw(AbstractCanvas &ac) const
{
  ac.drawCircle(m_center.x, m_center.y, m_R, lineColor());
}


// here follows boost serialization magic:
#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Circle)
