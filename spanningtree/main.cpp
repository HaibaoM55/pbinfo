#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y;
vector<int> v[30004];
int f[30004];
bool viz[30004];
int vmax = 0;
void dfs(int k, int pas){
    int l = v[k].size();
    viz[k] = true;
    f[k] = pas;
    for(int i = 0; i < l; i++){
        if(viz[v[k][i]]){
            vmax = max(vmax, abs(f[k]-f[v[k][i]])+1);
        }else{
            viz[v[k][i]] = true;
            dfs(v[k][i], pas+1);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 1);
    cout << vmax;
    return 0;
}
