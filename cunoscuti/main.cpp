#include <iostream>
using namespace std;
int n, m;
int x, y;
int vmax = 0;
int f[104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        f[y]++;
        vmax = max(vmax, f[y]);
    }
    for(int i = 1; i <= n; i++){
        if(vmax == f[i]){
            cout << i << ' ';
        }
    }
    return 0;
}
