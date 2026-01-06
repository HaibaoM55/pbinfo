#include <iostream>
using namespace std;
int n, v[100004];
int vmin[100004], vmax[100004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cin >> v[i];
    }
    int j = 1;
    vmax[1] = v[1];
    for(int i = 2; i <= n; i++){
        vmax[i] = max(vmax[i-1], v[i]);
    }
    vmin[n] = v[n];
    for(int i = n-1; i >= 1; i--){
        vmin[i] = min(vmin[i+1], v[i]);
    }
    int difmax = vmax[1]-vmin[2];
    for(int i = 2; i <= n-1; i++){
    	difmax = max(difmax, vmax[i]-vmin[i+1]);
    }
    cout << difmax;
    return 0;
}
