#include <iostream>
using namespace std;
int n;
int v[1025][1025];
void kp(int i1, int j1, int i2, int j2, int val){
    if(val == 0){
        return;
    }
//    cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n';
//    cout << endl;
    int p = 1 << val-1;
    int mi=(i1+i2)/2, mj=(j1+j2)/2;
    v[mi][mj] = val;
    if(val > 1){
        kp(i1, j1, mi-1, mj-1, val-1);
        kp(mi+1, j1, i2, mj-1, val-1);
        kp(i1, mj+1, mi-1, j2, val-1);
        kp(mi+1, mj+1, i2, j2, val-1);
    }
}
int main(){
    cin >> n;
    int pm = 1 << n;
    pm--;
    kp(1, 1, pm, pm, n);
    for(int i = 1; i <= pm; i++){
        for(int j = 1; j <= pm; j++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
