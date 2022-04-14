#include "NotationConverter.hpp"
using namespace std;

//postfixToInfix takes in a postfix string and converts it to infix
string NotationConverter::postfixToInfix(string inStr){
    if(!isalpha(inStr[0]))
        throw inStr;

    for(unsigned int i = 0; i < inStr.size(); i++){
        //This if statement removes whitespace from the string
        if(inStr[i] != ' '){
            //This if statement inserts the operator into a temporary deque
            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/')
                temp2.insertBack(inStr[i]);
            //This else statement inserts the operand into another temporary deque
            else
                temp.insertBack(inStr[i]);
        }
    }

    //Checks if postfix is correct
    if(temp2.size() != temp.size()-1){
        throw inStr;
    }
    
    N.insertBack('(');

    //The variable num is used since the size of temp2 will be changing
    int num = temp2.size();
    //The amount of parentheses being inserted depend on the amount of operators
    for(int i = 1; i < num-1; i++)
            N.insertBack('(');

    //This loop inserts the operand and operators from their temporary deques
    while(temp.empty() == false){
        N.insertBack(temp.front());
        temp.removeFront();

        //If there are still operators in the temp deque, then insert them into the main deque
        if(temp2.empty() == false){
            //If there are 2 operators left, then this removes the one from the back instead of the front
            //This is to maintain proper infix order
            if(temp2.size() == 2){
                N.insertBack(')');
                N.insertBack(temp2.back());
                temp2.removeBack();
                N.insertBack('(');
            }
            else{
                N.insertBack(temp2.front());
                temp2.removeFront();
            }
        }
    }

    N.insertBack(')');

    //Inserts any remaining parentheses needed
    for(int i = 1; i < num-1; i++)
            N.insertBack(')');

    return toString();
}

//postfixToPrefix takes an postfix string and converts it to a prefix string
//It uses other functions to convert to infix first and then finally to prefix
string NotationConverter::postfixToPrefix(string inStr){
    return infixToPrefix(postfixToInfix(inStr));
}

//infixToPostfix takes an infix string and converts it to postfix
string NotationConverter::infixToPostfix(string inStr){
    if(inStr[0] != '('){
        throw inStr;
    }
    
    for(unsigned int i = 0; i < inStr.size(); i++){
        //The while loop removes any left parentheses
        //One of the test cases had a space after the end parenthesis that caused problems
        //So I had to make sure that it does not iterate past the end of the string
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){
                //Inserts operators into a temporary deque
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                        temp.insertBack(inStr[i]);
                }
                //Inserts the operands into the main deque
                else if(inStr[i] != '('){
                    N.insertBack(inStr[i]);
                }
            }
            i++;
        }

        int num = temp.size();
        for(int i = 0; i < num; i++){
            //If there are 2 operators in the temp deque, then it removes the back to maintain postfix order
            if(temp.size() == 2){
                N.insertBack(temp.back());
                temp.removeBack();
            }
            else{
                N.insertBack(temp.front());
                temp.removeFront();
            }
        }
    }
    return toString();
}

//infixToPrefix takes an infix string and converts it to prefix
string NotationConverter::infixToPrefix(string inStr){
    if(inStr[0] != '('){
        throw inStr;
    }
    for(unsigned int i = 0; i < inStr.size(); i++){
        //The while loop removes any left parentheses
        //One of the test cases had a space after the end parenthesis that caused problems
        //So I had to make sure that it does not iterate past the end of the string
        while(inStr[i] != ')' && inStr[i] != *inStr.end()){
            if(inStr[i] != ' '){
                if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                    //If the operator was next to a left parenthesis, then insert it to the front
                    //This is for prefix ordering
                    if(inStr[i-2] == ')'){
                        N.insertFront(inStr[i]);
                    }
                    //Else insert it to the back like normal
                    else{
                        N.insertBack(inStr[i]);
                    }
                }
                //Inserts the operands into the temporary deque
                else if(inStr[i] != '('){
                    temp.insertBack(inStr[i]);
                }
            }
            i++;
        }

        //This section inserts the operands from the temp deque into the main one
        int num = temp.size();
        for(int i = 0; i < num; i++){
            N.insertBack(temp.front());
            temp.removeFront();
        }
    }
    return toString();
}

//prefixToInfix converts a prefix string to infix
string NotationConverter::prefixToInfix(string inStr){
    if(inStr[0] != '+' && inStr[0] != '-' && inStr[0] != '*' && inStr[0] != '/')
        throw inStr;

    bool needP = false; //variable to determine if a left parenthesis is needed
    int par = 0;        //variable to make sure that there are an even amount of parentheses

    for(unsigned int i = 0; i < inStr.size(); i++){
        if(inStr[i] != ' '){
            //Inserts operators into temp deque
            if(inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/'){
                temp.insertBack(inStr[i]);
                N.insertBack('(');
                par++;
                needP = false;  //Left parenthesis is not needed until an operand is found
            }
            else{
                //Inserts operand into main deque
                N.insertBack(inStr[i]);

                //Inserts a left parenthesis after an operand, operator, and then operand are inserted
                if(needP == true){
                    N.insertBack(')');
                    par--;
                }

                //Inserts the operator from the temp deque into the main deque
                if(temp.empty() == false){
                    N.insertBack(temp.back());
                    temp.removeBack();
                    needP = true;   //Left parenthesis is needed in the next loop
                }
            }
        }
    }

    //If par is 0, then there are an even number of parentheses
    //If not, then just one more left parenthesis is needed
    if(par != 0){
        while(par != 0){
            N.insertBack(')');
            par--;
        }
    }

    return toString();
}

//prefixToPostfix converts a prefix string to postfix
//It uses other functions to first convert to infix and then postfix
string NotationConverter::prefixToPostfix(string inStr){
    return infixToPostfix(prefixToInfix(inStr));
}

//toString removes elements from the deque and converts them into a single string
//It is used by all the other functions
//It does not take any arguments since the deque is part of the class
string NotationConverter::toString(){
    string newstr;

    //Checks if the deque is empty
    if(N.empty() == true)
        return newstr;

    int size = N.size();    //Needed since N will be changing sizes

    for(int i = 0; i < size; i++)
    {
        //If the character being inserted is a left parenthesis,
        //then this removes whitespace from the end of the string to make sure
        //that there is not space between the operand and the parenthesis
        if(N.front() == ')'){
            newstr.pop_back();
        }

        newstr += N.front();

        //Makes sure to not put space in front of the right parenthesis
        if(N.front() != '(')
            newstr += ' ';

        N.removeFront();
    }

    //An extra space is always added at the end of the loop, so this removes it
    newstr.pop_back();

    return newstr;
}
