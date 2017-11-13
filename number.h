#ifndef NUMBER_H
#define NUMBER_H

#include"token.h"

class Number :public Token
{
public:
    Number();
    Number(int SetPrec,char SetType,string SetItem);

};

Number::Number():Token(){

}

Number::Number(int SetPrec, char SetType, string SetItem):Token(SetPrec,SetType,SetItem){

}

#endif // NUMBER_H
