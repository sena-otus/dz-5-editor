#pragma once

#include "abstractcanvas.h"
#include "v2d.h"

#include "serialization.h"
#include <boost/serialization/list.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <list>
#include <memory>

class Item2d;
class AbstractCanvas;

/** @brief SketchModel is a model in MVC */
class SketchModel
{
public:
    /** remove all items */
  void clear() {m_items.clear();}

    /** add line
     * @param start line start
     * @param end line end
     * @param lineColor line color
     * */
  void addLine(v2d && start, v2d && end, int lineColor);

    /** add circle
     * @param center circle center
     * @param R circle radius
     * @param lineColor cicle color
     * */
  void addCircle(v2d && center, double R, int lineColor);

    /** delete last added item */
  void delLast();

    /** draw using AbstractCanvas iface */
  void draw(AbstractCanvas &) const;

    /** grant access to boost serialization */
  friend class boost::serialization::access;

    /** serialization */
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version	[[maybe_unused]])
  {
    ar & m_items;
  }

  size_t size() const { return m_items.size();}

private:
  std::list<std::shared_ptr<Item2d>> m_items; //!< items
};
