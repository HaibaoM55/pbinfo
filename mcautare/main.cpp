#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[101][101];
int k;
struct pv{
    int nr, i;
    bool ok;
}v[1001];
bool f[1001][101];
bool comparan(pv a, pv b){
    if(a.nr < b.nr){
        return true;
    }
    return false;
}
bool comparai(pv a, pv b){
    if(a.i < b.i){
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> v[i].nr;
        v[i].i = i;
    }
    sort(v+1, v+k+1, comparan);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int p1 = 1;
            int p2 = k;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(v[mij].nr < a[i][j]){
                    p1 = mij+1;
                }else{
                    p2 = mij-1;
                }
            }
            if(v[p1].nr == a[i][j]){
                for(int p = p1; p <= k; p++){
                    if(v[p].nr == v[p1].nr){
                        f[p][i] = true;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= k; i++){
        bool ok = true;
        for(int j = 1; j <= n; j++){
            if(f[i][j] == false){
                ok = false;
                break;
            }
        }
        v[i].ok = ok;
    }
    sort(v+1, v+k+1, comparai);
    for(int i = 1; i <= k; i++){
        if(v[i].ok){
            cout << "DA\n";
        }else{
            cout << "NU\n";
        }
    }
    return 0;
}
