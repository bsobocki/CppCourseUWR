#include <iostream>
#include <stack>
#include <queue>
#include <sstream>

//niektore funkcje (moga zostac uzupelniane na bierzaco)
bool is_func(std::string x){
    return x == "f" ||
            x== "g" ||
            x == "sin" ||
            x == "cos" ||
            x == "arcsin" ||
            x == "atan" ||
            x == "arccos" ||
            x == "sign" ||
            x == "log";
}

//sprawdzamy czy dany znak jest operatorem
bool is_oper(char x){
    return x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='%';
}

//zwraca nam priorytet obliczania danego operatora
int priority(char op){
    switch(op){
        case '(':
            return 0;
        case '+':
        case '-':
        case ')':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
}

//sprawdza, czy dany operator jest prawostronnie laczny z drugim operatorem
bool right_sided(char op1, char op2){
    switch(op1){
        case '+':
            return priority(op2) >= priority('+');
        case '-':
            return priority(op2) > priority('+');
        case '*':
            return priority(op2) >= priority('+');
        case '/':
            return priority(op2) > priority('+');
        case '%':
            return priority(op2) > priority('+');
        case '^':
            return priority(op2) > priority('+');
    }
}

//zamienia char na string
std::string toStr(char a) {
    std::stringstream ss;
    ss<<a; return
    ss.str();
}

//zamienia wyrazenie w postaci infixowej na rownowazne wyrazenie w ONP
std::string toONP(std::string infix) {
    std::stack<std::string> stos;
    std::queue<std::string> wyjscie;

    for(int i=0; i<infix.size() ; i++){
        //jesli symbol jest liczba
        if(infix[i]>=48 && infix[i]<=57) {
            //liczba zostanie zbudowana za pomoca stringstream
            std::stringstream ss;
            //dopoki kolejne znaki to dalszy ciag liczby dodane zostaja do stringstream i zwiekszany jest iterator
            while(infix[i+1]>=48 && infix[i+1]<=57){
                ss<<infix[i];
                i++;
            }
            //dodana zostaje ostatnia cyfra
            ss<<infix[i];
            //wrzucamy do wyjscia
            wyjscie.push(ss.str());
        }
        //jesli symbole sa nazwa funkcji
        else if(infix[i]>=97 && infix[i]<=122){
            //nazwa zostanie zbudowana za pomoca stringstream
            std::stringstream ss;
            //dopoki kolejne znaki to dalszy ciag nazwy dodane zostaja do stringstream i zwiekszany jest iterator
            while(infix[i+1]>=97 && infix[i+1]<=122){
                ss<<infix[i];
                i++;
            }
            //dodana zostaje ostatni znak
            ss<<infix[i];
            stos.push(ss.str());
        }
        //jesli symbol jest przecinkiem odddzielajacym
        else if(infix[i]==',') {
            //dopoki nie napotkamy nawiasu wrzucamy do wyjscia operatory
            while (stos.top()[0]!='('){
                wyjscie.push(stos.top());
                stos.pop();
            }
        }
        //jesli natkniemy sie na operator
        else if(is_oper(infix[i])){
            //dopoki na stosie sa operatory:
            while( !stos.empty() &&  is_oper(stos.top()[0]) &&
                    /*infix[i] jest lewostronnie lacznym operatorem (jest, o ile ma mnijszy lub rowny priorytet)
                     o mniejszym lub rownym priorytecie */
                    (priority(stos.top()[0])>=priority(infix[i]) ||
                    //infix[i] jest prawostronnie lacznym operatorem o mniejszym priorytecie
                    (right_sided(infix[i],stos.top()[0]) && priority(stos.top()[0])>priority(infix[i]))))
            {
                wyjscie.push(stos.top());
                stos.pop();
            }
            stos.push(toStr(infix[i]));
        }
        //gdy natkniemy sie na nawias otwierajacy to wrzucamy go na stos
        else if(infix[i]=='(')
            stos.push(toStr(infix[i]));
        //gdy napotkamy nawias zamykajacy
        else if(infix[i]==')'){
            //dopoki nie natkniemy sie na nawias otwierajacy to wyrzucamy ze stosu do wyjscia operatory
            while(!stos.empty() && stos.top()[0]!='(' ){
                wyjscie.push(stos.top());
                stos.pop();
            }
            //gdy kolejny symbol na stosie to nawias
            if(stos.top()[0]=='(')
                stos.pop(); //zdejmujemy lewy nawias nie wpisujac go do wyjscia
            else
                std::cerr<<"zle postawione nawiasy!"<<std::endl;

            //gdy symbol po nawiasach to
            if(is_func(stos.top())) {
                wyjscie.push(stos.top());
                stos.pop();
            }
        }
    }

    //gdy nie ma juz nic do przeczytania wyrzucamy ze stosu wszystko na wyjscie
    while(!stos.empty()){
        wyjscie.push(stos.top());
        stos.pop();
    }

    //tworzone zostanie wyjscie
    std::stringstream to_return;

    while(!wyjscie.empty()){
        to_return << wyjscie.front() << " ";
        wyjscie.pop();
    }

    return to_return.str();
}

int main() {
    //przyklady infik => ONP
    std::cout << toONP("332+4*2/(1-5)^7") << std::endl;
    std::cout << toONP("332-42-5*5") << std::endl;
    std::cout << toONP("sin(3)+4*2*(1 - cos(4 + 3))/(1-5)^7") << std::endl;
    std::cout << toONP("cos(7) + log(2,3)") << std::endl;
    std::cout << toONP("422-4*2^(1-5)^7") << std::endl;
    return 0;
}