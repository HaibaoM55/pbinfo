#include <iostream>
using namespace std;
int n, vmax = 0, vmaxi=0;
int v[1004];
int f[1000004];
bool esteprim(int k){
    if(k < 2) return false;
    for(int i = 2; i*i <= k; i++){
    	if(k % i == 0) return false;
    }
    return true;
}
int main(){
    cin >> n;
    int vmax = 0, vmin=2e9;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
        f[v[i]]++;
        vmax = max(vmax, v[i]);
        vmin = min(vmin, v[i]);
    }
    cout << f[vmax-vmin];
    return 0;
}
