#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y;
vector<int> v[100004];
int a[100004];
int drum(int k){
    if(a[k] != 0){
        return a[k];
    }else{
        int pmax = 0;
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            pmax = max(pmax, drum(v[k][i]));
        }
        a[k] = 1+pmax;
        return a[k];
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
    }
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        vmax = max(vmax, drum(i));
    }
    cout << vmax-1;
    return 0;
}
