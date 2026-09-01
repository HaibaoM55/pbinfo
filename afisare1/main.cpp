#include <iostream>
using namespace std;
int n, z;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    z = n;
    int i;
    for(i = 1; i < z; i++){
    	cout << v[i] << ' ';
        cout << v[z] << ' ';
        z--;
    }
    if(i == z){
    	cout << v[i];
    }
}
