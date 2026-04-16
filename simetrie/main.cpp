#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MOD 1000000007
int n, m;
struct pos{
    int i, j;
};
map<int, vector<pos>> f;
long long rasp(int n, int m) {
    return (1LL*n*(n+1)*(n+2)/6*m*(m+1)*(m+2)/6)%MOD;
}
int main(){
    cin >> n >> m;
    int a[n+4][m+4];
    long long s[n+4][m+4];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            f[a[i][j]].push_back({i, j});
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    long long suma = 0;
    if(f.size() == 1){
        cout << (1LL*rasp(n, m)*a[1][1])%MOD;
        return 0;
    }
    for(auto nr: f){
        int l = nr.second.size();
        for(int i = 0; i < l; i++){
            for(int j = i; j < l; j++){
                int i1 = nr.second[i].i;
                int j1 = nr.second[i].j;
                int i2 = nr.second[j].i;
                int j2 = nr.second[j].j;
                if(j1 <= j2){
                    suma += s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1];
                    suma = suma % MOD;
                }
            }
        }
    }
    cout << suma;
    return 0;
}
