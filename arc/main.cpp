#include <fstream>
using namespace std;
ifstream fin("arc.in");
ofstream fout("arc.out");
int p, n;
int v[10004];
int a[10004];
void remove(int i1, int j1, int &n){
    int k = 0, r = 0;
    for(int i = 1; i <= n; i++){
        if(i < i1 || i > j1)
            v[++k] = v[i];
        else r++;
    }
    n -= r;
    int st = i1, dr = i1;
    while(v[st] == v[i1])
        st--;
    while(v[dr] == v[i1])
        dr++;
    st++, dr--;
    if(dr - st + 1 >= 3 && st != i1)
        remove(st, dr, n);
}
int main()
{
    fin >> p >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int nrs = 0;
    v[0] = -1;
    if(p == 1){
        for(int i = 1; i <= n; i++){
            if(v[i] != v[i-1]){
                nrs++;
            }
        }
        fout << nrs;
    }else{
        bool ok = true;
        while(ok && n > 0){
            ok = false;
            int p1 = 0, p2 = 0, lmax = 0;
            int p = 0, st = 0, dr = 0;
            for(int i = 1; i <= n; i++){
                if(v[i] != p){
                    if(p1 && lmax < p2 - p1 + 1){
                        lmax = p2 - p1 + 1;
                        st = p1;
                        dr = p2;
                    }
                    p2 = i;
                    p1 = i;
                    p = v[i];
                }else{
                    p2++;
                }
            }
            if(p1 && lmax < p2 - p1 + 1){
                lmax = p2 - p1 + 1;
                st = p1;
                dr = p2;
            }
            if(p1 && lmax >= 3){
                remove(st, dr, n);
            }
            if(lmax >= 3){
                ok = true;
            }
        }
        fout << n << '\n';
        for(int i = 1; i <= n; i++){
            fout << v[i] << '\n';
        }
    }
    return 0;
}
