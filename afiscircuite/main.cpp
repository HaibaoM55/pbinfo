#include <iostream>
#include <vector>
using namespace std;
int n, m;
int x, y;
bool viz[104];
vector<int> v[104];
int p = 0;
vector<int> cc[104];
int nr = 0;
void visit(int k){
    viz[k] = true;
    cc[p].push_back(k);
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
bool f[104][104];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        f[x][y] = true;
    }
    /*
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            p++;
            visit(i);
            if(cc[p].size() == 3){
                nr++;
            }
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= p; i++){
        if(cc[p].size() == 3){
            cout << cc[i][0] << ' ' << cc[i][1] << ' ' << cc[i][2] << '\n';
        }
    }*/
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(i != j && j != k && i != k){
                    if(f[i][j] && f[j][k] && f[k][i]){
                        cout << i << ' ' << j << ' ' << k << '\n';
                    }
                }
            }
        }
    }
    return 0;
}
