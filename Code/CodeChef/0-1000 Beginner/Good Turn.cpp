#include <iostream>
using namespace std;
/*
They consider a turn to be good if the sum of the numbers 
on their dice is greater than 6.
Given that in a particular turn Chef and Chefina got X and 
Y on their respective dice, find whether the turn was good.
*/
int main() {
	int iterations;
	cin >> iterations;
	for (int i = 0; i < iterations; i++){
	    int roll1, roll2;
	    cin >> roll1 >> roll2;
	    if (roll1 + roll2 > 6){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}