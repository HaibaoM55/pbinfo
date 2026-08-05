#include <iostream>
using namespace std;
int n;
int main(){
	cin >> n;
    for(int i = 2; i <= n; i += 2){
    	cout << i << ' ';
    }
    cout << '\n';
    for(int i = 3; i <= n; i += 3){
    	cout << i << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0 || i % 3 == 0){
            if(i % 6 == 0){
            	continue;
            }
            cout << i << ' ';
        }
    }
    return 0;
}
