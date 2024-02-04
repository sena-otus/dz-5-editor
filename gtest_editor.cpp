/**
 * @file gtest_editor.cpp
 *
 * @brief Test editor
 *  */

#include "abstractcanvas.h"
#include "sketch.h"
#include "item2d.h"

#include <gtest/gtest.h>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <list>
#include <new>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

namespace {

  class TestCanvas final: public AbstractCanvas
  {
  public:
    void drawText([[maybe_unused]]int x, [[maybe_unused]]int y, [[maybe_unused]]const std::string &txt) override
    {
    }

    void drawLine(int x1, int y1, int x2, int y2, int color) override
    {
      m_sm.addLine(v2d{x1,y1}, v2d{x2,y2}, color);
    }

    void drawCircle(int x1, int y1, int radius, int color) override
    {
      m_sm.addCircle(v2d{x1, y1}, radius, color);
    }

    SketchModel  m_sm;
  };


   // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  TEST(Google_test, sketch) {
    {
      SketchModel sm;
      v2d c{191, 291};
      const int R{12};
      const int lineColor{1};

      for(int ii = 0; ii < 20; ii++)
      {
        c.x += 1;
        c.y += 1;
        sm.addCircle(v2d{c}, R, lineColor);
        const v2d p1 = c;
        v2d p2 = c;
        p2.x -= 5;
        p2.x -= 6;
        sm.addLine(v2d{p1}, v2d{p2}, lineColor+1);
      }

      EXPECT_EQ(sm.size(), 40);

      std::ostringstream oss;
      boost::archive::text_oarchive oa(oss);
      oa << sm;

      sm.delLast();
      EXPECT_EQ(sm.size(), 39);

      sm.clear();
      EXPECT_EQ(sm.size(), 0);

      std::istringstream iss(oss.str());
      boost::archive::text_iarchive ia(iss);
      ia >> sm;
      EXPECT_EQ(sm.size(), 40);

      TestCanvas tc;
      sm.draw(tc);

      EXPECT_EQ(sm.size(), tc.m_sm.size());

    }
  }

    // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
}
