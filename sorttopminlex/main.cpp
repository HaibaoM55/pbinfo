#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, x, y;
vector<int> v[100004], ff[100004];
int f[100004];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        f[y]++;
        v[x].push_back(y);
    }
    int st = 1, dr = 0;
    int vmax = 0;
    priority_queue<int, vector<int>, greater<int>> coada;
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            coada.push(i);
        }
    }
    while(!coada.empty()){
        int k = coada.top();
        coada.pop();
        cout << k << ' ';
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            f[v[k][i]]--;
            if(f[v[k][i]] == 0){
                coada.push(v[k][i]);
            }
        }
    }
    return 0;
}
