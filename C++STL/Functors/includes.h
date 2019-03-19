//
// Created by Leszek on 2018-10-29.
//

#ifndef FUNCTORS_INCLUDES_H
#define FUNCTORS_INCLUDES_H

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

template <typename Type>
class isInTheRangeFromAtoB{
public:
    //constructor
    isInTheRangeFromAtoB(Type a, Type b): A(a), B(b) {
        std:: cout<<"From "<<A<<" to "<<B<<std::endl;
    }
    //operator
    void operator() (Type x){
        if ( x>=A && x<=B)
            std::cout<<x<<std::endl;
    }
    void setA(Type x){ A = x;}
    void setB(Type x){ B = x;}
    void say() {std:: cout<<"From "<<A<<" to "<<B<<std::endl;}
private:
    Type A;
    Type B;
};

template <typename K>
class K_Value {
private:
    int k;
    int p;
    int iter;
    void (*fun)(K & val);
public:
    //constructor
    K_Value(const int & kk, const int & pp, void(*f)(K& val)) : p(pp), k(kk), iter(1), fun(f){
        std::cout<<"doing smth on every "<< k << "-positions started from "<<p<<"-postion"<<std::endl;
    }
    //operator
    void operator() (K & val) {
        if ((iter-p)%k == 0 && iter >=p)
            fun(val);
        iter++;
    }
};

template <typename K, typename L>
class arithAver{
private:
    double sum;
    int count;
public:
    //constructor
    arithAver(): sum(0), count(0) {}
    //operator ()
    double operator() (L coll) {
        for_each(coll.begin(), coll.end(), [&](K x) {sum+=x; count++;});
        return sum/count;
    }
};

template <typename K, typename L>
class pair{
public:
    K itmin;
    K itmax;
    L coll;
public:
    pair(K min, K max, L coll){
        //set fields of class
        itmin = coll.begin();
        itmax = coll.begin();
        this->coll = coll;
        //moving iterators to the right places
        while (*itmin!=*min) itmin++;
        while(*itmax!=*max) itmax++;
    }
    pair(pair& a){
        //set fields of class
        coll = a.coll;
        itmin = coll.begin();
        itmax = coll.begin();
        //moving iterators to the right places
        while (*itmin!=*a.min) itmin++;
        while(*itmax!=*a.max) itmax++;
    }
    pair(pair&&)=default;
};

template <typename K, typename L>
class minMax{
public:
    minMax(){}
    pair<K, L> operator()(L &coll){
        //looking for min and max values
        max = *coll.begin();
        min = max;
        for_each(coll.begin(), coll.end(), [&](double x) {
            if(x>max) max = x;
            if(x<min) min = x;
        });

        //returning pair of iterators
        auto itmax = coll.begin();
        //looking for iterator of max value
        for(itmax; itmax!=coll.end(); itmax++){
            if(*itmax==max){
                //looking for iterator of min value
                for(auto itmin=coll.begin(); itmin!=coll.end(); itmin++){
                    if(*itmin==min)
                        return pair<K, L>(itmin,itmax,coll);
                }
            }
        }
    }
private :
    double max;
    double min;
};

#endif //FUNCTORS_INCLUDES_H
