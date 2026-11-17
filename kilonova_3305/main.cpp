#include <iostream>
using namespace std;
int n, q, a, b;
int v[200004];
int s[1048580];
int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        for(int j = 0; j < 20; j++){
            if(v[i] & (1<<j)){
                s[1<<j] = s[1<<j] | v[i];
            }
        }
    }
    for(int i=0; i<(1<<20); i++){
        for(int j=0; j<20; j++){
            if(i&(1<<j)){
                s[i] = s[i] | s[(i^(1<<j))];
            }
        }
    }
    while(q){
        q--;
        cin >> a >> b;
        a = v[a];
        b = v[b];
        int cnt=1;
        while(!(a&b) && s[a]!=a){
            a=s[a];
            cnt++;
        }
        if(!(a & b)){
            cout << -1 << '\n';
            continue;
        }
        cout << cnt << '\n';
    }
    return 0;
}
