#include <iostream>
using namespace std;
int n, m;
int a[104][104];
int vmax = 0, vmin = 1000004;
int vmaxi, vmaxj;
int vmini, vminj;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(a[i][j] > vmax){
                vmax = a[i][j];
                vmaxi = i;
                vmaxj = j;
            }
            if(a[i][j] < vmin){
                vmin = a[i][j];
                vmini = i;
                vminj = j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == vmini || i == vmaxi){
            continue;
        }
        for(int j = 1; j <= m; j++){
            if(j == vminj || j == vmaxj){
                continue;
            }
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
