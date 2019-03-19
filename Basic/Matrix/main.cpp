#include "macierz.hpp"

using namespace std;
using namespace obliczenia;

int main()
{
   Macierz a = Macierz(4);
   cout<<a<<endl;
   cin>>a;
   a=a*a;
   cout<<a;

}
