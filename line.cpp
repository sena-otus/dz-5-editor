#include "line.h"

Line::Line(v2d && start, v2d && end)
  : Item2d(std::forward<v2d>(start)),
    m_start(base()),
    m_end(std::forward<v2d>(end))
{
}


#include "serialize_archive.h"

BOOST_CLASS_EXPORT_IMPLEMENT(Line)
