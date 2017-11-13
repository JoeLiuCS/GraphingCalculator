#ifndef BRACKET
#define BRACKET
#include"token.h"

class Bracket:public Token{
public:
    Bracket();
    Bracket(int SetPrec,char SetType,string SetItem);
};

Bracket::Bracket():Token(){

}

Bracket::Bracket(int SetPrec, char SetType, string SetItem):Token(SetPrec,SetType,SetItem){

}

#endif // BRACKET

