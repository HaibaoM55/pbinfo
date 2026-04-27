#include <iostream>
using namespace std;
int n;
char x;
int a[504];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = x-'0';
    }
    cout << a[1];
    for(int i = 2; i <= n; i++){
        cout << (a[i]+a[i-1])%2;
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = x-'0';
    }
    cout << a[1];
    int prev = a[1];
    for(int i = 2; i <= n; i++){
        prev = (prev+a[i])%2;
        cout << prev;
    }
    return 0;
}
