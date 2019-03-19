#include "wymierne.hpp"

using namespace std;
using namespace obliczenia;

int main()
{
   Wymierne wym(5,-10);
   cout<<"-5/10 = "<<wym<<endl;

   wym = Wymierne(6,10);
   cout <<"6/10 = "<< wym << endl;

   double t = wym;
   cout <<"(double) 6/10 = "<< t << endl;

   cout <<"(int) 5/10 = "<< static_cast<int>(wym) << endl;

   wym = Wymierne(15,10);
   cout <<"- 15/10 = "<< -wym << endl;
   cout <<"! 15/10 = "<< !wym << endl;

   cout<<"1/3 = "<<Wymierne(1,3)<<endl;

   try{cout<<Wymierne(10,0)<<endl;} catch (wyjatek_wymierny& a) {cout<<a.what()<<endl;}
   try{cout<<Wymierne(INT_MAX,3)*Wymierne(7,4)<<endl;}catch(wyjatek_wymierny& a) {cout<<a.what()<<endl;}
   try{cout<<Wymierne(3,INT_MIN)<<endl;}catch(wyjatek_wymierny& a) {cout<<a.what()<<endl;}
   try{cout<<!Wymierne(1,111)<<endl;}catch(wyjatek_wymierny& a) {cout<<a.what()<<endl;}

   cout<<Wymierne(1,111)<<endl;

   wym = Wymierne(0,1);

   Wymierne wym2(2,4);
   cout<<wym2<<endl;

   try {cout<<wym2/wym<<endl;} catch (wyjatek_wymierny& e) {cout<<e.what()<<endl;}

   cout<<(int)(Wymierne(3,4)/Wymierne(3,4))<<endl;

   return 0;
}
