#ifndef WYMIERNE_HPP_INCLUDED
#define WYMIERNE_HPP_INCLUDED
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int nwd(int a, int b);

namespace obliczenia
{

   class wyjatek_wymierny: public exception
   {
   protected:
      string wyjatek;

   public:
      wyjatek_wymierny(string wyj);
      virtual const string what() =0;
   };

   class dzielenie_przez_0: public wyjatek_wymierny
   {
   public:
      dzielenie_przez_0(string wyj);

      const string what();
   };

   class przekroczenie_zakresu: public wyjatek_wymierny
   {
   public:
      przekroczenie_zakresu(string wyj);

      const string what();
   };


   class Wymierne
   {
   private:
     int licznik;
     int mianownik=1;

   public:
      Wymierne(const int l, const int m) throw (dzielenie_przez_0,przekroczenie_zakresu);
      Wymierne(const int liczba);
      Wymierne(const Wymierne&);
      Wymierne(Wymierne&&);

      int getlicznik() const;
      int getmianownik() const;
      void setlicznik(int l);
      void setmianownik(int m);

      friend ostream& operator<< (ostream &wyj, const Wymierne &w);
      Wymierne & operator= (const Wymierne& w);
      Wymierne & operator= (Wymierne&& w);
      Wymierne operator+ (const Wymierne& w) throw (przekroczenie_zakresu);
      Wymierne operator+ (Wymierne&& w) throw (przekroczenie_zakresu);
      Wymierne operator- (const Wymierne& w) throw (przekroczenie_zakresu);
      Wymierne operator- (Wymierne&& w) throw (przekroczenie_zakresu);
      Wymierne operator* (const Wymierne& w) throw (przekroczenie_zakresu);
      Wymierne operator* (Wymierne&& w) throw (przekroczenie_zakresu);
      Wymierne operator/ (const Wymierne& w) throw (dzielenie_przez_0,przekroczenie_zakresu);
      Wymierne operator/ (Wymierne&& w) throw (dzielenie_przez_0,przekroczenie_zakresu);

      Wymierne operator- ();
      Wymierne operator! () throw (dzielenie_przez_0);

      operator double() const;
      explicit operator int() const;
   };

   ostream & operator<< (ostream &wyj, const Wymierne &w);
}

#endif // WYMIERNE_HPP_INCLUDED
