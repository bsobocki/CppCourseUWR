#include "stos.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
   Stos first(3);

   first.wloz("pierwszy string");
   first.wloz("drugi string");
   first.wypiszStos();

   Stos second(first);

   second.wypiszStos();

   Stos third(Stos(7));

   third.wloz("nowy");

   second = third;
   second.wypiszStos();
   cout<<second.poj()<<endl;
   cout<<second.rozmiar();

}

/*
bedzie odejmowane za brak...
1) flagi -Wextra -Wall
2) listy inicjalizacyjne w konstruktorach (np ile(3), kto("Bartek"))
*/
