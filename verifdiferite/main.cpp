#include <iostream>
using namespace std;
int n, x;
int f[10004];
int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> x;
        f[x]++;
        if(f[x] == 2){
        	cout << "NU";
            return 0;
        }
    }
    cout << "DA";
    return 0;
}
