#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, x, y;
vector<int> v[200004];
int c[200004], t[200004];
vector<set<int>> st(200004);
int f[200004];
void stabileste_parinti(int nod, int par) {
    t[nod] = par;

    for(int vecin : v[nod]) {
        if(vecin != par) {
            stabileste_parinti(vecin, nod);
        }
    }
}
void dfs(int i, int parent = -1){
    st[i].insert(c[i]);
    for(int copil: v[i]){
        if(copil == parent) continue;
        dfs(copil, i);
        if(st[i].size() < st[copil].size()){
            swap(st[i], st[copil]);
        }
        for(int x : st[copil]){
            st[i].insert(x);
        }
        st[copil].clear();
    }
    f[i] = st[i].size();
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i < n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    stabileste_parinti(1, 0);
    for(int i = 1; i <= n; i++){
        v[i].clear();
    }
    for(int i = 1; i <= n; i++){
        v[t[i]].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << f[i] << ' ';
    }
    return 0;
}
