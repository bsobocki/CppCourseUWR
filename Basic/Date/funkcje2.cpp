#include "data.hpp"

using namespace std;

//________gettery

short DataGodz::get_godzina() const
{
   return godzina;
}

short DataGodz::get_minuty() const
{
   return minuty;
}

short DataGodz::get_sekundy() const
{
   return sekundy;
}

//_______konkstruktory

DataGodz::DataGodz()
{
   //pobieranie czasu z komputera
   using namespace std::chrono;

   chrono::system_clock::time_point today = system_clock::now();
   std::time_t end_time = std::chrono::system_clock::to_time_t(today);
   stringstream buffer;
   string date="";

   //string zamieniamy na pojedyncze zmienne
   buffer<<ctime(&end_time);

   for(int i=4; i<(int)buffer.str().size(); i++)
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

   for(int i=(int)buffer.str().size()-2; buffer.str()[i]!=' '; i--)
      year+=buffer.str()[i];

   for(int i=0; i<(int)year.size(); i++)
   {
      yearI += ((int)year[i]-48)*p;
      p*=10;
   }

   int hour = ((int)date[7] - 48)*10 + ((int)date[8]-48);
   int minu = ((int)date[10] - 48)*10 + ((int)date[11]-48);
   int sec  = ((int)date[13] - 48)*10 + ((int)date[14]-48);

   dzien   = day;
   miesiac = mon;
   rok     = yearI;
   godzina = hour;
   minuty  = minu;
   sekundy = sec;
}

DataGodz::DataGodz(short hour, short minutes, short seconds)
{
   if(!(hour<0 || minutes<0 || seconds<0 || hour>=24 || minutes>=60 || seconds>=60))
   {
      Data temp;
      dzien   = temp.get_dzien();
      miesiac = temp.get_miesiac();
      rok     = temp.get_rok();
      godzina = hour;
      minuty  = minutes;
      sekundy = seconds;
   }
   else
   {
      cerr<<"Niepoprawna data!";
      dzien   = 1;
      miesiac = 1;
      rok     = 0;
      godzina = 0;
      minuty  = 0;
      sekundy = 0;
   }
}

DataGodz::DataGodz(const Data& d,short hour, short minutes, short seconds)
{
   if(!(hour<0 || minutes<0 || seconds<0 || hour>=24 || minutes>=60 || seconds>=60))
   {
      dzien   = d.get_dzien();
      miesiac = d.get_miesiac();
      rok     = d.get_rok();
      godzina = hour;
      minuty  = minutes;
      sekundy = seconds;
   }
   else
   {
      cerr<<"Niepoprawna data!";
      dzien   = 1;
      miesiac = 1;
      rok     = 0;
      godzina = 0;
      minuty  = 0;
      sekundy = 0;
   }
}

DataGodz::DataGodz(const DataGodz& d)
{
   dzien   = d.get_dzien();
   miesiac = d.get_miesiac();
   rok     = d.get_rok();
   godzina = d.get_godzina();
   minuty  = d.get_minuty();
   sekundy = d.get_sekundy();
}

DataGodz::DataGodz(DataGodz&& d)
{
   dzien   = d.get_dzien();
   miesiac = d.get_miesiac();
   rok     = d.get_rok();
   godzina = d.get_godzina();
   minuty  = d.get_minuty();
   sekundy = d. get_sekundy();
}

//_______operatory

DataGodz& DataGodz::operator = (const DataGodz& d)
{
   return *this=DataGodz(d);
}

DataGodz& DataGodz::operator = (DataGodz&& d)
{
   dzien   = d.get_dzien();
   miesiac = d.get_miesiac();
   rok     = d.get_rok();
   godzina = d.get_godzina();
   minuty  = d.get_minuty();
   sekundy = d. get_sekundy();
   return *this;
}

bool DataGodz::operator > (const DataGodz& d)
{
   if(rok>d.get_rok())
          return true;
   else if(rok==d.get_rok())
   {
      if(miesiac>d.get_miesiac())
         return true;
      else if(miesiac==d.get_miesiac())
      {
         if(dzien>d.get_dzien())
         return true;
         else if(dzien==d.get_dzien())
         {
            if(godzina>d.get_godzina())
               return true;
            else if(godzina==d.get_godzina())
            {
               if(minuty>d.get_minuty())
                  return true;
               else if(minuty==d.get_minuty())
               {
                   if(sekundy>d.get_sekundy())
                     return true;
                   else

                      return false;

               }

               else
                  return true;

            }
            else return false;

         }
         else return false;

      }
      else return false;

   }   return true;

   return false;
}

bool DataGodz::operator == (const DataGodz& d)
{
   return (rok==d.get_rok() && miesiac==d.get_miesiac() && dzien==d.get_dzien() && godzina==d.get_godzina() && minuty==d.get_minuty() && sekundy==d.get_sekundy());
}

int operator - (DataGodz& d1, DataGodz& d2)
{

  int dni   = 0;
  int godzW = 0; //wiksze wartosci "W"
  int godzM = 0; //mniejsze wartosci "M"
  int minsW = 0;
  int minsM = 0;
  int sekW  = 0;
  int sekM  = 0;

   dni = abs(d1.dnioddaty() - d2.dnioddaty());

   if(d1.get_rok()==d2.get_rok() && d1.get_miesiac()==d2.get_miesiac() && d1.get_dzien()==d2.get_dzien())
   {
      if(d1.get_godzina() < d2.get_godzina())
      {
         godzM = d1.get_godzina();
         minsM = d1.get_minuty();
         sekM  = d1.get_sekundy();
         godzW = d2.get_godzina();
         minsW = d2.get_minuty();
         sekW  = d2.get_sekundy();
      }
      else if(d1.get_godzina() == d2.get_godzina())
       {
         if(d1.get_minuty() < d2.get_minuty())
         {
            godzM = d1.get_godzina();
            minsM = d1.get_minuty();
            sekM  = d1.get_sekundy();
            godzW = d2.get_godzina();
            minsW = d2.get_minuty();
            sekW  = d2.get_sekundy();
         }
         else if (d1.get_minuty() == d2.get_minuty())
         {
            if(d1.get_sekundy() < d2.get_sekundy())
            {
               godzM = d1.get_godzina();
               minsM = d1.get_minuty();
               sekM  = d1.get_sekundy();
               godzW = d2.get_godzina();
               minsW = d2.get_minuty();
               sekW  = d2.get_sekundy();
            }
            else if(d1.get_sekundy() == d2.get_sekundy())
               {return dni*3600*24;}
            else
            {
               godzW = d1.get_godzina();
               minsW = d1.get_minuty();
               sekW  = d1.get_sekundy();
               godzM = d2.get_godzina();
               minsM = d2.get_minuty();
               sekM  = d2.get_sekundy();
            }
         }
         else
         {
            godzW = d1.get_godzina();
            minsW = d1.get_minuty();
            sekW  = d1.get_sekundy();
            godzM = d2.get_godzina();
            minsM = d2.get_minuty();
            sekM  = d2.get_sekundy();
         }
       }
       else
       {
         godzW = d1.get_godzina();
         minsW = d1.get_minuty();
         sekW  = d1.get_sekundy();
         godzM = d2.get_godzina();
         minsM = d2.get_minuty();
         sekM  = d2.get_sekundy();
       }
   }
   else
   {
       if(d1.get_rok() < d2.get_rok())
      {
         godzM = d1.get_godzina();
         minsM = d1.get_minuty();
         sekM  = d1.get_sekundy();
         godzW = d2.get_godzina();
         minsW = d2.get_minuty();
         sekW  = d2.get_sekundy();
      }
      else if(d1.get_rok() == d2.get_rok())
       {
         if(d1.get_miesiac() < d2.get_miesiac())
         {
            godzM = d1.get_godzina();
            minsM = d1.get_minuty();
            sekM  = d1.get_sekundy();
            godzW = d2.get_godzina();
            minsW = d2.get_minuty();
            sekW  = d2.get_sekundy();
         }
         else if (d1.get_miesiac() == d2.get_miesiac())
         {
            if(d1.get_dzien() < d2.get_dzien())
            {
               godzM = d1.get_godzina();
               minsM = d1.get_minuty();
               sekM  = d1.get_sekundy();
               godzW = d2.get_godzina();
               minsW = d2.get_minuty();
               sekW  = d2.get_sekundy();
            }
            else if(d1.get_dzien() == d2.get_dzien())
               {return dni*3600*24;}
            else
            {
               godzW = d1.get_godzina();
               minsW = d1.get_minuty();
               sekW  = d1.get_sekundy();
               godzM = d2.get_godzina();
               minsM = d2.get_minuty();
               sekM  = d2.get_sekundy();
            }
         }
         else
         {
            godzW = d1.get_godzina();
            minsW = d1.get_minuty();
            sekW  = d1.get_sekundy();
            godzM = d2.get_godzina();
            minsM = d2.get_minuty();
            sekM  = d2.get_sekundy();
         }
       }
       else
       {
         godzW = d1.get_godzina();
         minsW = d1.get_minuty();
         sekW  = d1.get_sekundy();
         godzM = d2.get_godzina();
         minsM = d2.get_minuty();
         sekM  = d2.get_sekundy();
       }
   }

    //cout<<"wieksze "<<godzW<<" aaa "<<minsW<<" aaa "<<sekW<<endl;;

    if(sekW<sekM) {minsW--; sekW+=60;}
    if(minsW<minsM)
    {
       godzW--;
       if(sekW<sekM) minsW+=59;
       else minsW+=60;
    }
    if(godzW<godzM)
    {
       if(minsW<minsM) godzW+=23;
       else godzW+=24;
       dni--;
    }
      //cout<<" ilegodz "<<godz<<" ilemin "<<mins<< " ilesek "<<sek<<endl;
      //cout<<"odejmowanie : "<<dni*3600*24<<" | "<<(godzW - godzM)*3600<< " | "<<(minsW - minsM)*60<< " | "<<(sekW - sekM)<<endl;
      return dni*3600*24 + (godzW - godzM)*3600 + (minsW - minsM)*60 + (sekW - sekM);

}

DataGodz& DataGodz::operator ++ ()
{
   //jesli mozna bezpiecznie zwiekszyc sekundy, to robimy to
   if(sekundy+1<60) sekundy++;
   else //gdy sekundy poszly za daleko to zwiekszamy minuty
   {
      if(minuty+1<60)
      {
         sekundy=0;
         minuty++;
      }
      else //gdy minuty poszly za daleko to zwiekszamy godziny
      {
         sekundy=0;
         minuty=0;
         if(godzina+1<24) godzina++;
         else //gdy godziny poszly za daleko zwiekszany jest dzien
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
         }
      }

   }
   return *this;
}

DataGodz& DataGodz::operator -- ()
{
   //jesli mozna bezpiecznie zmniejszyc sekundy, to robimy to
   if(sekundy-1>=0) sekundy--;
   else //gdy sekundy poszly za daleko to zwiekszamy minuty
   {
      if(minuty-1>0)
      {
         sekundy=59;
         minuty--;
      }
      else //gdy minuty poszly za daleko to zmniejszamy godziny
      {
         sekundy=59;
         minuty=59;
         if(godzina-1>=0) godzina++;
         else //gdy godziny poszly za daleko zmniejszany jest dzien
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
                     dzien = dniwmiesiacach[czyprzest][miesiac];
                  }
               else
                  {
                     miesiac--;
                     dzien = dniwmiesiacach[czyprzest][miesiac];
                  }
            }
            else
               dzien--;
         }
      }

   }
   return *this;
}

DataGodz& DataGodz::operator -= (int d)
{
   for(int i=1; i<=d; i++)
      {
         --*this;
      }
   return *this;
}

DataGodz& DataGodz::operator += (int d)
{
   for(int i=1; i<=d; i++)
      {
         ++*this;
      }
   return *this;
}

//__________metody

int DataGodz::ilednioddaty()
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

   iloscPrzest=get_rok()/4 - get_rok()/100 + get_rok()/400;

   return ilosc1 + (rok*365) + iloscPrzest; // *(1) + *(2)
}
