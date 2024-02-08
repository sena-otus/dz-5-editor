#pragma once
#include "abstractcanvas.h"
#include "v2d.h"

#include <boost/serialization/access.hpp>
#include <utility>

/**
* @brief Abstract base class for all 2d objects.
*  */
class Item2d
{
public:
  Item2d(Item2d && other) = default;
  Item2d(const Item2d &other) = default;
  Item2d & operator=(const Item2d &other) = default;
  Item2d & operator=(Item2d &&other) = default;
  virtual ~Item2d() = default;


  explicit Item2d(int lineColor) : m_lineColor(lineColor) {}

    /** getter to access line color */
  int lineColor() const {return m_lineColor;}

    /** Draw the item on provided canvas.
     * Every item should implement it.
     * @param ac canvas to draw
     * */
  virtual void draw(AbstractCanvas &ac) const = 0;

    /** grant access for boost serialization */
  friend class boost::serialization::access;
    /**  boost serialization */
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & m_lineColor;
  }
private:
  int m_lineColor; //!< line color
};
