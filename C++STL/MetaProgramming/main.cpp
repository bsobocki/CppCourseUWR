#include <iostream>
#include <cmath>
template <unsigned int N> struct Lucas1 { enum { val = Lucas1<N-1>::val + Lucas1<N-2>::val }; };
template <> struct Lucas1<0> { enum { val = 2 }; };
template <> struct Lucas1<1> { enum { val = 1 }; };
constexpr int Fib(unsigned int N) { return static_cast<unsigned int>((1/(std::sqrt(5))) * ( std::pow((1+std::sqrt(5))/2,N) - std::pow((1-std::sqrt(5))/2,N) ) ); }
template <unsigned int N> struct Lucas { enum { val = N==0 ? 2 : Fib(N-1) + Fib(N+1)}; };
int main() { std::cout << "Lucas1<15> = " << Lucas1<15>::val << "   Lucas<15> = " << Lucas<15>::val << std::endl; }
