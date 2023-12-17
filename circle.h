#pragma once

#include "serialization.h"
#include <boost/serialization/base_object.hpp>
#include "item2d.h"

class Circle : public Item2d
{
public:
  Circle() = default;
  Circle(v2d && center, double R);

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & boost::serialization::base_object<Item2d>(*this);
    ar & m_center;
    ar & m_R;
  }

private:
   v2d m_center{};
   double m_R{};
};

BOOST_CLASS_EXPORT_KEY(Circle);
