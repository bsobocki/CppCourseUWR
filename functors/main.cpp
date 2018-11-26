//
// Created by Bartosz Sobocki on 2018-10-29.
//

#include "includes.h"

int main() {

    std::srand(time(nullptr));

    /////creating containers/////

    //create descending set with values from [0;100]
    auto cmp = [] (int a, int b) {return a>b;};
    std::set<int>_set;
    for (int i=0; i<50; i++){
        _set.insert(static_cast<int>(rand()%100 + 1));
    }

    //create vector with values from [0;1]
    std::vector<double> _vec;
    for (int i=0; i<50; i++){
        _vec.push_back(static_cast<double>(rand()%100 + 1)/100);
    }

    //create list with strings
    std::list<std::string> _list;
    char a;
    std::string k="";
    for (int i=0; i<50; i++) {
        a = static_cast<char>(i%26 + 97);
        _list.push_back(k + a + a + a);
    }


    /////writing out/////

    std::cout<<std::endl;
    std::cout<<std::endl;

    //writing out _vec
    std::cout<<" writing out _vec "<<std::endl;
    std::vector<double>::iterator it_vec = _vec.begin();
    for(it_vec; it_vec!=_vec.end(); it_vec++){
        std::cout<<*it_vec<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    //writing out _set
    std::cout<<" writing out _set "<<std::endl;
    auto it_set = _set.begin();
    for(it_set; it_set!=_set.end(); it_set++){
        std::cout<<*it_set<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    //writing out _list
    std::cout<<" writing out _list "<<std::endl;
    auto it_list ;
    for(it_list= _list.begin(); it_list!=_list.end(); it_list++){
        std::cout<<*it_list<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;

    /////write from A to B/////

    //write from A to B from _set
    std::cout<<"write from A to B from _set"<<std::endl;
    std::cout<<std::endl;
    isInTheRangeFromAtoB<double> range(20,40);
    for_each(_set.begin(), _set.end(), range);
    std::cout<<std::endl;

    //write from A to B from _vec
    std::cout<<"write from A to B from _vec"<<std::endl;
    range.setA(0.5);
    range.setB(0.7);
    range.say();
    for_each(_vec.begin(), _vec.end(), range);

    std::cout<<std::endl;

    /////writing out every 3rd position started from 2nd/////

    //writing out every 3rd position started from 2nd
    K_Value<std::string> writeK(3,2,[](std::string & v) {std::cout<<v<<std::endl;});
    std::for_each(_list.begin(), _list.end(), writeK);

    std::cout<<std::endl;

    /////sum/////

    //sum of _set
    double s = 0;
    for_each(_set.begin(), _set.end(), [&s](int x) { s+=x;});
    std::cout<<"sum of _set is equal "<<s<<std::endl;

    //sum of _vec
    s = 0;
    for_each(_vec.begin(), _vec.end(), [&s](double x) { s+=x;});
    std::cout<<"sum of _vec is equal "<<s<<std::endl;

    //concatenation of _list
    k = "";
    for_each(_list.begin(), _list.end(), [&k](std::string c) {k += c;});
    std::cout<<"concatenation of _list is equal "<<k<<std::endl;

    std::cout<<std::endl;
    std::cout<<std::endl;

    /////add 5 to every member of container/////

    //add value to every variable from _set, _vec and _list
    //for_each(_set.begin(), _set.end(), [add](int & x) { x+=add;}); //cannot add value to set
    int add = 5;
    for_each(_vec.begin(), _vec.end(), [add](double & x) { x+=add;});
    k = "OOO";
    for_each(_list.begin(), _list.end(), [k](std::string & x) { x+=k;});

    /////writing out _vec + 5 and _list + "OOO"/////

    //writing out _vec
    std::cout<<" writing out _vec + 5 "<<std::endl;
    for(it_vec = _vec.begin(); it_vec!=_vec.end(); it_vec++){
        std::cout<<*it_vec<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    //writing out _list by iterator
    std::cout<<" writing out _list + \"OOO\" "<<std::endl;
    std::list<std::string>::iterator it = _list.begin();
    int i;
    for( it,i=1; it!=_list.end(); it++, i++) {
        std::cout <<i<<"-position = " << *it << std::endl;
    }

    /////arithmetic average/////

    //arithmetic average of _set
    arithAver<int,std::set<int>> arAv;
    std::cout<<std::endl<<"arithmetic average of _set is equal : "<<arAv(_set)<<std::endl;

    /////min and max/////

    //min and max in _vec and _set
    //VECTOR
    minMax<std::vector<double>::iterator, std::vector<double>> mima;
    auto iter = mima(_vec);
    std::cout<<std::endl<<"max from _vec is equal : "<<*iter.itmax<<" and min from _vec is equal : "<<*iter.itmin<<std::endl;
    std::cout<<std::endl;

    /////add to every 2-position object starting from 3-position in _list value equal "KKK"/////
    K_Value<std::string> addKKK(2,3,[](std::string & c){c+="KKK";});
    std::for_each(_list.begin(), _list.end(), addKKK);

    /////writing out _list/////
    std::cout<<std::endl;

    std::cout<<" writing out _list "<<std::endl;
    for(it_list= _list.begin(); it_list!=_list.end(); it_list++){
        std::cout<<*it_list<<std::endl;
    }
}
