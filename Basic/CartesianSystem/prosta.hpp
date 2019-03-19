#ifndef PROSTA_HPP_INCLUDED
#define PROSTA_HPP_INCLUDED
#include <iostream>
#include <stdexcept>
#include "wektor.hpp"
#include "punkt.hpp"
#include <cmath>


class Prosta{
private:
   double A = 1.0;
   double B = -1.0;
   double C;

public:
   double get_A() const {return A;}
   double get_B() const {return B;}
   double get_C() const {return C;}
   Prosta() = default;
   Prosta(const Wektor &wek);
   Prosta(double a, double b, double c);
   Prosta(const Prosta &prosta, const Wektor &wek);
   Prosta(const Punkt &PktA, const Punkt &PktB);
   Prosta& operator = (const Prosta&) = delete;
   Prosta(const Prosta&) = delete;
   bool CzyPunktLezy(const Punkt& p);
   bool czyWektorProstopadly(const Prosta &pr, const Wektor &wek);
   bool czyWektorRownolegly(const Prosta &pr, const Wektor &wek);
   void normalizacja();
};

bool czyProstopadle(const Prosta &pr1, const Prosta &pr2);
bool czyRownolegle(const Prosta &pr1, const Prosta &pr2);
Punkt punktPrzeciecia(const Prosta &pr1, const Prosta &pr2);

#endif // PROSTA_HPP_INCLUDED
