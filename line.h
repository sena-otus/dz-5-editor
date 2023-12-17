#pragma once

#include "serialization.h"
#include <boost/serialization/base_object.hpp>
#include "item2d.h"

class Line : public Item2d
{
public:
  Line() = default;
  Line(v2d && start, v2d && end);

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & boost::serialization::base_object<Item2d>(*this);
    ar & m_start;
    ar & m_end;
  }

private:
   v2d m_start{};
   v2d m_end{};
};

BOOST_CLASS_EXPORT_KEY(Line);
