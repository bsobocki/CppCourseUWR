#include "data.hpp"

using namespace std;


Wydarzenie::Wydarzenie()
{
   DataGodz tmp;
   punktCzasowy = tmp;
   tytul = "no title";
}

Wydarzenie::Wydarzenie(const string title)
{
   DataGodz tmp;
   punktCzasowy = tmp;
   tytul = title;
}

Wydarzenie::Wydarzenie(const DataGodz& d, const string title)
{
   punktCzasowy = d;
   tytul = title;
}

Wydarzenie& Wydarzenie::operator= (const Wydarzenie& ev)
{
   punktCzasowy = ev.punktCzasowy;
   tytul = ev.tytul;
}

