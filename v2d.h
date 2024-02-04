#pragma once

/** 2d vector */
struct v2d
{
  int x{0}; //!< x component
  int y{0}; //!< y component
};


namespace boost {
  namespace serialization {

      /** boost serialization magic for struct v2d */
    template<class Archive>
    void serialize(Archive & ar, v2d & v, const unsigned int version [[maybe_unused]])
    {
      ar & v.x;
      ar & v.y;
    }

  } // namespace serialization
} // namespace boost
