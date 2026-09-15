#include <iostream>
#include <vector>
using namespace std;
int n, m, k, q;
int x, y, p, l;
vector<int> v[104];
bool sig[104];
int dist(int a, int b){
    pair<int, int> coada[104];
    bool viz[104];
    for(int i = 1; i <= n; i++){
        viz[i] = false;
    }
    int st = 1, dr = 1;
    coada[1] = {a,0};
    bool siga = sig[a];
    bool sigb = sig[b];
    sig[a] = true;
    sig[b] = true;
    while(st <= dr){
        int k = coada[st].first;
        if(k == b){
            sig[a] = siga;
            sig[b] = sigb;
            return coada[st].second;
        }
        int l = v[k].size();
        for(int i = 0; i < l; i++){
            if(!viz[v[k][i]] && sig[v[k][i]]){
                viz[v[k][i]] = true;
                dr++;
                coada[dr] = {v[k][i], coada[st].second+1};
            }
        }
        st++;
    }
    sig[a] = siga;
    sig[b] = sigb;
    return -1;
}
int main(){
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1; i <= k; i++){
        cin >> x;
        sig[x] = true;
    }
    for(int i = 1; i <= q; i++){
        cin >> p >> l;
        if(dist(p, l) != -1){
            cout << "DA";
        }else{
            cout << "NU";
        }
        cout << '\n';
    }
    return 0;
}
