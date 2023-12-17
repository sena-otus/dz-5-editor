#pragma once

#include "v2d.h"

#include "serialization.h"
#include <boost/serialization/list.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <list>
#include <memory>

class Item2d;

class Sketch
{
public:
  void clear() {m_items.clear();}
  void addLine(v2d && start, v2d && end);
  void addCircle(v2d && center, double R);
  void delLine();

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & m_items;
  }

private:

  std::list<std::shared_ptr<Item2d>> m_items;
};
