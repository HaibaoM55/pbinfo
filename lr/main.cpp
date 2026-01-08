#include <iostream>
using namespace std;
int n;
int v[100004], vmax[100004], vmin[100004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vmax[1] = v[1];
    for(int i = 2; i <= n; i++){
        vmax[i] = max(vmax[i-1], v[i]);
    }
    vmin[n] = v[n];
    for(int i = n-1; i >= 1; i--){
        vmin[i] = min(vmin[i+1], v[i]);
    }
    int nr =0;
    for(int i = 2; i < n; i++){
        if(vmax[i-1] <= v[i] && v[i] <= vmin[i+1]){
            nr++;
        }
    }
    cout << nr;
    return 0;
}
