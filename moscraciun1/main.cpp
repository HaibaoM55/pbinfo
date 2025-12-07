#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int v[1004];
int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v+1, v+n+1);
    int nr = 0;
    int sc = 0;
    for(int i = 1; i <= n; i++){
        if(sc + v[i] <= s){
            sc += v[i];
            nr++;
        }
    }
    int sn=0;
    if(nr == n){
        sn = 0;
    }else{
        int br = s - sc;
        sn = v[nr+1] - br;
    }
    cout << nr << ' ' << sn;
    return 0;
}
