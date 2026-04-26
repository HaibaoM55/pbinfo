#include <iostream>
#include <vector>
using namespace std;
int n, s;
int v[10], c[10];
vector<int> corect;
void bt(int i, int sm, vector<int> f){
    if(i == n+1){
        if(sm == s){
            corect = f;
        }
        return;
    }
    f.push_back(0);
    bt(i+1, sm, f);
    for(int i1 = 1; i1 <= c[i]; i1++){
        sm += v[i];
        f[i-1] = i1;
        bt(i+1, sm, f);
    }
}
vector<int> clearv;
int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    bt(1, 0, clearv);
    for(int i = 0; i < n; i++){
        cout << corect[i] << ' ';
    }
    return 0;
}
