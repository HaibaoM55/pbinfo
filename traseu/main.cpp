#include <fstream>
using namespace std;
ifstream fin("traseu.in");
ofstream fout("traseu.out");
int n, m;
bool b[104][104][104];
bool a[104][104][104];
int k1, l1, c1;
int k2, l2, c2;
struct coada{
    int k, l, c;
    int dep = 0;
    int pasi = 0;
}q[1000004];
int v[1000004];
int main(){
    fin >> n >> m;
    fin >> k1 >> l1 >> c1;
    fin >> k2 >> l2 >> c2;
    for(int i = 1; i<= m; i++){
        int k,l,c;
        fin >> k >> l >> c;
        b[k][l][c] = true;
    }
    int st = 1, dr = 1;
    q[1].k = k1;
    q[1].l = l1;
    q[1].c = c1;
    q[1].pasi = 1;
    b[k1][l1][c1] = true;
    while(st <= dr){
        int k = q[st].k;
        int c = q[st].c;
        int l = q[st].l;
        if(k == k2 && l == l2 && c == c2){
            fout << q[st].pasi << '\n';
            v[1] = q[st].dep;
            for(int i = 2; i <= q[st].pasi; i++){
                v[i] = q[v[i-1]].dep;
            }
            for(int i = q[st].pasi-1; i >= 1; i--){
                fout << q[v[i]].k << ' ' << q[v[i]].l << ' ' << q[v[i]].c << '\n';
            }
            fout << k2 << ' ' << l2 << ' ' << c2;
        }
        if(k > 1){
            if(b[k-1][l][c] == false){
                dr++;
                q[dr].k = k-1;
                q[dr].c = c;
                q[dr].l = l;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        if(l > 1){
            if(b[k][l-1][c] == false){
                dr++;
                q[dr].k = k;
                q[dr].l = l-1;
                q[dr].c = c;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        if(c > 1){
            if(b[k][l][c-1] == false){
                dr++;
                q[dr].k = k;
                q[dr].l = l;
                q[dr].c = c-1;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        if(c < n){
            if(b[k][l][c+1] == false){
                dr++;
                q[dr].k = k;
                q[dr].l = l;
                q[dr].c = c+1;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        if(l < n){
            if(b[k][l+1][c] == false){
                dr++;
                q[dr].k = k;
                q[dr].l = l+1;
                q[dr].c = c;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        if(k < n){
            if(b[k+1][l][c] == false){
                dr++;
                q[dr].k = k+1;
                q[dr].l = l;
                q[dr].c = c;
                q[dr].pasi = q[st].pasi+1;
                q[dr].dep = st;
                b[q[dr].k][q[dr].l][q[dr].c] = true;
            }
        }
        st++;
    }
    return 0;
}
