#ifndef WEKTOR_HPP_INCLUDED
#define WEKTOR_HPP_INCLUDED

class Wektor{
   public:
      const double dx = 0.0;
      const double dy = 0.0;
      Wektor();
      Wektor(const double xx, const double yy);
      Wektor(const Wektor &wektor);
      Wektor& operator = (const Wektor&) = delete;
};

Wektor zloz(const Wektor &wektor1, const Wektor &wektor2);

#endif // WEKTOR_HPP_INCLUDED
