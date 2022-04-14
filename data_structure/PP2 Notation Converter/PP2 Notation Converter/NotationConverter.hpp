#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H
#include "NotationConverterInterface.hpp"
#include "Deque.hpp"
#include<iostream>

using namespace std;

//Class for the notation converter
//It is a friend of the Deque class
class NotationConverter:public NotationConverterInterface{
public:
    string postfixToInfix(string inStr);
    string postfixToPrefix(string inStr);

    string infixToPostfix(string inStr);
    string infixToPrefix(string inStr);

    string prefixToInfix(string inStr);
    string prefixToPostfix(string inStr);

    string toString();  //Converts the deque into a string

private:
    Deque N;    //The main deque
    Deque temp; //A temp deque used in various functions
    Deque temp2;//Another temp deque only used in the postfixToInfix function
};

#endif
