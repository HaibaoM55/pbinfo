#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[100004];
int b[100004];
bool ciur[1000004];
int prm[100004], nrp;
int p, q;
int box[80000][302];
int L = 300;
int main()
{
    vector<long long> c[1000004];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2; i <= 1000000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <=1000000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    for(int i = n; i >= 1; i--){
        int x = b[i];
        for(int j = 1; j <= nrp && prm[j]*prm[j] <= x; j++){
            if(x % prm[j] == 0){
                c[prm[j]].push_back(b[i]);
                int l = c[prm[j]].size();
                if(l > 1){
                    c[prm[j]][l-1] += c[prm[j]][l-2];
                }
                while(x % prm[j] == 0){
                    x = x / prm[j];
                }
            }
        }
        if(x > 1){
            c[x].push_back(b[i]);
            int l = c[x].size();
            if(l > 1){
                c[x][l-1] += c[x][l-2];
            }
        }
    }
    cin >> m;
    for(int i = 1;i <= m; i++){
        cin >> p >> q;
        long long s = 0;
        int pz = n;
        int nr = 0;
        for(int j = 1; j <= q; j++){
            if(a[j] % p != 0){
                s = s + a[j];
            }else{
                nr++;
            }
        }
        if(nr > 0){
            s = s+ c[p][nr-1];
        }
        cout << s << '\n';
    }
    return 0;
}
