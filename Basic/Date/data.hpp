#ifndef DATA_HPP_INCLUDED
#define DATA_HPP_INCLUDED
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

class Data{
protected:
   short dzien;
   short miesiac;
   int rok;

public:
   static constexpr int dniwmiesiacach[2][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
{0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};
   static constexpr int dniodpoczroku[2][13]= {
{0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
{0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};

public:
   short get_dzien() const;
   short get_miesiac() const;
   short get_rok() const;

   Data();
   Data(short day, short month, short year);
   Data(const Data& d);
   Data(Data&& d);

   Data& operator = (const Data& d);
   Data& operator = (Data&& d);

protected:
   static bool przestepny(short year);

private:
   bool czyPoprawnaData(short day, short month, short year);
public:
   int ilednioddaty();

public:
   virtual int operator - (Data& d);
   Data& operator ++ ();
   Data& operator -- ();
   Data& operator -= (int d);
   Data& operator += (int d);

};

class DataGodz final : public Data
{
protected:
   short godzina = 0;
   short minuty  = 0;
   short sekundy = 0;

public:
   DataGodz();
   DataGodz(short hour, short minutes, short seconds);
   DataGodz(const Data& d,short hour, short minutes, short seconds);
   DataGodz(const DataGodz& d);
   DataGodz(DataGodz&& d);

   DataGodz& operator = (const DataGodz& d);
   DataGodz& operator = (DataGodz&& d);

   short get_godzina() const;
   short get_minuty() const;
   short get_sekundy() const;

   DataGodz& operator ++ ();
   DataGodz& operator -- ();
   DataGodz& operator -= (int d);
   DataGodz& operator += (int d);
   bool operator > (const DataGodz& d);
   bool operator == (const DataGodz& d);

private:
   int ilednioddaty();

public:
   int dnioddaty()
   {
      return ilednioddaty();
   }

};

int operator - (DataGodz& d1, DataGodz& d2);

class Wydarzenie
{
public:
   DataGodz punktCzasowy;
   string tytul;

public:
   Wydarzenie();
   Wydarzenie(const string title);
   Wydarzenie(const DataGodz& d, const string title);
   //Wydarzenie(const Wydarzenie&);
   //Wydarzenie(Wydarzenie&&);

   Wydarzenie& operator= (const Wydarzenie& ev);
};

#endif // DATA_HPP_INCLUDED
