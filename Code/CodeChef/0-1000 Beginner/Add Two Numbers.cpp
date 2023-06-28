#include <iostream>
using namespace std;
/*
The task is very simple: given two integers A and B, 
write a program to add these two numbers and output it.
*/
int main() 
{
   int itr;
   cin >> itr; // Number of iterations
   for (int i = 0; i < itr; i++){
       int a, b;
       cin >> a >> b;
       cout << a + b << endl;
   }
   
   return 0;
}