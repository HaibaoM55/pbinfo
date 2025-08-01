#include <iostream>
#include <algorithm>
using namespace std;
int n, m, z = 0;
char p;
int v[10004];
int a[104][104];
int main(){
    cin >> n >> m;
    cin >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            z++;
            cin >> v[z];
        }
    }
    sort(v+1, v+z+1);
    if(p == '+'){
        z = 0;
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                z++;
                a[i][j] = v[z];
            }
        }
    }else{
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                a[i][j] = v[z];
                z--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
