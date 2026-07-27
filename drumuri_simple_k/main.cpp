#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
int x, y;
vector<int> f[24];
bool ok = true;
bool viz[24][24];
int v[14];
void bt(int kk){
    if(kk == k+2){
        for(int i = 1; i <= k+1; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        ok = false;
    }else{
        int old = v[kk-1];
        int l = f[old].size();
        for(int i = 0; i < l; i++){
            if(!viz[old][f[old][i]]){
                viz[old][f[old][i]] = true;
                v[kk] = f[v[kk-1]][i];
                bt(kk+1);
                viz[old][f[old][i]] = false;
            }
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        f[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        f[0].push_back(i);
        sort(f[i].begin(), f[i].end());
    }
    bt(1);
    if(ok){
        cout << "Nu exista";
    }
    return 0;
}
