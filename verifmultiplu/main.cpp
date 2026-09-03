#include <iostream>
using namespace std;
int n, k;
int v[1004];
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        if(v[i] % v[n] != 0){
        	cout << "NU";
            return 0;
        }
    }
    cout << "DA";
    return 0;
}
