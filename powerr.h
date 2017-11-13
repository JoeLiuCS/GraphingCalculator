#ifndef POWERR
#define POWERR

#include"token.h"

class PowerR :public Token
{
public:
    PowerR();
    PowerR(int SetPrec,char SetType,string SetItem);

};

PowerR::PowerR():Token(){

}

PowerR::PowerR(int SetPrec, char SetType, string SetItem):Token(SetPrec,SetType,SetItem){

}
#endif // POWERR

