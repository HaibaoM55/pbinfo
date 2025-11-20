#include <iostream>
using namespace std;
int t, m;
long long n;
int x;
bool f[67];
int fv[67];
int log2nr(int x){
    return 32 - __builtin_clzl(x) - 1;
}
int main(){
    cin >> t;
    while(t > 0){
        cin >> n >> m;
        while(n){
            fv[z]
            n = n/2;
        }
        for(int i = 1; i <= m; i++){
            cin >> x;
            fv[log2nr(x)]++;
        }
        t--;
    }
    return 0;
}
