#include <iostream>
using namespace std;
int n, x;
int e2, e5;
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        while(x % 2 == 0){
        	e2++;
            x = x/2;
        }
        while(x % 5 == 0){
        	e5++;
            x = x/5;
        }
    }
    cout << min(e2, e5);
}
