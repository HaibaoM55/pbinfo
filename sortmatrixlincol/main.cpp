#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[104][104];
int b[104];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
        sort(a[i]+1, a[i]+n+1);
    }
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            b[i] = a[i][j];
        }
        sort(b+1, b+n+1);
        for(int i = 1; i <= n; i++){
            a[i][j] = b[i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
