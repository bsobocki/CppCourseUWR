#ifndef PUNKT_HPP_INCLUDED
#define PUNKT_HPP_INCLUDED
#include "wektor.hpp"

class Punkt{
   public:
      const double x = 0.0;
      const double y = 0.0;
      Punkt() = default;
      Punkt(const Punkt &punkt, const Wektor &wektor);
      Punkt(const double xx, const double yy);
      Punkt(const Punkt &punkt);
      Punkt& operator = (const Punkt&) = delete;
};
#endif // PUNKT_HPP_INCLUDED
