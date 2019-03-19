#ifndef MACIERZ_HPP_INCLUDED
#define MACIERZ_HPP_INCLUDED
#include <iostream>

using namespace std;

namespace obliczenia
{

   class wyjatek:public exception{

   protected:
      const char* w;

   public:
      wyjatek(const char* wyj);
      virtual const char* what() =0;
   };

   class rozmiary_nie_pasuja: public wyjatek
   {
   public:
      rozmiary_nie_pasuja(const char* wyj);
      const char* what();
   };

   class nie_kwadratowa : public wyjatek
   {
   public:
      nie_kwadratowa(const char* wyj);
      const char* what();
   };



   class Macierz{

   public:
      int** matrix;
      int a,b;

      //konstruktor tworzacy macierz diagonalna
      Macierz(int n);
      //konstruktor tworzacy zerowa macierz prostokatna
      Macierz(int n, int m);
      //konstruktor kopiujacy
      Macierz(const Macierz& mac);
      //konstruktor przepisujacy
      Macierz(Macierz&& mac);
      //destruktor
      ~Macierz();
      //przypisanie kopiujace
      Macierz & operator = (const Macierz& mat);
      //przypisanie przepisujace
      Macierz & operator = (Macierz&& mat);
      //operatory
      Macierz operator* (const int alfa);
      Macierz operator+ (const Macierz& mat);
      Macierz operator+ (Macierz&& mat);
      Macierz operator* (const Macierz& mat);
      Macierz operator* (Macierz&& mat);
      Macierz operator- (const Macierz& mat);
      Macierz operator- (Macierz&& mat);
      Macierz operator! ();
      Macierz & operator+= (const Macierz& mat);
      Macierz & operator+= (Macierz&& mat);
      Macierz & operator-= (const Macierz& mat);
      Macierz & operator-= (Macierz&& mat);
      Macierz & operator*= (const Macierz& mat);
      Macierz & operator*= (Macierz&& mat);
      Macierz & operator*= (const int alfa);

      friend istream & operator>> (istream &we, Macierz &mat);
      friend ostream & operator<< (ostream &wy, const Macierz &mat);
   };

istream & operator>> (istream &we, Macierz &mat);
ostream & operator<< (ostream &wy, const Macierz &mat);
}

#endif // MACIERZ_HPP_INCLUDED
