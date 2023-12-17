#pragma once
#include "v2d.h"

#include <boost/serialization/access.hpp>
#include <utility>

class Item2d
{
public:
  Item2d()
    : m_base{.x = 0, .y = 0}
  {}

  Item2d(const Item2d &other) = default;
  Item2d(Item2d &&other) = default;
  Item2d& operator=(const Item2d &other) = default;
  Item2d& operator=(Item2d &&other) = default;
  virtual ~Item2d() = default;

  explicit Item2d(v2d && basepoint)
    : m_base(std::forward<v2d>(basepoint))
    {}

  v2d base() const { return m_base; }

  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & m_base;
  }

private:
  v2d m_base;
};
