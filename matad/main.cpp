#include <iostream>
using namespace std;
int n;
int a[104][104];
int f[104];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] > 1){
                cout << 0;
                return 0;
            }
        }
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                if(a[i][i]){
                    ok = false;
                }
            }else if(a[i][j] != a[j][i]){
                ok = false;
            }
        }
    }
    cout << ok;
    return 0;
}
