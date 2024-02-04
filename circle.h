#pragma once

#include "serialization.h"
#include <boost/serialization/base_object.hpp>
#include "item2d.h"

class AbstractCanvas;

/** Circle item */
class Circle : public Item2d
{
public:
  explicit Circle() : Item2d(0) {};
  Circle(v2d && center, int R, int lineColor);

  void draw(AbstractCanvas &ac) const override;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & boost::serialization::base_object<Item2d>(*this);
    ar & m_center;
    ar & m_R;
  }

private:
  v2d m_center{}; //!< center coordinate
  int m_R{}; //!< radius
};

BOOST_CLASS_EXPORT_KEY(Circle);
