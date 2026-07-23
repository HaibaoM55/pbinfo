#include <iostream>
using namespace std;
int n, m;
int x, y;
int intr[104], extr[104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        extr[x]++;
        intr[y]++;
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(intr[i] > extr[i]){
            nr++;
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= n; i++){
        if(intr[i] > extr[i]){
            cout << i << ' ';
        }
    }
    return 0;
}
