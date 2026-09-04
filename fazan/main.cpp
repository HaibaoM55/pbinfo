#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
string s[67];
int v[41];
bool b[41];
bool ok = false;
bool compatibil(int i, int j){
    int l = s[i].size();
    return (s[i][l-2] == s[j][0] && s[i][l-1] == s[j][1]);
}
void bt(int k){
    if(k == m+1){
        ok = true;
        for(int i = 1; i <= m; i++){
            cout << s[v[i]] << ' ';
        }
        cout << '\n';
        return;
    }else{
        for(int i = 1; i <= n; i++){
            if(k == 1 || (compatibil(v[k-1], i) && !b[i])){
                v[k] = i;
                b[i] = true;
                bt(k+1);
                b[i] = false;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    sort(s+1, s+n+1);
    bt(1);
    if(!ok){
        cout << "IMPOSIBIL";
    }
    return 0;
}
