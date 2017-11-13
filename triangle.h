#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"token.h"

class Triangle: public Token
{
public:
    Triangle();
    Triangle(int SetPrec,char SetType,string SetItem);

};

Triangle::Triangle():Token(){

}

Triangle::Triangle(int SetPrec, char SetType, string SetItem):Token(SetPrec,SetType,SetItem){

}

#endif // TRIANGLE_H
