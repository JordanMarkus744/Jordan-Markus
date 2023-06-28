#include <iostream>
using namespace std;
/*
Chef wants to appear in a competitive exam. To take the exam, there 
are following requirements: Minimum age limit is x(i.e. Age should be
greater than or equal to x). Age should be strictly less than y.
Chef's current age is A. Find whether he is currently eligible to take the 
exam or not.
*/
int main() {
	int itr;
	cin >> itr;
	for (int i = 0; i < itr; i++){
	    int x, y, age; // age should be greater than or equal to x and less than y
	    cin >> x >> y >> age;
	    if (age >= x && age < y){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
