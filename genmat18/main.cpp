#include <iostream>
using namespace std;
#define int long long
int n;
int a[10][10];
signed main(){
    cin >> n;
    int f1 = 1, f2 = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && (j  == 1 || j == 2)){
                a[i][j] = 1;
            }else{
                a[i][j] = f1+f2;
                int aux = f1;
                f1 = f1+f2;
                f2 = aux;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            for(int j = n; j >= 1; j--){
                cout << a[i][j] << ' ';
            }
        }else{
            for(int j = 1; j <= n; j++){
                cout << a[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
