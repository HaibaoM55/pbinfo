#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, y, m;
bool viz[104];
vector<int> v[104];
vector<int> cc[104];
int nr = 0;
void visit(int k){
    nr++;
    viz[k] = true;
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
        for(int j = 1; j <= n; j++){
            viz[j] = false;
        }
        visit(i);
        if(nr == n){
            cout << i << ' ';
        }
        nr = 0;
    }
    return 0;
}
