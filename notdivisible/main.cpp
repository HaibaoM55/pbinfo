#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;
int n, q;
int v[100005];
vector<int> vecini[100005],primeSmall;
int adancime[100005], parinte[100005][17];
int spf[100000001];
bool eRatSiv[10001];
void factorizeaza(int x, unordered_set<int>& multime){
    while(x > 1){
        int p = spf[x];
        multime.insert(p);
        while(x % p == 0){
            x = x/p;
        }
    }
}
void bfs_lca(int radacina){
    vector<int> coada;
    coada.reserve(n);
    adancime[radacina] = 0;
    parinte[radacina][0] = radacina;
    coada.push_back(radacina);
    vector<bool> vizitat(n + 1, false);
    vizitat[radacina] = true;
    for(int i = 0; i < (int)coada.size(); i++){
        int nod = coada[i];
        for(int vecin : vecini[nod]){
            if(!vizitat[vecin]){
                vizitat[vecin] = true;
                adancime[vecin] = adancime[nod] + 1;
                parinte[vecin][0] = nod;
                coada.push_back(vecin);
            }
        }
    }
    for(int j = 1; j < 17; j++){
        for(int i = 1; i <= n; i++){
            parinte[i][j] = parinte[parinte[i][j-1]][j-1];
        }
    }
}
int lca(int a, int b) {
    if(adancime[a] < adancime[b]){
        swap(a, b);
    }
    int diff = adancime[a] - adancime[b];
    for(int j = 0; j < 17; j++){
        if((diff >> j) & 1){
            a = parinte[a][j];
        }
    }
    if(a == b){
        return a;
    }
    for(int j = 16; j >= 0; j--){
        if(parinte[a][j] != parinte[b][j]){
            a = parinte[a][j];
            b = parinte[b][j];
        }
    }
    return parinte[a][0];
}
void colecteaza_drum(int nod, int stramos, unordered_set<int>& multime){
    while(nod != stramos){
        factorizeaza(v[nod], multime);
        nod = parinte[nod][0];
    }
    factorizeaza(v[stramos], multime);
}
unordered_set<int> factori;
void factorizeazaLocal(int x){
    for(int p : primeSmall){
        if(1LL*p*p > x){
            break;
        }
        if(x % p == 0){
            factori.insert(p);
            while(x % p == 0){
                x /= p;
            }
        }
    }
    if(x > 1){
        factori.insert(x);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2; i < 10001; i++){
        if(!eRatSiv[i]){
            primeSmall.push_back(i);
            for(int j = i*i; j < 10001; j += i){
                eRatSiv[j] = true;
            }
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        vecini[a].push_back(b);
        vecini[b].push_back(a);
    }
    bfs_lca(1);
    cin >> q;
    while(q){
        q--;
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        factori.reserve(64);
        int nod = a;
        while(nod != l){
            factorizeazaLocal(v[nod]);
            nod = parinte[nod][0];
        }
        factorizeazaLocal(v[l]);
        nod = b;
        while(nod != l){
            factorizeazaLocal(v[nod]);
            nod = parinte[nod][0];
        }
        vector<int> valori;
        valori.reserve(adancime[a]+adancime[b]-2*adancime[l]+1);
        nod = a;
        while(nod != l){
            valori.push_back(v[nod]);
            nod = parinte[nod][0];
        }
        valori.push_back(v[l]);
        nod = b;
        while(nod != l){
            valori.push_back(v[nod]);
            nod = parinte[nod][0];
        }
        int raspuns = -1;
        int k = 2;
        while(k){
            bool bun = true;
            for(int val : valori){
                if(k % val == 0){
                    bun = false;
                    break;
                }
            }
            if(bun){
                raspuns = k;
                break;
            }
            k++;
        }
        cout << raspuns << '\n';
    }
    return 0;
}
