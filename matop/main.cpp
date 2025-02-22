#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("matop.in");
ofstream fout("matop.out");
int n, k;
int nr = 0;
int diag[25004];
int f[25004];
struct poz{
    int i, j, val=0;
}v[100004];
struct query{
    int c, lin, col, val;
}p[100004];
bool compara(poz a, poz b){
    if(a.i < b.i){
        return true;
    }else if(a.i == b.i){
        if(a.j < b.j){
            return true;
        }
    }
    return false;
}
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= k; i++){
        fin >> p[i].c;
        /*
        1 LIN VAL: toate elementele de pe linia LIN cu valoarea mai mică decât VAL iau valoarea VAL.
        2 COL VAL: toate elementele de pe coloana COL cu valoarea mai mică decât VAL iau valoarea VAL.
        3 LIN COL: să se afişeze valoarea elementului de pe linia LIN şi coloana COL.
        4: să se afişeze suma elementelor de pe diagonala principală.
        */
        if(p[i].c == 1){
            fin >> p[i].lin >> p[i].val;
        }else if(p[i].c == 2){
            fin >> p[i].col >> p[i].val;
        }else if(p[i].c == 3){
            fin >> p[i].lin >> p[i].col;
            nr++;
            v[nr].i = p[i].lin;
            v[nr].j = p[i].col;
        }
    }
    sort(v+1, v+nr+1, compara);
    f[n+1] = nr+1;
    int lin = 0;
    for(int i = 1; i <= nr; i++){
        while(lin < v[i].i){
            lin++;
            f[lin] = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == 0){
            f[i] = f[i-1];
        }
    }
    long long s = 0;
    for(int i = 1; i <= k; i++){
        if(p[i].c == 1){
            if(diag[p[i].lin] < p[i].val){
                s = s+(p[i].val-diag[p[i].lin]);
                diag[p[i].lin] = p[i].val;
            }
            int p1 = 1, p2 = nr;
            for(int j = f[p[i].lin]; j <= nr; j++){
                if(v[j].i > p[i].lin){
                    break;
                }
                if(v[j].i == p[i].lin && v[j].val < p[i].val){
                    v[j].val = p[i].val;
                }
            }
        }else if(p[i].c == 2){
            if(diag[p[i].col] < p[i].val){
                s = s+(p[i].val-diag[p[i].col]);
                diag[p[i].col] = p[i].val;
            }
            for(int j = 1; j <= nr; j++){
                if(v[j].j == p[i].col && v[j].val < p[i].val){
                    v[j].val = p[i].val;
                }
            }
        }else if(p[i].c == 3){
            for(int j = f[p[i].lin]; j <= nr; j++){
                if(v[j].i > p[i].lin){
                    break;
                }
                if(v[j].j == p[i].col){
                    fout << v[j].val;
                    break;
                }
            }
            fout << '\n';
        }else{
            fout << s << '\n';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
