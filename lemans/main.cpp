#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("lemans.in");
ofstream fout("lemans.out");
long long n, m, t, nr, rez;
struct benone{
  long long x, i, j;
} a[2000005];
long long v[1005], f[1005], r[1005];
bool compara(benone x, benone y){
    return x.x < y.x;
}
int main() {
    fin >> t >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int nr = 0;
    for(int i = 1; i <= m; i++){
        int x;
        fin >> x;
        for(int j = 1; j <= n; j++){
            nr++;
            a[nr].x = v[j]*t+x;
            a[nr].i = i;
            a[nr].j = j;
        }
    }
    sort(a + 1, a + nr + 1, compara);
    int p1 = 1, p2 = 1, k = 0, x = 0, y = 0;
    long long rez = 1e17;
    while (p2 <= nr) {
        f[a[p2].j]++;
        if(f[a[p2].j] == 1){
            k++;
        }
        if(k == n) {
            while(p1 < p2 && f[a[p1].j] > 1){
                f[a[p1].j]--;
                p1++;
            }
            if(a[p2].x - a[p1].x < rez){
                rez = a[p2].x - a[p1].x;
                x = p1;
                y = p2;
            }
        }
        p2++;
    }
    fout << rez << '\n';
    for(int i = x; i <= y; i++){
        r[a[i].j] = a[i].i;
    }
    for (int i = 1; i <= n; i++){
        fout << r[i] << ' ';
    }
    return 0;
}
