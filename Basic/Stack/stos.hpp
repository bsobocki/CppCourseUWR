#ifndef STOS_HPP_INCLUDED
#define STOS_HPP_INCLUDED
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdexcept>
#include <utility>

using namespace std;

class Stos
{
   int _ile;
   int _pojemnosc;
   string* stos;

public:
   //konstruktory
   Stos();
   Stos(const int& nowaPojemnosc);
   Stos(const Stos&& other);
   Stos(const Stos& other);
   Stos(initializer_list<string> lista);

   //operatory
   Stos & operator=(Stos&&);
   Stos & operator=(const Stos&);

   //destruktor
   ~Stos();

   //metody klasy Stos
   void wloz(const string &n);
   void wypiszStos();
   string sciagnij();
   string sprawdz() const;
   int rozmiar() const;
   int poj() const;

};



#endif // STOS_HPP_INCLUDED
