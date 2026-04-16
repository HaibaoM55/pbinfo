#include <iostream>
using namespace std;
#define MOD 998244353
int q;
struct cd{
    int a, b;
}coada[200004];
int st=1,dr=0;
int main(){
    cin >> q;
    for(int i = 1; i <= q; i++){
        int tip;
        cin >> tip;
        if(tip == 1){
            dr++;
            cin >> coada[dr].a >> coada[dr].b;
        }else if(tip == 2){
            st++;
        }else{
            long long x;
            cin >> x;
            for(int j = st; j <= dr; j++){
                x = x*coada[j].a+coada[j].b;
                x = x % MOD;
            }
            cout << x << "\n";
        }
    }
    return 0;
}
