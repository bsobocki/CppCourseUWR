#include "wyrazenia.hpp"

//Operator jedno-argumentowy
Operator1arg::Operator1arg(Wyrazenie* arg): argument1(arg) {}

//Sinus
Sinus::Sinus(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Sinus::oblicz() { return sin(argument1->oblicz()); }
string Sinus::opis() {  return "sin( " + argument1->opis() + " )" ; }
string Sinus::wypisz() { return "sin( " + argument1->opis() + " ) = " + to_string(oblicz()); }

//Cosinus
Cosinus::Cosinus(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Cosinus::oblicz() { return cos(argument1->oblicz()); }
string Cosinus::opis() { return "cos( " + argument1->opis() + " )" ; }
string Cosinus::wypisz() { return "cos( " + argument1->opis() + " ) = " + to_string(oblicz());}

//Exp
Exp::Exp(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Exp::oblicz() { return exp(argument1->oblicz()); }
string Exp::opis() { return "exp( " + argument1->opis() + " )"; }
string Exp::wypisz() { return "exp( " + argument1->opis() + " ) = " + to_string(oblicz()); }

//Ln
Ln::Ln(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Ln::oblicz() { return log(argument1->oblicz()); }
string Ln::opis() { return "ln( " + argument1->opis() + " )" ; }
string Ln::wypisz() { return "ln( " + argument1->opis() + " ) = " + to_string(oblicz()); }

//Bezwzgledna
Bezwzgledna::Bezwzgledna(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Bezwzgledna::oblicz() { return argument1->oblicz()<0 ?  -argument1->oblicz() : argument1->oblicz(); }
string Bezwzgledna::opis() { return "| " + argument1->opis() + "|"; }
string Bezwzgledna::wypisz() { return "| " + argument1->opis() + "| = " + to_string(oblicz()); }

//Przeciwna
Przeciwna::Przeciwna(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Przeciwna::oblicz() { return -(argument1->oblicz()); }
string Przeciwna::opis() {
   /* // kod sprawia, ze usuwane sa nawiasy zbyteczne, tj -(-(-1)) zamienia na -1
   if(argument1->opis()[0]=='-')
   {
      string pom = "";
      for(unsigned int i=1; i<argument1->opis().size(); i++)
         pom = argument1->opis()[i];
      return pom;
   }
   if(argument1->typ=='f' || argument1->typ=='s' || argument1->typ=='l' || argument1->typ=='z')
      return "-" + argument1->opis();
      */
   return "-(" + argument1->opis() + ")";
}
string Przeciwna::wypisz() {return opis() + " = " + to_string(oblicz()); }

//Odwrotna
Odwrotna::Odwrotna(Wyrazenie* arg): Operator1arg(arg){ typ = 'f';}
long double Odwrotna::oblicz() {
   if(argument1->oblicz()!=0)
      return 1/(argument1->oblicz());
   else
      throw invalid_argument("nie mozna dzielic przez zero!");
}
string Odwrotna::opis() {
   if(argument1->oblicz()!=0)
      return "1/(" + argument1->opis() + ")";
   else
      throw invalid_argument("nie mozna dzielic przez zero!");
}
string Odwrotna::wypisz() {
   if(argument1->oblicz()!=0)
      return opis() + " = " + to_string(oblicz());
   else
      throw invalid_argument("nie mozna dzielic przez zero!");
}

//Liczba
Liczba::Liczba(const long double k): wartosc(k) { typ = 's';}
long double Liczba::oblicz() { return wartosc; }
string Liczba::opis() { return "" + to_string(wartosc); }
string Liczba::wypisz() { return "" + to_string(wartosc); }


//Zmienna
vector<pair<string,long double>> Zmienna::variables;
void Zmienna::dodaj(const string nazw,const long double wart) {
   unsigned int i = index(nazw);
   if (i==variables.size())
      variables.push_back(make_pair(nazw,wart));
   else
      zmien(nazw,wart,i);
}
void Zmienna::zmien(const string nazw, const long double wart,const int i) { Zmienna::variables[i] = make_pair(nazw,wart);}
int Zmienna::index(string nazw) {
   for(unsigned int i=0; i<variables.size(); i++)
         if (variables[i].first == nazw)
            return i;
   return variables.size();
}
Zmienna::Zmienna(const string nazw, const long double wart) : nazwa(nazw), wartosc(wart) {
      typ = 'z';
      bool czyjuzjest = false;
      unsigned int i;
      for( i=0; i<variables.size(); i++)
         if (variables[i].first == nazw)
            {
               czyjuzjest = true;
               break;
            }
      if(!czyjuzjest)
         Zmienna::dodaj(nazw,wart);
      else
         Zmienna::zmien(nazw,wart,i);
}
Zmienna::Zmienna(const string nazw) : nazwa(nazw), wartosc(0) {typ = 'z'; Zmienna::dodaj(nazw,0.0);}
void Zmienna::zmienWartosc(const long double wart) { wartosc = wart; Zmienna::zmien(nazwa,wart,Zmienna::index(nazwa));}
long double Zmienna::znajdz(const string nazw)
{
    for(unsigned int i=0; i<variables.size(); i++)
      if (variables[i].first == nazw)
         return variables[i].second;
      return 0;
}
long double Zmienna::oblicz() { return Zmienna::znajdz(nazwa); }
string Zmienna::opis() { return nazwa; }
string Zmienna::wypisz() { return nazwa + " = " + to_string(oblicz()); }

//Pi
Pi::Pi(){ wartosc = 3.14159265358979323846; typ = 's';}
long double Pi::oblicz() { return wartosc; }
string Pi::opis() { return "PI"; }
string Pi::wypisz() { return "PI = " + to_string(oblicz()); }


//E
E::E(){ wartosc = 2.71828182846; typ = 's';}
long double E::oblicz() { return wartosc; }
string E::opis() { return "E"; }
string E::wypisz() { return "E = " + to_string(oblicz()); }


//Fi
Fi::Fi(){ wartosc = 1.6180339887; typ = 's';}
long double Fi::oblicz() { return wartosc; }
string Fi::opis() { return "FI"; }
string Fi::wypisz() { return "FI = " + to_string(oblicz()); }
