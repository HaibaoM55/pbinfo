#include <iostream>
using namespace std;
int n, a[51][51];
int main(){
    cin >> n;
    int p = 0;
    while(p < n/2){
        for(int i = 1+p; i <= n-p-1; i++){
            a[1+p][i] = p+1;
        }
        for(int i = 1+p; i <= n-p-1; i++){
            a[i][n-p] = p+1;
        }
        for(int i = n-p; i >= 2+p; i--){
            a[n-p][i] = p+1;
        }
        for(int i = n-p; i >= 2+p; i--){
            a[i][1+p] = p+1;
        }
        p++;
    }
    if(n % 2 == 1){
        a[n/2+1][n/2+1] = p+1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
