#include <fstream>
using namespace std;
#define BLOC_SIZE 140
ifstream fin("rev.in");
ofstream fout("rev.out");
int n, m;
int v[100004];
int b[100004];
int x, y, k;
struct query{
    int x, y, k;
}q[20004];
struct pv{
    int st, dr, valoare;
}o[100004];
int rasp_poz(int k, int i){
    int poz = b[k];
    int inceput = i % BLOC_SIZE;
    for(int j = inceput; j % BLOC_SIZE != 0; j--){
        if(q[j].x <= poz && poz <= q[j].y){
            poz = q[j].x + q[j].y - poz;
        }
    }
    return poz;
}
int f[100004];
int p[100004];
void initializare_bloc(){
    int activ = 0;
    for(int i = 1; i <= n; i++){
        activ += f[i];
        p[i] = activ % 2;
    }
    int idx = 1;
    int i = 1;
    while (i <= n) {
        if (p[i] == 0) {
            int j = i;
            while (j <= n && p[j] == 0)
                j++;
            for (int k = i; k < j; k++)
                b[idx++] = k;
            i = j;
        } else {
            int j = i;
            while (j <= n && p[j] == 1)
                j++;
            for (int k = j - 1; k >= i; k--)
                b[idx++] = k;
            i = j;
        }
    }
    for(int i = 1; i <= min(n, 10); i++)
        fout << b[i] << ' ';
    fout << '\n';
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        v[i] = i;
        b[i] = i;
    }
    for(int i = 1; i <= m; i++){
        fin >> q[i].x >> q[i].y >> q[i].k;
        f[q[i].x]++;
        f[q[i].y+1]--;
        fout << rasp_poz(q[i].k, i) << '\n';
        if(i % 1 == 0){
            initializare_bloc();
        }
    }
    return 0;
}
