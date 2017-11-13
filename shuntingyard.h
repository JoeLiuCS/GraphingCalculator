#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include<queue>
#include<stack>
#include"token.h"
#include"number.h"
#include"operator.h"
#include"powerr.h"
#include"triangle.h"
#include"bracket.h"
#include<math.h>
#include<sstream>
#include"allconstants.h"


class ShuntingYard
{
public:
    ShuntingYard();
    ShuntingYard(string s,int x);
    void postFix();
    void printResult();
    double calculateIt();

private:
    bool CheckIsNum(string n);
    bool CheckIsBracket(string n);
    bool CheckIsTriangle(string n);
    queue<Token*> _result;
};

ShuntingYard::ShuntingYard(){

}

ShuntingYard::ShuntingYard(string s, int x){
    stringstream function(s);
    string temp;
    while(temp != "~"){
        function >> temp;
        //set precedence
        //number > Trimetirc > bracket > power > D&M > P&Mu
        if(temp == "x" || temp == "X"){
            _result.push(new Number(6,'N',to_string(x)));
        }
        else if(CheckIsNum(temp)){
            _result.push(new Number(6,'N',temp));
        }
        else if(CheckIsBracket(temp)){
            _result.push(new Bracket(5,'B',temp));
        }
        else if(CheckIsTriangle(temp)){
            _result.push(new Triangle(4,'T',temp));
        }
        else if (temp == "^"){
            _result.push(new PowerR(3,'R',temp));
        }
        else{
            if(temp=="*" || temp=="/"){
               _result.push(new Operator(2,'O',temp));
            }
            if(temp == "-" || temp =="+"){
               _result.push(new Operator(1,'O',temp));
            }
        }
    }
}

void ShuntingYard::postFix(){

    queue<Token*> tempFinal;
    stack<Token*> tempOperators;
    while(!_result.empty()){
        Token *tokenTemp = _result.front();

        //If find number push in
        if(tokenTemp->GetType() == 'N'){
            tempFinal.push(tokenTemp);
        }
        //if it is operator and left bracket
        else if(tokenTemp->GetPrec() <= 4 || tokenTemp->GetItem() == "("){

            if(tempOperators.empty()){
                tempOperators.push(tokenTemp);
            }
            else{
                Token *checkTop = tempOperators.top();
                //Staff == top
                if(checkTop->GetPrec() == tokenTemp->GetPrec()){
                    if(tokenTemp->GetItem() !="("){
                        tempFinal.push(checkTop);
                        tempOperators.pop();
                    }
                    tempOperators.push(tokenTemp);
                }
                //Staff > top
                else if (checkTop->GetPrec() < tokenTemp->GetPrec()){
                    tempOperators.push(tokenTemp);
                }
                //Staff < top
                else{
                    //find left bracket just push in
                    if(checkTop->GetItem() == "("){
                        tempOperators.push(tokenTemp);
                    }
                    //if not , push all operators until find the left bracket
                    else{
                        while(!tempOperators.empty()){
                            Token* TemHere = tempOperators.top();
                            tempFinal.push(TemHere);
                            tempOperators.pop();
                            if(!tempOperators.empty()){
                                Token* check = tempOperators.top();
                                if(check->GetItem() == "(" || tempOperators.empty()){
                                    break;
                                }
                            }
                        }
                        tempOperators.push(tokenTemp);
                    }
                }
            }
        }
        //if it is right bracket
        //push all operators inside bracket
        else{
            Token* tempOpe = tempOperators.top();
            while(tempOpe->GetItem() != "("){
                tempFinal.push(tempOpe);
                tempOperators.pop();
                tempOpe = tempOperators.top();
            }
            tempOperators.pop();
        }
        _result.pop();
    }
    //push all remainning operators to the queue
    if(!tempOperators.empty()){
        while(!tempOperators.empty()){
            Token *temp = tempOperators.top();
            tempFinal.push(temp);
            tempOperators.pop();
        }
    }
    _result = tempFinal;
}

double ShuntingYard::calculateIt(){
    stack<Token*> temp_Out;
    while(!_result.empty()){
        Token* tempTop = _result.front();

        if(tempTop->GetType() == 'N'){
            temp_Out.push(tempTop);
        }
        else if (tempTop->GetType() == 'T'){
            Token * tempO = temp_Out.top();
            temp_Out.pop();
            double num = stod(tempO->GetItem());
            string ans;
            if(tempTop->GetItem() == "sin"){
                ans = to_string(sin(num*angle));
            }
            if(tempTop->GetItem() == "cos"){
                ans = to_string(cos(num*angle));
            }
            if(tempTop->GetItem() == "tan"){
                ans = to_string(tan(num*angle));
            }
            temp_Out.push(new Number(6,'N',ans));
        }
        else{
            Token* temp2 = temp_Out.top();
            temp_Out.pop();
            double num2 = stod(temp2->GetItem());
            Token* temp1 = temp_Out.top();
            temp_Out.pop();
            double num1 = stod(temp1->GetItem());

            string ope = tempTop->GetItem();
            string ans;
            if(ope == "*"){
                ans = to_string(num1*num2);
            }
            if(ope == "/"){
                ans = to_string(num1/num2);
            }
            if(ope == "+"){
                ans = to_string(num1+num2);
            }
            if(ope == "-"){
                ans = to_string(num1-num2);
            }
            if(ope == "^"){
                ans = to_string(pow(num1,num2));
            }
            temp_Out.push(new Number(6,'N',ans));
        }
        _result.pop();
    }
    Token* top = temp_Out.top();
    return stod(top->GetItem());
}


void ShuntingYard::printResult(){
    while(!_result.empty()){
        Token* temp = _result.front();
        cout<<temp->GetItem()<<endl;
        _result.pop();
    }
}

bool ShuntingYard::CheckIsNum(string n){
    return n.at(0) > 47 && n.at(0) <57 ;
}
bool ShuntingYard::CheckIsBracket(string n){
    return n == "(" || n == ")";
}
bool ShuntingYard::CheckIsTriangle(string n){
    return n == "sin" || n == "cos" || n == "tan";
}

#endif // SHUNTINGYARD_H
