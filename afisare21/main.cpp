#include <iostream>
using namespace std;
int n, m, x;
int vmin = 1000000004;
int v[10004];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> x;
        vmin = min(vmin, x);
    }
    bool exista = false;
    for(int i= 1; i <= n; i++){
        if(v[i] < vmin){
            cout << v[i] << ' ';
            exista = true;
        }
    }
    if(!exista){
        cout << "NU EXISTA";
    }
    return 0;
}
