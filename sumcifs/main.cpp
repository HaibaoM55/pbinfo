#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
int n, z=0;
int v[1000004];
void kp(int x){
    int y = x;
    bool f[15] = {false, false, false, false, false,false, false, false, false, false,false};
    int sumcif = 0;
    do{
        f[y%10] = true;
        sumcif += y%10;
        y = y/10;
    }while(y > 0);
    if(sumcif == n){
        z++;
        v[z] = x;
    }
    for(int i = 0; i <= 9 && i <= n-sumcif; i++){
        if(!f[i]){
            kp(x*10+i);
        }
    }
}
signed main(){
    cin >> n;
    kp(0);
    sort(v+1, v+z+1);
    for(int i = 1; i <= z; i++){
        cout << v[i] << '\n';
    }
    return 0;
}
