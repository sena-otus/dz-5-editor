#pragma once
#include "abstractcanvas.h"
#include "v2d.h"

#include <boost/serialization/access.hpp>
#include <utility>

class Item2d
{
public:
  Item2d(Item2d && other) = default;
  Item2d(const Item2d &other) = default;
  Item2d & operator=(const Item2d &other) = default;
  Item2d & operator=(Item2d &&other) = default;
  virtual ~Item2d() = default;


  explicit Item2d(int lineColor) : m_lineColor(lineColor) {}

  int lineColor() const {return m_lineColor;}

  virtual void draw(AbstractCanvas &ac) const = 0;

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & m_lineColor;
  }
private:
  int m_lineColor;
};
