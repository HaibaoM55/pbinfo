#include <iostream>
using namespace std;
int n, nr;
int a[104][104];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 0){
                a[i][j] = a[i-1][j];
            }else{
                a[i][j] = 1+max(a[i-1][j-1], a[i-1][j+1]);
            }
        }
    }
    for(int j = 1; j <= n; j++){
        nr = max(nr, a[n][j]);
    }
    cout << nr;
    return 0;
}
