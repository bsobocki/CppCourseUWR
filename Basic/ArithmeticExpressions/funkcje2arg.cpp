#include "wyrazenia.hpp"


//Operator dwu-argumentowy
Operator2arg::Operator2arg(Wyrazenie* arg1,Wyrazenie* arg2): Operator1arg(arg1), argument2(arg2) {}


//Dodawanie
Dodawanie::Dodawanie(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'D';}
long double Dodawanie::oblicz() { return argument1->oblicz() + argument2->oblicz(); }
string Dodawanie::opis(){ return argument1->opis() + " + " + argument2->opis();}
string Dodawanie::wypisz(){ return opis() + " = " + to_string(oblicz());}


//Odejmowanie
Odejmowanie::Odejmowanie(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'O';}
long double Odejmowanie::oblicz() { return argument1->oblicz() - argument2->oblicz(); }
string Odejmowanie::opis()
{
   if(argument2->typ == 'O' || argument2->typ == 'D')
            return  argument1->opis() + " - (" + argument2->opis() + ")";

   return argument1->opis() + " - " + argument2->opis();
}
string Odejmowanie::wypisz() { return opis() + " = " + to_string(oblicz());}

//Mnozenie
Mnozenie::Mnozenie(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'M';}
long double Mnozenie::oblicz() { return argument1->oblicz() * argument2->oblicz(); }
string Mnozenie::opis()
{
   if(argument1->typ =='D' || argument1->typ == 'O')
      {
         if(argument2->typ == 'D' || argument2->typ == 'O')
            return "(" + argument1->opis() + ") * (" + argument2->opis() + ")";
         return "(" + argument1->opis() + ") * " + argument2->opis();
      }
   if(argument2->typ == 'D' || argument2->typ == 'O')
         return  argument1->opis() + " * (" + argument2->opis() + ")";

   return argument1->opis() + " * " + argument2->opis();
}
string Mnozenie::wypisz() { return opis() + " = " + to_string(oblicz());}

//Dzielenie
Dzielenie::Dzielenie(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = ':';}
long double Dzielenie::oblicz() { return argument1->oblicz() / argument2->oblicz(); }
string Dzielenie::opis()
{
   if(argument1->typ == 'D' || argument1->typ == 'O')
      {
         if(argument2->typ == 'D' || argument2->typ == 'O')
            return "(" + argument1->opis() + ") / (" + argument2->opis() + ")";
         return "(" + argument1->opis() + ") / " + argument2->opis();
      }
   if(argument2->typ == 'D' || argument2->typ == 'O')
         return  argument1->opis() + " / (" + argument2->opis() + ")";

   return argument1->opis() + " / " + argument2->opis();
}
string Dzielenie::wypisz() { return opis() + " = " + to_string(oblicz());}

//Potegowanie
Potegowanie::Potegowanie(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'P';}
long double Potegowanie::oblicz() { return pow(argument1->oblicz(),argument2->oblicz()); }
string Potegowanie::opis()
{
   if(argument1->typ == 's' || argument1->typ == 'f' || argument1->typ == 'z')
     {
        if(argument2->typ != 's' && argument2->typ != 'f' && argument2->typ != 'z' && argument2->typ!='P')
            return argument1->opis() + " ^ (" + argument2->opis() + ")";
        return argument1->opis() + " ^ " + argument2->opis() ;
     }
   if(argument2->typ != 's' && argument2->typ != 'f' && argument2->typ != 'z')
            return "(" + argument1->opis() + ") ^ (" + argument2->opis() + ")";

   return "(" + argument1->opis() + ") ^ " + argument2->opis();
}
string Potegowanie::wypisz() { return opis() + " = " + to_string(oblicz());}

//Logarytm
Logarytm::Logarytm(Wyrazenie* arg1, Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'L';}
long double Logarytm::oblicz() { return log(argument2->oblicz())/log(argument1->oblicz()); }
string Logarytm::opis()
{
   if(argument1->typ == 's' || argument1->typ == 'f' || argument1->typ == 'z')
      {
         if(argument2->typ == 's' || argument2->typ == 'f' || argument2->typ == 'z')
            return "log " + argument1->opis() + "  " + argument2->opis() ;
         return "log " + argument1->opis() + "  (" + argument2->opis() + ")";
      }
   else if (argument2->typ == 's' || argument2->typ == 'f' || argument2->typ == 'z')
      return "log (" + argument1->opis() + ")  " + argument2->opis() ;

   return "log (" + argument1->opis() + ")  (" + argument2->opis() + ")";
}
string Logarytm::wypisz() { return opis() + " = " + to_string(oblicz());}

//Modulo
Modulo::Modulo(Wyrazenie* arg1,Wyrazenie* arg2) : Operator2arg(arg1,arg2) {typ = 'M';}
long double Modulo::oblicz() { return fmod(argument1->oblicz(),argument2->oblicz())  ; }
string Modulo::opis()
{
  if(argument1->typ == 's' || argument1->typ == 'f' || argument1->typ == 'z')
      {
         if(argument2->typ == 's' || argument2->typ == 'f' || argument2->typ == 'z')
            return  argument1->opis() + " % " + argument2->opis() ;
         return argument1->opis() + " % (" + argument2->opis() + ")";
      }
   else if (argument2->typ == 's' || argument2->typ == 'f' || argument2->typ == 'z')
      return "(" + argument1->opis() + ") % " + argument2->opis() ;

   return "(" + argument1->opis() + ") % (" + argument2->opis() + ")";
}
string Modulo::wypisz() { return opis() + " = " + to_string(oblicz());}
