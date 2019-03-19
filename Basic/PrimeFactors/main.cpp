#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

using namespace std;

//Jak nazwa wskazuje, funkcja zwraca wartosc boolowska
//w zaleznosci od tego, czy liczba jest pierwsza.
bool czyPierwsza(int64_t liczba)
{
   if(liczba==1 || liczba==0) return false;
   if(liczba==2) return true;
   if(liczba%2 == 0)
      return false;
   for(int64_t i=3; i<=static_cast<int>(std::sqrt<int64_t>(liczba)); i+=2)
   {
      if(liczba%i == 0)
      return false;
   }
   return true;
}

//dla danej liczby zwracany jest vector
//z jej czynnikami
vector <int64_t> rozklad(int64_t liczba)
{
   vector <int64_t> czynniki;

   //dla -1 0 1 wypisujemy tylko te liczby
   switch(liczba)
   {
   case -1:
      {
         czynniki.push_back(-1);
         return czynniki;
      }
   case 0:
      {
         czynniki.push_back(0);
         return czynniki;
      }
   case 1:
      {
         czynniki.push_back(1);
         return czynniki;
      }
   }

   //gdy liczba jest ujemna to dodajemy -1 do wypisywaych czynnikow
   if(liczba<0)
      {
         czynniki.push_back(-1);
         liczba = -liczba;
      }

   //sprawdzamy, czy liczba jest pierwsza
   if(czyPierwsza(liczba))
   {
      czynniki.push_back(liczba);
      return czynniki;
   }

   while(liczba%2==0)
   {
      czynniki.push_back(2);
      liczba=liczba/2;
      if(czyPierwsza(liczba))
      {
          czynniki.push_back(liczba);
               return czynniki;
      }
   }

   //wpisujemy do vector'a czynniki
   for(int64_t i=3; liczba>1;)
   {
      if(liczba%i==0)
      {
         czynniki.push_back(i);
         liczba=liczba/i;
         if(czyPierwsza(liczba))
            {
               czynniki.push_back(liczba);
               return czynniki;
            }
      }
      else i+=2;
   }

   return czynniki;
}

//zamiana ze string na int64_t
int64_t stoi64(string napis)
{
   int64_t tmp     = 0;
   int64_t p       = 1;
   bool znak    = true;
   bool czyliczba  = true;

   if(napis == "-9223372036854775808")
   {
      return -9223372036854775808;
   }

   if(napis[0]=='-') znak = false;

   for(int64_t i=napis.length()-1; i>=0; i--)
   {
      if(i!=0)
      {
         if(napis[i]>='0' && napis[i]<='9')
         {
            if(tmp+(napis[i]-48) * p < 0)throw invalid_argument("Poza zakresem!");
            tmp += (napis[i]-48) * p;
            p=p*10;
         }
         else
            czyliczba = false;
      }
      else
         if(znak==1)
         {
            tmp += (napis[i]-48) * p;
         }
         else
         {
             tmp= -tmp;
         }
   }


   if(!czyliczba)
      throw invalid_argument("Podana wartosc to nie liczba");

   return tmp;
}

//wypisywanie czynniku
void print(int64_t a)
{
   cout<<a<<"*";
}

//wypisywanie ostatniego czynnika
void print2(int64_t a)
{
   cout<<a;
}

int main(int iloscArg, char* argumenty[])
{
    if(iloscArg <2)
    {
       cerr<<"Nie podano zadnego argumentu. Podanie argumentow w postaci liczb mieszczacych sie w zmiennej typu int64_t jest niezbedne do prawidlowej pracy programu\n";
    }
    else
    {
       vector <int64_t> czynniki;
       int64_t temp;
       bool czyWypisac = true;

       for(int i=1; i<iloscArg; i++)
       {
          czyWypisac = true;
          cout<<argumenty[i]<<"=";

          try
          {
            temp = stoi64((string)argumenty[i]);
          }
          catch (invalid_argument &ia)
          {
             cerr<<"Invalid argument: "<<ia.what()<<endl;
             czyWypisac = false;
          }

          if(czyWypisac)
             {
                czynniki = rozklad(temp);
                for_each(czynniki.begin(),czynniki.end()-1,print);
                for_each(czynniki.end()-1,czynniki.end(),print2);
                cout<<endl;
             }
       }
    }
    return 0;
}
