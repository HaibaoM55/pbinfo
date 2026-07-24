#include <iostream>
using namespace std;
int n, m, x, y;
int intr[104], extr[104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        extr[x]++;
        intr[y]++;
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(intr[i] == 0){
            cout << i << ' ';
            ok = false;
        }
    }
    if(ok){
        cout << "NU EXISTA";
    }
    return 0;
}
