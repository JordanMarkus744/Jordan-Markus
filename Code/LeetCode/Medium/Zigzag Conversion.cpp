#include <string>

using namespace std;


/*
[0]   [4]   [8]    [12] going up by 4
[1][3][5][7][9][11][13] going up by 2
[2]   [6]   [10]        going up by 4

length of string divided by numRows stored in an int gets how many letters go on top row

class Solution { 
public:
    string convert(string s, int numRows) {
        bool stringComplete = false;
        bool goingUp = false;
        int j = 0;
        int k = 0;
        string result = "";
        if (s.length() == 1){
            string result = "";
            result += s[0];
            return result;
        }
        if (s.length() == 2){
            return s;
        }
        if (numRows == 1){
            return s;
        }
        if (numRows == 2){
            for (int i = 0; i < s.length(); i+=2){
                result += s[i];
            }
            for (int i = 1; i < s.length(); i+=2){
                result += s[i];
            }
            return result;
        }
        
        char MyArray[numRows][s.length()];
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < s.length(); j++){
                MyArray[i][j] = '8';
            }
        }

            for (int i = 0; i < s.length(); i++){
                MyArray[j][k] = s[i];
                if (j == 0){
                    goingUp = false;
                }
                if (goingUp == true){
                    k++;
                    j--;
                }
                if (j == numRows-1){
                    goingUp = true;
                    k++;
                    j--;
                }
                if (goingUp == false){
                    j++;
                }

                if (i == s.length()-1){
                    stringComplete = true;
                }
                
            }
        
        int length = s.length();
        for (int i = 0; i < numRows; i++){
            for (int j = 0; j < length; j++){
                if (MyArray[i][j] != '8'){
                    result += MyArray[i][j];
                }
            }
        }
        return result;
    }
};
*/