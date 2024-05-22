/*
[3] A common problem for compilers and text editors is determining whether the
parentheses in a string are balanced and properly nested. For example, the string
((())())() contains properly nested pairs of parentheses, which the strings )()( and
()) do not. Give an algorithm that returns true if a string contains properly nested
and balanced parentheses, and false if otherwise. For full credit, identify the position
of the first offending parenthesis if the string is not properly nested and balanced.
*/

#include <iostream>
#include <stack>

// isValid prototype
bool isValid(std::string);


int main(){
    std::string untested = ")()(";
    
    if (isValid(untested)){
        std::cout << "Valid Parenthesis!" << std::endl;
    }
    else{
        std::cout << "Not Valid Parenthesis!" << std::endl;
    }
}

//isValid implementation
bool isValid(std::string par){
    std::stack<char> Paren;
    int i = 0; 

    for (auto c : par){

        if (c == '('){
            Paren.push('(');
        }

        else{

            if (Paren.empty()){
                std::cout << "Too many closing parenthesis, failed on index " << i << std::endl;
                return false;
            }

            else{
                Paren.pop();
            }
        }
        i++;
    }

    if (!Paren.empty()){
        return false;
    }
    return true;
}