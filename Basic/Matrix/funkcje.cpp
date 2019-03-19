#include "macierz.hpp"

using namespace obliczenia;
using namespace std;


//BLEDY

wyjatek::wyjatek(const char* wyj): w(wyj) {}

rozmiary_nie_pasuja::rozmiary_nie_pasuja(const char* wyj): wyjatek(wyj) {}
const char* rozmiary_nie_pasuja::what() {return w;}

nie_kwadratowa::nie_kwadratowa(const char* wyj): wyjatek(wyj) {}
const char* nie_kwadratowa::what() {return w;}

//MACIERZ

Macierz::Macierz(int n): a(n), b(n)
{
   matrix = new int*[n];
   for(int i=0; i<n; i++)
      matrix[i] = new int[n];

   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] = 0;
}

Macierz::Macierz(int n, int m): a(n), b(n)
{
   matrix = new int*[n];
   for(int i=0; i<n; i++)
      matrix[i] = new int[m];

   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] = 0;
}

Macierz::Macierz(const Macierz& mat): matrix(mat.matrix) {}
Macierz::Macierz(Macierz&& mat): matrix(mat.matrix) {}
Macierz::~Macierz()
{
   for(int i=0; i<a; i++)
         delete [] matrix[i];
   delete [] matrix;
}


//OPERATORY

Macierz & Macierz::operator = (const Macierz& mat)
{
   a = mat.a;
   b = mat.b;
   matrix = mat.matrix;
   return *this;
}
Macierz & Macierz::operator = (Macierz&& mat)
{
   a = mat.a;
   b = mat.b;
   matrix = mat.matrix;
   delete &mat;
   return *this;
}

Macierz Macierz::operator* (const int alfa)
{
   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] *= alfa;
   return *this;
}

Macierz Macierz::operator+ (const Macierz& mat)
{
   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] += mat.matrix[i][j];
   return *this;
}
Macierz Macierz::operator+ (Macierz&& mat)
{
   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] += mat.matrix[i][j];
   delete &mat;
   return *this;
}



Macierz Macierz::operator- (const Macierz& mat)
{
   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] -= mat.matrix[i][j];
   return *this;
}
Macierz Macierz::operator- (Macierz&& mat)
{
   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
         matrix [i][j] -= mat.matrix[i][j];
   delete &mat;
   return *this;
}






Macierz Macierz::operator* (const Macierz& mat)
{
   Macierz m(a,b);
   long int s = 0;

   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
      {
         for(int z=0; z<b; z++)
            s+= matrix[i][j] * mat.matrix[j][i];
          m.matrix[i][j] = s;
      }

   return m;
}
Macierz Macierz::operator* (Macierz&& mat)
{
   Macierz m(a,b);
   long int s = 0;

   for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
      {
         for(int z=0; z<b; z++)
            s+= matrix[i][j] * mat.matrix[j][i];
          m.matrix[i][j] = s;
      }
   delete &mat;
   return m;
}




/*

Macierz & Macierz::operator+= (const Macierz& mat)
{
   return this = &(*this+mat);
}
Macierz & Macierz::operator+= (Macierz&& mat)
{
   return this &(*this+mat);
}




Macierz & Macierz::operator-= (const Macierz& mat)
{
   return *this-mat;
}
Macierz & Macierz::operator-= (Macierz&& mat)
{
   return *this-mat;
}




Macierz & Macierz::operator*= (const Macierz& mat)
{
   return *this*mat;
}
Macierz & Macierz::operator*= (Macierz&& mat)
{
   return *this*mat;
}




Macierz & Macierz::operator*= (const int alfa)
{
   return *this*alfa;
}

*/


istream & obliczenia::operator>> (istream &we, Macierz &mat)
{
   for(int i=0; i<mat.a; i++)
      for(int j=0; j<mat.b; j++)
         we>>mat.matrix[i][j];
         return we;
}

ostream & obliczenia::operator<< (ostream &wy, const Macierz &mat)
{
   for(int i=0; i<mat.a; i++)
   {
      for(int j=0; j<mat.b; j++)
         wy<<" "<<mat.matrix[i][j];
      wy<<endl;
   }
   return wy;
}
