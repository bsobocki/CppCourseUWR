#include "wymierne.hpp"

using namespace std;
using namespace obliczenia;

int nwd(int a, int b)
{
  int t;
  a = abs(a);
  b = abs(b);
  while(b)
  {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}


Wymierne::Wymierne(const int l, const int m)
throw (dzielenie_przez_0,przekroczenie_zakresu)
{
   if(m!=INT_MIN)
   {
      if (m!=0)
      {
         licznik = l/nwd(l,m);
         mianownik = m/nwd(l,m);
         if (mianownik<0)
          {
            licznik = -licznik;
            mianownik = -mianownik;
          }
      }
      else
         throw dzielenie_przez_0("Nie dziel przez 0!!!");
   }
   else throw przekroczenie_zakresu("Przekroczono zakres!!");
}

Wymierne::Wymierne(const int liczba): licznik(liczba){}

int Wymierne::getlicznik() const    {return licznik;}
int Wymierne::getmianownik() const  {return mianownik;}
void Wymierne::setlicznik(int l)    {licznik = l;}
void Wymierne::setmianownik(int m)  {mianownik = m;}



Wymierne & Wymierne::operator= (const Wymierne& w)
{
   licznik = w.getlicznik();
   mianownik = w.getmianownik();
   return *this;
}
Wymierne & Wymierne::operator= (Wymierne&& w)
{
   licznik = w.getlicznik();
   mianownik = w.getmianownik();

   return *this;
}




int suma25(int a)
{
 int w = 0;
 while(a % 2 == 0)
 {
   a /= 2;
   w++;
 }
 while(a % 5 == 0)
 {
   a /= 5;
   w++;
 }
 return w;
}


ostream & obliczenia::operator<< (ostream &wyj, const Wymierne &w)
{
 if(w.getlicznik()/w.getmianownik() == 0 && w.getlicznik() < 0)
   wyj << "-";
 wyj << w.getlicznik()/w.getmianownik();
 if(w.getlicznik() % w.getmianownik() != 0)
 {
   wyj << ".";
   int suma = suma25(w.getmianownik());
   int o = w.getlicznik() % w.getmianownik() * 10;
   for(int i=0; i<suma ; i++)
   {
     wyj << abs(o / w.getmianownik());
     o = o % w.getmianownik() * 10;
   }
   wyj << "(";
   int p = o , i = 1;
   while(p != o || i == 1)
   {
     wyj << abs(o / w.getmianownik());
     o = o % w.getmianownik() * 10;
     i++;
   }
   wyj << ")";
 }
 return wyj;
}




Wymierne Wymierne::operator+ (const Wymierne& w) throw (przekroczenie_zakresu)
{
   int64_t c = static_cast<int64_t>(licznik*w.getmianownik()) + static_cast<int64_t>(mianownik*w.getlicznik());
   int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);
   Wymierne a(0,1);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));
   return Wymierne(0,1);
}
Wymierne Wymierne::operator+ (Wymierne&& w) throw (przekroczenie_zakresu)
{
   int64_t c = static_cast<int64_t>(licznik*w.getmianownik()) + static_cast<int64_t>(mianownik*w.getlicznik());
   int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));

   return Wymierne(0,1);
}



Wymierne Wymierne::operator- (const Wymierne& w) throw (przekroczenie_zakresu)
{
   int64_t c = static_cast<int64_t>(licznik*w.getmianownik()) - static_cast<int64_t>(mianownik*w.getlicznik());
   int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));
   return Wymierne(0,1);
}
Wymierne Wymierne::operator- (Wymierne&& w) throw (przekroczenie_zakresu)
{
    int64_t c = static_cast<int64_t>(licznik*w.getmianownik()) - static_cast<int64_t>(mianownik*w.getlicznik());
    int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));

   return Wymierne (0,1);
}



Wymierne Wymierne::operator* (const Wymierne& w) throw (przekroczenie_zakresu)
{
   int64_t c = static_cast<int64_t>(licznik) * static_cast<int64_t>(w.getlicznik());
   int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));
   return Wymierne(0,1);
}
Wymierne Wymierne::operator* (Wymierne&& w) throw (przekroczenie_zakresu)
{
   int64_t c = static_cast<int64_t>(licznik) * static_cast<int64_t>(w.getlicznik());
   int64_t d = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));

   return Wymierne(0,1);
}



Wymierne Wymierne::operator/ (const Wymierne& w) throw (przekroczenie_zakresu,dzielenie_przez_0)
{
   int64_t c = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(licznik);
   int64_t d = static_cast<int64_t>(w.getlicznik()) * static_cast<int64_t>(mianownik);

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else if (d==0)
      throw dzielenie_przez_0("Nie dziel przez zero!!!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));
   return Wymierne(0,1);
}
Wymierne Wymierne::operator/ (Wymierne&& w) throw (przekroczenie_zakresu, dzielenie_przez_0)
{
   int64_t c = static_cast<int64_t>(w.getmianownik()) * static_cast<int64_t>(licznik);
   int64_t d = static_cast<int64_t>(w.getlicznik()) * static_cast<int64_t>(mianownik);
   ;

   if (c>INT_MAX || c<INT_MIN || d>INT_MAX || d<INT_MIN)
      throw przekroczenie_zakresu("Zakres zostal przekroczony!");
   else if (d==0)
      throw dzielenie_przez_0("Nie dziel przez zero!!!");
   else
      return Wymierne(static_cast<int>(c)/nwd(c,d),static_cast<int>(d)/nwd(c,d));

   return Wymierne(0,1);
}



Wymierne Wymierne::operator- ()
{
   return Wymierne(-licznik,mianownik);
}



Wymierne Wymierne::operator! () throw (dzielenie_przez_0)
{
   if (licznik >= 0)
   {
      if (licznik > 0)
         return Wymierne(mianownik,licznik);
      else
         throw dzielenie_przez_0("Nie dziel przez zero!!!");
   }
   else
   {
      return Wymierne (-mianownik,-licznik);
   }
   return *this;
}



Wymierne::operator double() const
{
   return static_cast<double>(licznik)/static_cast<double>(mianownik);
}



Wymierne::operator int() const
{
   return licznik/mianownik;
}



wyjatek_wymierny::wyjatek_wymierny(string wyj): wyjatek(wyj){}


dzielenie_przez_0::dzielenie_przez_0(string wyj): wyjatek_wymierny(wyj){}
const string dzielenie_przez_0::what(){return wyjatek;}

przekroczenie_zakresu::przekroczenie_zakresu (string wyj): wyjatek_wymierny(wyj){}
const string przekroczenie_zakresu::what(){return wyjatek;}

