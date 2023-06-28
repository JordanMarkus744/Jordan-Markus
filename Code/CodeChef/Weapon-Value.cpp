#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >>t;
	
	for (int i = 0; i < t; i++){
	    int WeaponNotDestroyed[10] = {0};
	    string s;
	    int count = 0;
	    cin >> n;
	    for (int j = 0; j < n; j++){
	        cin >> s;
	        int arr[10] = {0};
	        for (int k = 0; k < s.length(); k++){
	            arr[k] = s[k] - '0';
	        }
	        for (int k = 0; k < 10; k++){
	            WeaponNotDestroyed[k] = WeaponNotDestroyed[k] ^ arr[k];
	        }
	        
	    }
	    for (int k = 0; k < 10; k++){
	        if (WeaponNotDestroyed[k] > 0){
	            count++;
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}