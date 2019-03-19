#include "data.hpp"

using namespace std;

constexpr int Data::dniwmiesiacach[2][13];
constexpr int Data::dniodpoczroku[2][13];

//________gettery

short Data::get_dzien() const
{
   return dzien;
}

short Data::get_miesiac() const
{
   return miesiac;
}

short Data::get_rok() const
{
   return rok;
}

//_______konkstruktory

Data::Data()
{
   //pobieranie czasu z komputera
   using namespace std::chrono;

   chrono::system_clock::time_point today = system_clock::now();
   std::time_t end_time = std::chrono::system_clock::to_time_t(today);
   stringstream buffer;
   string date="";

   //string zamieniamy na pojedyncze zmienne
   buffer<<ctime(&end_time);

   for(int i=4; i<buffer.str().size(); i++)
      date+= buffer.str()[i];

   //pobieramy miesiac
   string month="";
   month = month + date[0] + date[1] + date[2];
   int mon;

      if(month=="Jan") mon=1;
      if(month=="Feb") mon=2;
      if(month=="Mar") mon=3;
      if(month=="Apr") mon=4;
      if(month=="May") mon=5;
      if(month=="Jun") mon=6;
      if(month=="Jul") mon=7;
      if(month=="Aug") mon=8;
      if(month=="Sep") mon=9;
      if(month=="Oct") mon=10;
      if(month=="Nov") mon=11;
      if(month=="Dec") mon=12;

   //pobieramy dzien
   int day = ((int)date[4] - 48)*10 + ((int)date[5]-48);

   //pobieramy rok
   string year = "";
   int yearI=0;
   int p=1;

   for(int i=buffer.str().size()-2; buffer.str()[i]!=' '; i--)
      year+=buffer.str()[i];

   for(int i=0; i<year.size(); i++)
   {
      yearI += ((int)year[i]-48)*p;
      p*=10;
   }

   dzien   = day;
   miesiac = mon;
   rok     = yearI;
}

Data::Data(short day, short month, short year)
{
   if(czyPoprawnaData(day,month,year))
   {
      dzien   = day;
      miesiac = month;
      rok     = year;
   }
   else
   {
      cerr<<"Niepoprawna data!";
      dzien   = 1;
      miesiac = 1;
      rok     = 0;
   }
}

Data::Data(const Data& d)
{
   this->dzien   = d.get_dzien();
   this->miesiac = d.get_miesiac();
   this->rok     = d.get_rok();
}

Data::Data(Data&& d)
{
   this->dzien   = d.get_dzien();
   this->miesiac = d.get_miesiac();
   this->rok     = d.get_rok();
}

//_______operatory

Data& Data::operator = (const Data& d)
{
   return *this=Data(d);
}

Data& Data::operator= (Data&& d)
{
   this->dzien   = d.get_dzien();
   this->miesiac = d.get_miesiac();
   this->rok     = d.get_rok();
   return *this;
}

int Data::operator - (Data& d)
{
    return abs(ilednioddaty() - d.ilednioddaty());
}

Data& Data::operator ++ ()
{
    bool czyprzest = 0;

   if(przestepny(rok))
      czyprzest = 1;

   if(dzien+1 > dniwmiesiacach[czyprzest][miesiac])
   {
      if(miesiac+1 > 12)
         {
            rok++;
            miesiac = 1;
            dzien = 1;
         }
      else
         {
            miesiac++;
            dzien = 1;
         }
   }
   else
      dzien++;

   return *this;
}

Data& Data::operator -- ()
{
   bool czyprzest = 0;

   if(przestepny(rok))
      czyprzest = 1;

   if(dzien-1 <= 0)
   {
      if(miesiac-1 <= 0)
         {
            rok--;
            miesiac = 12;
            czyprzest = 0;
            if(przestepny(rok)) czyprzest = 1;
            dzien = Data::dniwmiesiacach[czyprzest][miesiac];
         }
      else
         {
            miesiac--;
            dzien = dniwmiesiacach[czyprzest][miesiac];
         }
   }
   else
      dzien--;

   return *this;
}

Data& Data::operator -= (int d)
{
   for(int i=1; i<=d; i++)
      {
         if(!czyPoprawnaData(dzien,miesiac,rok))
         {
            cerr<<"Data niepoprawna!"<<endl;
            break;
         }
         --*this;
      }
   return *this;
}

Data& Data::operator += (int d)
{
   for(int i=1; i<=d; i++)
      {
         if(!czyPoprawnaData(dzien,miesiac,rok))
         {
            cerr<<"Data niepoprawna!"<<endl;
            return *this;
         }
         ++*this;
      }
   return *this;
}

//__________metody

bool Data::przestepny(short year)
{
   return ((year%4==0 && year%100!=0) || year%400==0);
}

bool Data::czyPoprawnaData(short day, short month, short year)
{
   if(month<=12 && month>0)
      if(year>=0)
      {
         if(przestepny(year))
            {if(day<=dniwmiesiacach[1][month] && day>0)
               return true;}
         else //jesli nie przestepny
            {if(day<=dniwmiesiacach[0][month] && day>0)
                return true;}
      }
   return false;
}

int Data::ilednioddaty()
{
   //virtualna data 01.01.00r.
   //zamieniamy this na ilosc dni od (this.rok-1) *(1)
   //zamieniamy this.rok na ilosc dni             *(2)
   //odejmujemy 1 od (1), bo 01.01
   //dodajemy *(2)

   int ilosc1; //ilosc dni od roku poprzedniego *(1)
   int czyPrzest   = 0;
   int iloscPrzest = 0; //ilsc lat przestepnych w danym przedziale lat *(2)-(data.rok * 365)

   if(przestepny(get_rok()))
      czyPrzest = 1;

   ilosc1 = get_dzien()-1 + dniodpoczroku[czyPrzest][get_miesiac()-1];

   iloscPrzest=get_rok()/4 - get_rok()/100;

   return ilosc1 + (rok*365) + iloscPrzest; // *(1) + *(2)
}
