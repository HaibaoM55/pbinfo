#include <iostream>
#include <vector>
using namespace std;
int n;
int t[200004], f[200004];
int poz[200004];
bool viz[200004];
vector<int> v;
void visit(int k){
    while(!viz[k]){
        viz[k] = true;
        f[k] = -1;
        poz[k] = (int)v.size();
        v.push_back(k);
        k = t[k];
    }
    if(f[t[k]] == -1){
        int l = v.size();
        for(int i = poz[k]; i < l; i++){
            f[v[i]] = l-poz[k];
        }
        for(int i = poz[k]-1; i  >= 0; i--){
            f[v[i]] = f[v[i+1]]+1;
        }
    }else{
        int l = v.size();
        int nrp = f[k]+1;
        for(int i = l-1; i >= 0; i--){
            f[v[i]] = nrp;
            nrp++;
        }
    }
    v.clear();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            visit(i);
        }
        cout << f[i] << ' ';
    }
    return 0;
}
