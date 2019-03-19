#ifndef WYRAZENIA_HPP_INCLUDED
#define WYRAZENIA_HPP_INCLUDED
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

/* zamiana wartosci na napis */

template<typename T>
const string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}


/* klasy abstrakcyjne */

class  Wyrazenie
{
public :
   char typ; // | f - funkcja | o - operator | s - stala | l - liczba | z - zmienna |
   virtual long double oblicz() =0  ;
   virtual string opis() =0;
   virtual string wypisz() =0;
};

class Operator1arg : public Wyrazenie
{
protected:
   Wyrazenie* argument1;

public:
   Operator1arg(Wyrazenie * arg);

public:
   virtual long double oblicz() =0;
   virtual string opis() =0;
   virtual string wypisz() =0;
};

class Operator2arg : public Operator1arg
{
protected:
  // Wyrazenie* argument1;
   Wyrazenie* argument2;

public:
   Operator2arg(Wyrazenie* arg1,Wyrazenie* arg2);

public:
   virtual long double oblicz() =0;
   virtual string opis() =0;
   virtual string wypisz() =0;
};


/* funkcje jednoargumentowe: */

class Sinus : public Operator1arg
{
public:
   Sinus();
   Sinus(const Sinus&);
   Sinus(Sinus&&);
   Sinus(Wyrazenie* arg);

   long double oblicz() ;
   string opis();
   string wypisz();
};

class Cosinus : public Operator1arg
{
public:
   Cosinus();
   Cosinus(const Cosinus&);
   Cosinus(Cosinus&&);
   Cosinus(Wyrazenie* arg);

   long double oblicz();
   string opis();
   string wypisz();
};

class Exp : public Operator1arg
{
public:
   Exp();
   Exp(const Exp&);
   Exp(Exp&&);
   Exp(Wyrazenie* arg);

   long double oblicz() ;
   string opis() ;
   string wypisz() ;
};

class Ln : public Operator1arg
{
public:
   Ln();
   Ln(const Ln&);
   Ln(Ln&&);
   Ln(Wyrazenie* arg);

   long double oblicz();
   string opis();
   string wypisz();
};

class Bezwzgledna : public Operator1arg
{
public:
   Bezwzgledna() = delete;
   Bezwzgledna(const Bezwzgledna&);
   Bezwzgledna(Bezwzgledna&&);
   Bezwzgledna(Wyrazenie* arg);

   long double oblicz();
   string opis();
   string wypisz();
};

class Przeciwna : public Operator1arg
{
public:
   Przeciwna();
   Przeciwna(const Przeciwna&);
   Przeciwna(Przeciwna&&);
   Przeciwna(Wyrazenie* arg);

   long double oblicz();
   string opis();
   string wypisz();
};

class Odwrotna : public Operator1arg
{
public:
   Odwrotna();
   Odwrotna(const Odwrotna&);
   Odwrotna(Odwrotna&&);
   Odwrotna(Wyrazenie* arg);

   long double oblicz();
   string opis();
   string wypisz();
};


/* funkcje dwuargumentowe: */

class Dodawanie : public Operator2arg
{
public:
   Dodawanie();
   Dodawanie(const Dodawanie&);
   Dodawanie(Dodawanie&&);
   Dodawanie(Wyrazenie* arg1,Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};


class Odejmowanie : public Operator2arg
{
public:
   Odejmowanie();
   Odejmowanie(const Odejmowanie&);
   Odejmowanie(Odejmowanie&&);
   Odejmowanie(Wyrazenie* arg1,Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};


class Mnozenie : public Operator2arg
{
public:
   Mnozenie();
   Mnozenie(const Mnozenie&);
   Mnozenie(Mnozenie&&);
   Mnozenie(Wyrazenie* arg1,Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};


class Dzielenie : public Operator2arg
{
public:
   Dzielenie();
   Dzielenie(const Dzielenie&);
   Dzielenie(Dzielenie&&);
   Dzielenie(Wyrazenie* arg1,Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};


class Potegowanie : public Operator2arg
{
public:
   Potegowanie();
   Potegowanie(const Potegowanie&);
   Potegowanie(Potegowanie&&);
   Potegowanie(Wyrazenie* arg1, Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};

class Logarytm : public Operator2arg
{
public:
   Logarytm();
   Logarytm(const Logarytm&);
   Logarytm(Logarytm&&);
   Logarytm(Wyrazenie* arg1, Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};

class Modulo : public Operator2arg
{
public:
   Modulo();
   Modulo(const Modulo&);
   Modulo(Modulo&&);
   Modulo( Wyrazenie* arg1, Wyrazenie* arg2);

   long double oblicz();
   string opis();
   string wypisz();
};


//klasy reprezentujacy zmienne, stale i liczby:

class Zmienna : public Wyrazenie
{
private:
   static vector<pair<string,long double>> variables;

private:
    string nazwa;
    long double wartosc;

public:
   Zmienna(const string nazw, const long double wart);
   Zmienna(const string nazw);

   void zmienWartosc(const long double wart);
   static long double znajdz(const string nazw);
   static void dodaj(const string nazw, const long double wart);
   static void zmien(const string nazw, const long double wart, const int i);
   static int index(const string nazw);
   long double oblicz();
   string opis();
   string wypisz();
};


class Liczba : public Wyrazenie
{
private:
   long double wartosc;

public:
   Liczba(const long double k);

   long double oblicz();
   string opis();
   string wypisz();
};

class Stala : public Wyrazenie
{
protected:
   long double wartosc;
};


class Pi : public Stala
{
public:
   Pi();

   long double oblicz();
   string opis();
   string wypisz();
};


class E : public Stala
{
public:
   E();

   long double oblicz();
   string opis();
   string wypisz();
};


class Fi : public Stala
{
public:
   Fi();

   long double oblicz();
   string opis();
   string wypisz();
};

#endif // WYRAZENIA_HPP_INCLUDED
