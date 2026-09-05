#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
string s[67];
int v[41], r[41];
bool b[41];
bool ok = false;
bool compatibil(int i, int j){
    int l = s[i].size();
    return (s[i][l-2] == s[j][0] && s[i][l-1] == s[j][1]);
}
int vmax = 0;
void bt(int k){
    bool nmc = true;
    for(int i = 1; i <= n; i++){
        if(k == 1 || (compatibil(v[k-1], i) && !b[i])){
            nmc = false;
            v[k] = i;
            b[i] = true;
            bt(k+1);
            b[i] = false;
        }
    }
    if(nmc && k-1 > vmax){
        vmax = k-1;
        for(int i = 1; i <= k; i++){
            r[i] = v[i];
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    sort(s+1, s+n+1);
    bt(1);
    for(int i = 1; i <= vmax; i++){
        cout << s[r[i]] << ' ';
    }
    return 0;
}
