#include <iostream>
using namespace std;
/*
Most programmers will tell you that one of the ways to improve your performance in competitive programming is to practice a lot of problems.

Our Chef took the above advice very seriously and decided to set a target for himself.
Chef decides to solve at least 10 problems every week for 4 weeks.
Given the number of problems he actually solved in each week over 4 weeks as P1, P2, P3, and P4, output the number of weeks in which chef met his target
*/
int main() {
	int a;
	int count = 0;
	while (cin >> a){
	    if (a >= 10){
	        count++;
	    }
	}
	cout << count << endl;
	return 0;
}
