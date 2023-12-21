#pragma once

struct v2d
{
  int x{0};
  int y{0};
};


namespace boost {
  namespace serialization {

    template<class Archive>
    void serialize(Archive & ar, v2d & v, const unsigned int version [[maybe_unused]])
    {
      ar & v.x;
      ar & v.y;
    }

  } // namespace serialization
} // namespace boost
