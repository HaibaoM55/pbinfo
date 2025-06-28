#include <iostream>
using namespace std;
int n, x;
int vmax = 0,vmaxi,vmaxj;
int f[1000004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(f[x] == 0){
            f[x] = i;
        }
        if(f[x] != 0){
            if(i-f[x]+1 > vmax){
                vmax = i-f[x]+1;
                vmaxi = f[x];
                vmaxj = i;
            }
        }
    }
    cout << vmaxi << ' ' << vmaxj;
    return 0;
}
