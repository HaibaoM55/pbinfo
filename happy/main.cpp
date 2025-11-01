#include <iostream>
#include <algorithm>
using namespace std;
int n;
int nrdiv(int x){
    if(x == 1){
        return 1;
    }
    int nr = 0;
    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            nr++;
            if(i*i < x){
                nr++;
            }
        }
    }
    return nr;
}
int a, b;
int vmax = 0, vmin= 2e9;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        int rez = __gcd(a, b);
        if(nrdiv(rez) % 2 == 0){
            vmin = min(rez, vmin);
        }else{
            vmax = max(rez, vmax);
        }
    }
    if(vmax == 0 || vmin == 2e9){
        cout << "NU EXISTA";
        return 0;
    }
    cout << vmin << ' ' << vmax;
    return 0;
}
