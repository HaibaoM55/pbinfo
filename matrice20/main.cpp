#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[67][69];
int v[67][69];
int vmax[9];
void fill(int i, int j, int x){
    if(1 <= i && i <= n){
        if(1 <= j && j <= n){
            if(v[i][j] == 0){
                v[i][j] = x;
                fill(i+1, j, x);
                fill(i-1, j, x);
                fill(i, j+1, x);
                fill(i, j-1, x);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int sz;
    for(int i = 1; i <= n; i++){
        v[i][i] = 5;
    }
    int j1 = 1;
    for(int i = n; i >= 1; i--){
        v[i][j1] = 5;
        j1++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[i][j] == 0){
                nr++;
                fill(i, j, nr);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            vmax[v[i][j]] = max(vmax[v[i][j]], a[i][j]);
        }
    }
    int g = __gcd(vmax[1], vmax[2]);
    g = __gcd(g, vmax[3]);
    g = __gcd(g, vmax[4]);
    cout << g;
    return 0;
}
