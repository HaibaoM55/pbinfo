#include <fstream>
#include <map>
using namespace std;
ifstream fin("teleportor.in");
ofstream fout("teleportor.out");
int n, k, q;
struct poz{
    int i, j;
};
map<int, poz>v[1000004];
bool b[1000004];
int a[1004][1004];
int zm[1000004];
int nrt(){
    int nr = 0;
    for(int ic = 1; ic < k; ic++){
        int l = v[ic].size();
        bool ok = false;
        for (auto &p : v[ic]){
            poz poz1 = p.second;
            int i1 = poz1.i;
            int j1 = poz1.j;
            if(a[i1+1][j1] == ic+1 || a[i1][j1+1] == ic+1 || a[i1][j1-1] == ic+1 || a[i1-1][j1] == ic+1){
                ok = true;
                break;
            }
        }
        b[ic] = ok;
        if(!ok){
            nr++;
        }
    }
    return nr;
}
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
            poz pozitie;
            pozitie.i = i;
            pozitie.j = j;
            zm[a[i][j]]++;
            v[a[i][j]][zm[a[i][j]]] = pozitie;
        }
    }
    int nr = nrt();
    fout << nr << '\n';
    fin >> q;
    for(int z = 1; z <= q; z++){
        int i, j, c;
        fin >> i >> j >> c;
        for (auto &p : v[a[i][j]]){
            poz poz1 = p.second;
            if(poz1.i == i && poz1.j == j){
                v[a[i][j]].erase(p.first);
                break;
            }
        }
        int oa = a[i][j];
        a[i][j] = c;
        poz pozitie;
        pozitie.i = i;
        pozitie.j = j;
        zm[c]++;
        v[c][zm[c]] = pozitie;
        if(1 <= oa && oa <= k){
            if(b[oa]){
                bool ok = false;
                for(auto &p : v[oa]){
                    poz poz1 = p.second;
                    int i1 = poz1.i;
                    int j1 = poz1.j;
                    if(a[i1+1][j1] == oa+1 || a[i1][j1+1] == oa+1 || a[i1][j1-1] == oa+1 || a[i1-1][j1] == oa+1){
                        ok = true;
                        break;
                    }
                }
                if(!ok){
                    b[oa] = false;
                    nr++;
                }
            }
        }
        if(1 <= oa-1 && oa-1 <= k){
            if(b[oa-1]){
                bool ok = false;
                for(auto &p : v[oa-1]){
                    poz poz1 = p.second;
                    int i1 = poz1.i;
                    int j1 = poz1.j;
                    if(a[i1+1][j1] == oa || a[i1][j1+1] == oa || a[i1][j1-1] == oa || a[i1-1][j1] == oa){
                        ok = true;
                        break;
                    }
                }
                if(!ok){
                    b[oa-1] = false;
                    nr++;
                }
            }
        }
        if(1 <= c-1 && c-1 <= k){
            if(!b[c-1]){
                bool ok = false;
                for(auto &p : v[c-1]){
                    poz poz1 = p.second;
                    int i1 = poz1.i;
                    int j1 = poz1.j;
                    if(a[i1+1][j1] == c || a[i1][j1+1] == c || a[i1][j1-1] == c || a[i1-1][j1] == c){
                        ok = true;
                        break;
                    }
                }
                if(ok){
                    b[c-1] = true;
                    nr--;
                }
            }
        }
        if(1 <= c && c <= k){
            if(!b[c]){
                bool ok = false;
                int i1 = i;
                int j1 = j;
                if(a[i1+1][j1] == c+1 || a[i1][j1+1] == c+1 || a[i1][j1-1] == c+1 || a[i1-1][j1] == c+1){
                    ok = true;
                }
                if(ok){
                    b[c] = true;
                    nr--;
                }
            }
        }
        fout << nr << '\n';
    }
    return 0;
}
