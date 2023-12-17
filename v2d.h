#pragma once

struct v2d
{
  double x;
  double y;
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
