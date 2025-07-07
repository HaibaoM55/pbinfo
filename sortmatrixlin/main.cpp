#include <iostream>
#include <algorithm>
using namespace std;
int n, m, z;
char t;
int v[10004];
int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            z++;
            cin >> v[z];
        }
    }
    sort(v+1, v+z+1);
    if(t == '+'){
        z=0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                z++;
                cout << v[z] << ' ';
            }
            cout << '\n';
        }
    }else{
        z = n*m+1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                z--;
                cout << v[z] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
