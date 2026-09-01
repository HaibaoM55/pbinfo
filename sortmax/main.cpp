#include <iostream>
#include <algorithm>
using namespace std;
int n,vmax,vmaxi;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
        vmax = max(vmax, v[i]);
        if(v[i] == vmax){
        	vmaxi = i;
        }
    }
    sort(v+1, v+vmaxi+1);
    sort(v+vmaxi+1, v+n+1);
    for(int i = 1; i <= vmaxi; i++){
    	cout << v[i] << ' ';
    }
    for(int i = n; i >= vmaxi+1; i--){
    	cout << v[i] << ' ';
    }
	return 0;
}
