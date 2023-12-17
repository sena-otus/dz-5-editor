#include "circle.h"

Circle::Circle(v2d && center, const double R)
  : Item2d(std::forward<v2d>(center)),
    m_center(base()),
    m_R(R)
{
}


#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Circle)
