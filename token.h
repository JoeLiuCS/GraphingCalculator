#ifndef TOKEN
#define TOKEN
#include<string>
#include<iostream>
#include <sstream>

using namespace std;
class Token{
public:
    Token();
    Token(int Precedence, char Type,string AddItem);

    int GetPrec();
    char GetType();
    string GetItem();

private:
    int _prec;
    string _Item;
    char _type;

};

Token::Token(){
    _prec = 0;
}

Token::Token(int Precedence, char Type, string AddItem){
    _prec = Precedence;
    _type = Type;
    _Item = AddItem;
}

int Token::GetPrec(){
    return _prec;
}

char Token::GetType(){
    return _type;
}

string Token::GetItem(){
    return _Item;
}

#endif // TOKEN
