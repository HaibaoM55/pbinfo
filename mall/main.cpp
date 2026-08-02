#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y;
vector<int> v[104];
int f[104];
bool viz[104];
void visit(int k){
    viz[k] = true;
    f[k]++;
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            visit(v[k][i]);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        f[i] = false;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            viz[j] = false;
        }
        visit(i);
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == n){
            cout << i;
            return 0;
        }
    }
    cout << "NU EXISTA";
    return 0;
}
