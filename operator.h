#ifndef OPERATOR
#define OPERATOR
#include"token.h"

class Operator:public Token{
public:
    Operator();
    Operator(int SetPrec,char SetType,string SetItem);
};

Operator::Operator():Token(){

}

Operator::Operator(int SetPrec, char SetType, string SetItem):Token(SetPrec,SetType,SetItem){

}

#endif // OPERATOR
