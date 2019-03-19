#include "wyrazenia.hpp"

using namespace std;

int main()
{
   //tworzymy wskaznik na wyrazenie
    Wyrazenie* wyr;

    wyr = new Liczba((new Pi())->oblicz()/2);
    cout<<wyr->wypisz()<<endl;

    wyr = new Dodawanie(new Sinus(wyr),new Liczba(7));
    cout<<wyr->wypisz()<<endl;

    //PI-(2+(x+42)*7)
    wyr = new Odejmowanie(
                      new Pi(),
                      new Dodawanie(
                         new Liczba(2),
                         new Mnozenie(
                            new Dodawanie(
                               new Zmienna("x"),
                               new Liczba(42)),
                            new Liczba(7)
                            )

                      )
                  );
   cout<<wyr->wypisz()<<endl;

   wyr = new Ln(new E());
   cout<<wyr->wypisz()<<endl;

   wyr = new Dodawanie(
                       new Odejmowanie(
                                       new Liczba(42),
                                       new Dzielenie(
                                                     new Liczba (42),
                                                     new Liczba(7))),

                       new Mnozenie(
                                    new Potegowanie(
                                                    new E(),
                                                    new Ln(new Liczba(7))),
                                    new Liczba(6)
                                    ));
   cout<<wyr->wypisz()<<endl;

   wyr = new Logarytm(new Liczba(1.0/4),new Liczba(2));
   cout<<wyr->wypisz()<<endl;

   Zmienna* iks = new Zmienna("x");

   //cos((x+1)*x)/e^x^2
   wyr = new Dzielenie(new Cosinus(
                                    new Mnozenie(
                                                 new Dodawanie(
                                                               iks,
                                                               new Liczba(1.0)),
                                                 iks)),
                       new Potegowanie(
                                       new E(),
                                       new Potegowanie(iks,new Liczba(2.0))));
   cout<<wyr->wypisz()<<endl;


   //((x-1)*x)/2
   wyr = new Dzielenie(
                        new Mnozenie(
                                     new Odejmowanie(
                                                     iks,
                                                     new Liczba(1.0)),
                                     iks),
                       new Liczba(2.0));
   cout<<wyr->wypisz()<<endl;


   //(3+5)/(2+x*7)
   iks->zmienWartosc(1);
   wyr = new Dzielenie(
                       new Dodawanie(
                                     new Liczba(3.0),
                                     new Liczba(5.0)),
                       new Dodawanie(
                                     new Liczba (2.0),
                                     new Mnozenie(
                                                  iks,
                                                  new Liczba(7.0))));
    cout<<wyr->wypisz()<<endl;


    //2+x*7-(y*3+5)
    wyr = new Odejmowanie(
                          new Dodawanie(
                                        new Liczba(2.0),
                                        new Mnozenie(iks,new Liczba(7))),
                          new Dodawanie(
                                        new Mnozenie(
                                                     new Zmienna("y"),
                                                     new Liczba(3.0)),
                                        new Liczba(3.0)));

    Zmienna::zmien("x",10.0,Zmienna::index("x"));
    cout<<wyr->wypisz()<<endl;

    wyr = new Przeciwna(new Przeciwna(new Liczba(-1)));
    cout<<wyr->wypisz()<<endl;

    wyr = new Odwrotna(new Liczba(0));

    try
    {cout<<wyr->wypisz()<<endl;}
    catch (invalid_argument& a)
    {
       cout<<a.what()<<endl;
    }

    cout<<0.0*(-1);
    return 0;
}
