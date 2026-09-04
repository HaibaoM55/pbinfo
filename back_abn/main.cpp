#include <iostream>
using namespace std;
char x, y;
int n;
char v[24];
void bt(int k, int vmax){
    if(k == n+1){
        for(int i = 1; i <= n; i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    for(int i = vmax+1; i <= y-'a'; i++){
        v[k] = i+'a';
        bt(k+1, i);
    }
}
int main(){
    cin >> x >> y >> n;
    bt(1, x-'a'-1);
    return 0;
}
