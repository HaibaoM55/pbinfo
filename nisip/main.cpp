#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
ifstream fin("nisip.in");
ofstream fout("nisip.out");
int n, m;
int f[1000004];
int a[1000004];
int misc[1000004];
int nrp = 0, nrnis=0;
int urm[1000004];
int nru = 0;
struct intrebare{
    int q, t, p;
    int i;
}v[1000004];
bool compara(intrebare a, intrebare b){
    if(a.t < b.t){
        return true;
    }else if(a.t == b.t){
        return a.q < b.q;
    }
    return false;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> v[i].q >> v[i].t >> v[i].p;
    }
    int j = 1;
    int t = 1;
    while(j <= m){
        int k = 0;
        while(nru > 0){
            if(a[urm[nru]] == 2){
                a[urm[nru]] = 0;
                if(a[urm[nru]-1] == 1){
                    k++;
                    misc[k] = urm[nru]-1;
                }
            }else if(a[urm[nru]] == 1){
                a[urm[nru]] = 0;
                a[urm[nru]+1] = 1;
                if(a[urm[nru]-1] == 1){
                    k++;
                    misc[k] = urm[nru]-1;
                }
                if(a[urm[nru]+2] == 0){
                    k++;
                    misc[k] = urm[nru]+1;
                }
            }
            nru--;
        }
        while(nru < k){
            nru++;
            urm[nru] = misc[nru];
        }
        if(v[j].t == t && v[j].q == 1){
            nru++;
            urm[nru] = v[j].p;
            j++;
        }
        if(v[j].t == t && v[j].q == 2){
            fout << a[v[j].p] << "\n";
            j++;
        }
        t++;
    }
    return 0;
}
