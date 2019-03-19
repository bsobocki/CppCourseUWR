#include "prosta.hpp"

using namespace std;

int main()
{
   try
   {
      Punkt a(1.0,3.0);
      Punkt b(2.0,4.0);
      Prosta pr(a,b);
      cout<<pr.get_A()<<"   "<<pr.get_B()<<"   "<<pr.get_C()<<endl;
      Wektor wek(1,3);
      Prosta k(pr, wek);
      cout<<k.get_A()<<"   "<<k.get_B()<<"   "<<k.get_C()<<endl;
      Prosta c(1,2,3);
      Prosta d(2,-1,4);
      czyProstopadle(c,d) ? cout<<"prostopadle"<<endl: cout<<"nie sa prostopadle"<<endl;
      Prosta c1(2,-1,3);
      Prosta d1(3,-1,2);
      czyRownolegle(c1,d1) ? cout<<"rownolegle"<<endl: cout<<"nie sa rownolegle"<<endl;
      cout<<punktPrzeciecia(c1,d1).x<<"   "<<punktPrzeciecia(c1,d1).y<<endl;
      Punkt p(1,5);
      c1.CzyPunktLezy(p) ? cout<<"lezy"<<endl : cout<<"nie lezy"<<endl;
   }
   catch (invalid_argument &ia)
   {
      cout<<ia.what();
   }
   return 0;
}
