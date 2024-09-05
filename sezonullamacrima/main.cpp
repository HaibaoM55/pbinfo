#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
struct interval{
    int a, b;
    int i;
}v[200000];
int n;
int minim = 1000000004;
int maxim = 1000000004;
bool f1[200004], f2[200004];
bool compara(interval x, interval y){
    if(x.a < y.a || (x.a == y.a && x.b >y.b)){
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i].a >> v[i].b;
        v[i].i = i;
    }
    sort(v+1, v+n+1, compara);
    maxim = v[1].b;
    for(int i = 2; i <= n; i++){
        //v[j].a <= v[i].a și v[i].b <= v[j].d => f2
        if(v[i].b <= maxim){
            f2[v[i].i] = true;
        }else{
            maxim = v[i].b;
        }
    }
    minim = v[n].b;
    for(int i = n-1; i >= 1; i--){
        //v[i].a <= v[j].a și v[j].b <= v[i].d => f1
        if(v[i].b >= minim){
            f1[v[i].i] = true;
        }else{
            minim = v[i].b;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << f1[i] << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << f2[i] << ' ';
    }
    return 0;
}
