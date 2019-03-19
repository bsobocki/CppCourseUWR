#include "punkt.hpp"

using namespace std;

Punkt::Punkt(double xx, double yy)                     : x(xx), y(yy){}
Punkt::Punkt(const Punkt &punkt, const Wektor &wektor) : x(punkt.x + wektor.dx), y(punkt.y + wektor.dy){}
Punkt::Punkt(const Punkt &punkt)                       : x(punkt.x), y(punkt.y){}
