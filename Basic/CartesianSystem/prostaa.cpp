#include "prosta.hpp"

using namespace std;

Prosta::Prosta(const Punkt &PktA, const Punkt &PktB)
{
   if(PktA.x==PktB.x && PktA.x==PktB.x)
          throw invalid_argument("Nie mozna utworzyc prostej z tych samych punktow\n");

       this->A = PktB.y - PktA.y;
       this->B = PktA.x - PktB.x;
       this->C = PktB.x*PktA.y - PktA.x*PktB.y;
       //normalizacja();
}
Prosta::Prosta(const Wektor &wek)
{
   if (wek.dx == 0 && wek.dy == 0)
      throw invalid_argument("wspolczynniki A i B nie moga byc jednoczesnie rowne 0!\n");

   this->A = wek.dx;
   this->B = wek.dy;
   this->C = (-1)*A*A - B*B;
   //normalizacja();
}
Prosta::Prosta(double a, double b, double c)
{
   if(a==0 && b==0)
      throw invalid_argument("wspolczynniki A i B nie moga byc jednoczesnie rowne 0!\n");

   this->A = a;
   this->B = b;
   this->C = c;
   //normalizacja();
}
Prosta::Prosta( const Prosta &prosta, const Wektor &wek)
{
   if(prosta.C!=0)
   {
      if(prosta.A!=0 && prosta.B!=0)
      {
         Punkt pA(0, (-1)*prosta.get_C()/prosta.get_B());
         Punkt pB((-1)*prosta.get_C()/prosta.get_A(), 0);
         Punkt pA_2(pA, wek);
         Punkt pB_2(pB, wek);
         Prosta pr(pA_2, pB_2);

         if (pr.A == 0 && pr.B == 0)
            throw invalid_argument("wspolczynniki A i B nie moga byc jednoczesnie rowne 0!\n");

         this->A = pr.get_A();
         this->B = pr.get_B();
         this->C = pr.get_C();
      }
      else if(prosta.get_A()==0 && prosta.get_B()!=0)
      {
         Prosta pr(0, prosta.get_B(), prosta.get_C()-wek.dy);
         this->A = pr.get_A();
         this->B = pr.get_B();
         this->C = pr.get_C();
      }
      else if(prosta.get_A()!=0 && prosta.get_B()==0)
      {
         Prosta pr(prosta.get_A(), 0, prosta.get_C()-wek.dx);
         this->A = pr.get_A();
         this->B = pr.get_B();
         this->C = pr.get_C();
      }
   }
   else
   {
      double y = (-1)*prosta.get_A()/prosta.get_B();
      double x = (-1)*prosta.get_B()*y/prosta.get_A();
      Punkt pA(0,0);
      Punkt pB(x,y);
      Punkt pA_2(pA, wek);
      Punkt pB_2(pB, wek);
      Prosta pr(pA_2,pB_2);
      this->A = pr.get_A();
      this->B = pr.get_B();
      this->C = pr.get_C();
   }
   //normalizacja();
}

bool Prosta::CzyPunktLezy(const Punkt &p)
{
   if(this->A * p.x + this->B * p.y + this->C == 0)
      return true;
   else
   {
      double d = std::abs(this->A*p.x + this->B*p.y + C)/sqrt(pow(this->A,2)+pow(this->A,2));
      cout<<"Punkt nie lezy na prostej. Jego odleglosc od prostej wynosi: "<<d<<endl;
   }
   return false;
}
bool Prosta::czyWektorProstopadly(const Prosta &pr, const Wektor &wek)
{
   return (wek.dx == pr.get_A() && wek.dy == pr.get_B());

}
bool Prosta::czyWektorRownolegly(const Prosta &pr, const Wektor &wek)
{
   if(wek.dy == (-1)*pr.A/pr.get_C() && wek.dx==1)
      return true;
   return false;
}

bool czyProstopadle(const Prosta &pr1, const  Prosta &pr2)
{
   if(pr1.get_A()*pr2.get_A() == (-1)*pr1.get_B()*pr2.get_B())
      return true;
   return false;
}

bool czyRownolegle(const Prosta &pr1, const Prosta &pr2)
{
   if(pr1.get_A()*pr2.get_B() == pr1.get_B()*pr2.get_A())
      return true;
   return false;
}

Punkt punktPrzeciecia(const Prosta &pr1, const Prosta &pr2)
{
   if(czyRownolegle(pr1,pr2))
      throw invalid_argument("Proste sa rownolegle, nie maja punktu przeciecia\n");

   double x = ( ((-1.0)*pr2.get_C()/pr2.get_B()) + (pr1.get_C()/pr1.get_B()) )  /  ( ((-1)*pr1.get_A()/pr1.get_B()) + (pr2.get_A()/pr2.get_B()) ) ;
   double y = ((-1.0)*pr1.get_A()/pr1.get_B()*x ) - (pr1.get_C()/pr1.get_B());

   return Punkt(x,y);

}

void Prosta::normalizacja()
{
   double odleglosc = std::sqrt(this->A*this->A + this->B*this->B);
   this->A /= odleglosc;
   this->B /= odleglosc;
   this->C /= odleglosc;
}

