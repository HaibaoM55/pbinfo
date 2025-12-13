#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("picioroange.in");
ofstream fout("picioroange.out");
int n;
int start, sfarsit;
int v[104];
struct coada{
    int val, pasi;
}c[1000104];
int r = 0;
bool vizitat[1000104];
int f[1000104];
int l;
bool compara(int a, int b){
    return b < a;
}
void bt(int x, int pasi){
    f[x] = min(f[x], pasi);
    for(int i = 1; i <= n; i++){
        if(v[i]+x <= l+100){
            if(pasi < f[v[i]+x]){
                bt(v[i]+x, pasi+1);
            }
        }
        if(v[i]-x > 0){
            if(pasi < f[v[i]-x]){
                vizitat[v[i]-x] = true;
                bt(v[i]-x, pasi+1);
            }
        }
    }
}
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    fin >> start >> sfarsit;
    if(start > sfarsit){
        swap(start, sfarsit);
    }
    if(sfarsit <= 1000){
        sort(v+1, v+n+1, compara);
        l = sfarsit-start;
        for(int i = 1; i <= 1000100; i++){
            f[i] = 2e9;
        }
        bt(0, 0);
        fout << f[l];
		return 0;
    }
    int st = 1, dr = n;
    for(int i = 1; i <= n; i++){
        c[i].val = v[i];
        c[i].pasi = 1;
        vizitat[v[i]] = true;
    }
    while(st <= dr){
        if(c[st].val == sfarsit-start){
            fout << c[st].pasi;
            return 0;
        }
        for(int i = 1; i <= n; i++){
            if(c[st].val+v[i] <= 1000100){
                if(!vizitat[c[st].val+v[i]]){
                    vizitat[c[st].val+v[i]] = true;
                    dr++;
                    c[dr].pasi = c[st].pasi+1;
                    c[dr].val = c[st].val+v[i];
                    if(c[dr].val == sfarsit-start){
                        fout << c[dr].pasi;
                        return 0;
                    }
                }
            }
            if(c[st].val-v[i] > 0){
                if(!vizitat[c[st].val-v[i]]){
                    vizitat[c[st].val-v[i]] = true;
                    dr++;
                    c[dr].pasi = c[st].pasi+1;
                    c[dr].val = c[st].val-v[i];
                    if(c[dr].val == sfarsit-start){
                        fout << c[dr].pasi;
                        return 0;
                    }
                }
            }
        }
        st++;
    }
    return 0;
}
