#include <iostream>
using namespace std;
int n, m;
int a[104][104];
int mat[104][104];
int inloc(int x){
    int rasp = 0;
    for(int d = 2; d*d <= x; d++){
        if(x % d == 0){
            while(x % d == 0){
                x = x/d;
            }
            rasp++;
        }
    }
    if(x > 1) rasp++;
    return rasp;
}
int nrdiv(int x){
    if(x == 1) return 1;
    int rasp = 2;
    for(int d = 2; d*d <= x; d++){
        if(x % d == 0){
            rasp++;
            if(d*d < x) rasp++;
        }
    }
    return rasp;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            mat[i][j] = inloc(a[i][j]);
        }
    }
    int z = n;
    for(int i = 1; i <= n; i++){
        mat[i][i] = nrdiv(a[i][i]);
        mat[i][z] = nrdiv(a[i][z]);
        z--;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
