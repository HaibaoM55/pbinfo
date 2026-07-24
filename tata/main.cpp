#include <iostream>
#include <vector>
using namespace std;
int n;
int v1[100004];
bool viz[100004];
int f0=0;
vector<int> v[100004];
void bt(int k){
    int l = v[k].size();
    for(int i = 0; i < l; i++){
        if(!viz[v[k][i]]){
            viz[v[k][i]] = true;
            bt(v[k][i]);
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v1[i];
        v[v1[i]].push_back(i);
    }
    bool ok = true;
    for(int i = 1; i <= n; i++){
        if(i == v1[v1[i]]){
            ok = false;
        }
        if(v1[i] == 0){
            f0++;
            if(f0 == 2){
                ok = false;
            }
        }
    }
    viz[0]= true;
    bt(0);
    for(int i = 1; i <= n; i++){
        if(!viz[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "DA";
    }else{
        cout << "NU";
    }
    return 0;
}
