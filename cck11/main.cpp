#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x, y, pp;
int nr = 0;
bool viz[104];
vector<int> v[104];
vector<int> cc[104];
void visit(int k){
    cc[nr].push_back(k);
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
    cin >> n >> m >> pp;
    while(cin >> x >> y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            nr++;
            visit(i);
        }
    }
    int rasp = 0;
    for(int i = 1; i <= nr; i++){
        if(cc[i].size() == pp){
            rasp++;
        }
    }
    cout << rasp;
    return 0;
}
