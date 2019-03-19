#include "data.hpp"

using namespace std;

int main()
{// dzisiaj - 15.10.1582
    Data k(31,3,1);
    Data r(2,3,1);
    Data c;
    cout<<"C:\n"<<c.get_dzien()<<"-"<<c.get_miesiac()<<"-"<<c.get_rok()<<endl;
    cout<<"K:\n"<<k.get_dzien()<<"-"<<k.get_miesiac()<<"-"<<k.get_rok()<<endl<<endl;

    cout<<"k+=4"<<endl;
    k+=4;
    cout<<k.get_dzien()<<"-"<<k.get_miesiac()<<"-"<<k.get_rok()<<endl<<endl;

    cout<<"k=c"<<endl;
    k=c;
    cout<<"po przepisaniu z c : "<<k.get_dzien()<<"-"<<k.get_miesiac()<<"-"<<k.get_rok()<<endl<<endl;
    cout<<endl;

    Data nowa1(1,1,11);
    Data nowa2(31,12,10);
    DataGodz dg2(nowa1,00,01,00);
    DataGodz dg(nowa2,23,59,00);

    cout<<"dwie daty: "<<endl<<endl;
    cout<<dg.get_dzien()<<"-"<<dg.get_miesiac()<<"-"<<dg.get_rok()<<" | "<<dg.get_godzina()<<" : "<<dg.get_minuty()<<" : "<<dg.get_sekundy()<<endl;
    cout<<dg2.get_dzien()<<"-"<<dg2.get_miesiac()<<"-"<<dg2.get_rok()<<" | "<<dg2.get_godzina()<<" : "<<dg2.get_minuty()<<" : "<<dg2.get_sekundy()<<endl<<endl;

    cout<<"roznica tych dwoch dat (sekundy): \n";
    cout<<dg2-dg<<endl<<endl<<endl;


    //TEST
    //dzisiaj - 15.10.1582

    Data dzisiaj;
    Data test(15,10,1582);
    cout<<"Test dzisiaj-15.10.1582:"<<endl;
    cout<<dzisiaj-test<<endl;

/* //DODAWANIE WYDARZEN I WYPISANIE ICH
    vector<Wydarzenie> eventy;
    int n;
    string title;
    short aa,bb,cc,x,y,z;

    cout<<"podaj liczbe wydarzen: \n";
     cin>>n;

    for(int i=0; i<n; i++)
    {
       cout<<"podaj date (dd mm rrrr): \n";
       cin>>x>>y>>z;
       cout<<"podaj godzine (gg mm ss): \n";
       cin>>aa>>bb>>cc;
       cout<<"podaj tytul: \n";
       cin>>title;
       Data data(x,y,z);
       DataGodz datagodz(data,aa,bb,cc);
       Wydarzenie tmp(datagodz,title);
       eventy.push_back(tmp);
       cout<<endl;
    }

    for(int i=0; i<n; i++)
    cout<<"Data : \n"<<eventy[i].punktCzasowy.get_rok()<<"-"<<eventy[i].punktCzasowy.get_miesiac()<<"-"<<eventy[i].punktCzasowy.get_dzien()<<"  |  "<<eventy[i].punktCzasowy.get_godzina()<<":"<<eventy[i].punktCzasowy.get_minuty()<<":"<<eventy[i].punktCzasowy.get_sekundy()<<":"<<" tytul: "<<eventy[i].tytul<<endl;
*/
}

