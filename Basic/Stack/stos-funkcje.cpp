#include "stos.hpp"
using namespace std;

//konstruktor delegatowy
Stos::Stos(): _ile(0), _pojemnosc(1), stos(new string[_pojemnosc]){}

//konstruktor kopiujacy
Stos::Stos(const Stos &other): _ile(other._ile), _pojemnosc(other._pojemnosc), stos(new string[other._pojemnosc])
{
   for(int i=0; i<other._ile; i++)
      stos[i]=other.stos[i];
}

//konstruktor po liscie
Stos::Stos(initializer_list<string> lista): _ile (0), _pojemnosc(lista.size()), stos (new string[lista.size()])
{
   for(auto x:lista)
      wloz(x);
}

//konstruktor po pojemnosci
Stos::Stos(const int &nowaPojemnosc): _ile(0),  _pojemnosc(nowaPojemnosc), stos(new string[_pojemnosc]){}

//konstruktor przepisujacy
Stos::Stos(const Stos&& other): _ile(other._ile), _pojemnosc(other._pojemnosc), stos(new string[other._ile])
{
   for(int i=0; i<other._ile; i++)
      stos[i]=other.stos[i];
}

//operator dla Rvalue
Stos & Stos::operator=(Stos&&other)
{
   if(this == &other) return *this;
   _pojemnosc = other._pojemnosc;
   _ile = other._ile;
   stos = other.stos;
   other.stos = nullptr;
   return *this;
}

//operator dla Lvalue
Stos & Stos::operator=(const Stos& other)
{
   return *this = Stos(other);
}

//wkladanie nowego elementu
void Stos::wloz(const string& n)
{
   if(_ile==_pojemnosc)
      throw range_error("Stos jest pelny!");
   else
   {
      stos[_ile] = n;
      _ile++;
   }
}

//sprawdzenie pierwszego z gory elementu
string Stos::sprawdz() const
{
   if(_ile>0)
      return stos[_ile-1];
   else
      throw range_error("Stos jest pusty!");
}

//metoda sciagajaca ostatni element
string Stos::sciagnij()
{
   string sciagniety = stos[--_ile]; //nasz sciagniety string
   stos[_ile+=1].clear(); // usuwamy string sciagniety
   return sciagniety;
}

//pobieranie rozmiaru
int Stos::rozmiar() const
{
   return _ile;
}

//pobieranie rozmiaru
int Stos::poj() const
{
   return _pojemnosc;
}

//destruktor
Stos::~Stos()
{
   delete [] stos;
}

//wypisujemy stos
void Stos::wypiszStos()
{
   for(int i=0; i<_ile; i++)
      cout<<stos[i]<<endl;
}
