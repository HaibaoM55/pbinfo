#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
int v[1004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int y = x;
        int rx = 0;
        do{
            rx = rx*10+y%10;
            y = y/10;
        }while(y);
        v[n-i+1] = __gcd(x, rx);
    }
    for(int i = 1; i <= n; i++){
        cout << v[i] << ' ';
    }
    return 0;
}
