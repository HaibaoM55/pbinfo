#include <iostream>
using namespace std;
int n, m, k;
int x, y;
int f[104];
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        f[x]++;
        f[y]++;
    }
    bool ok = false;
    for(int i = 1; i <= n; i++){
        if(f[i] == k){
            ok = true;
            cout << i << ' ';
        }
    }
    if(!ok){
    	cout << "Nu exista";
    }
    return 0;
}
