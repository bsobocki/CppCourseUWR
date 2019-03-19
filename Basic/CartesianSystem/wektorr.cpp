#include "wektor.hpp"

using namespace std;

Wektor::Wektor()                                   : dx(0), dy(0){}
Wektor::Wektor(const double xx, const double yy)   : dx(xx), dy(yy){}
Wektor::Wektor(const Wektor &wektor)               : dx(wektor.dx), dy(wektor.dy){}
Wektor zloz(const Wektor &wektor1, const Wektor &wektor2)
{
   return Wektor(wektor1.dx + wektor2.dx, wektor1.dy + wektor2.dy);
}
