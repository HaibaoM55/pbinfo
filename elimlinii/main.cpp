#include <iostream>
using namespace std;
int n, m, x;
int a[104][104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i][1] = x;
        a[i][0] = 0;
        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                a[i][0] = 1;
                break;
            }
        }
        for(int j = 2; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i][0] == 1){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
