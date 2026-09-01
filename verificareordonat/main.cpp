#include <iostream>
using namespace std;
int n;
int v[505];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    v[0] = -2e9;
    for(int i = 1; i <= n; i++){
        if(v[i] < v[i-1]){
        	cout << "NU";
            return 0;
        }
    }
    cout <<"DA";
	return 0;
}
