#include <iostream>
using namespace std;
int n;
int a[66][66];
int z= 0;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            z++;
            a[(i-1)*3+1][(j-1)*3+1]=z;a[(i-1)*3+1][(j-1)*3+2]=0;a[(i-1)*3+1][(j-1)*3+3]=z;
            a[(i-1)*3+2][(j-1)*3+1]=0;a[(i-1)*3+2][(j-1)*3+2]=z;a[(i-1)*3+2][(j-1)*3+3]=0;
            a[(i-1)*3+3][(j-1)*3+1]=z;a[(i-1)*3+3][(j-1)*3+2]=0;a[(i-1)*3+3][(j-1)*3+3]=z;
        }
    }
    for(int i = 1; i <= 3*n; i++){
        for(int j = 1; j <= 3*n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
