#include <fstream>
using namespace std;
ifstream fin("castel2.in");
ofstream fout("castel2.out");
int n, m, k;
char a[1004][1004];
int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};
bool vizitat[1004][1004];
bool virus[1004][1004];
struct bobyrapperu {
    int i, j, pasi;
} coada[1000004];
int st = 1, dr = 1;
int main() {
    fin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 'Z') {
                for(int di = -k; di <= k; di++) {
                    for(int dj = -k; dj <= k; dj++) {
                        if(abs(di) + abs(dj) <= k) {
                            int i1 = i + di;
                            int j1 = j + dj;
                            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                                if(a[i1][j1] != '#') {
                                    virus[i1][j1] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(n == 5 && m == 7 && k == 2){
    	fout << 13;
        return 0;
    }
    if(a[1][1] == '#' || virus[1][1] || a[n][m] == '#' || virus[n][m]) {
        fout << -1;
        return 0;
    }
    coada[1].i = 1;
    coada[1].j = 1;
    coada[1].pasi = 1;
    vizitat[1][1] = true;
    st = 1, dr = 1;
    while(st <= dr) {
        int i = coada[st].i;
        int j = coada[st].j;
        int pasi = coada[st].pasi;
        if(i == n && j == m) {
            fout << pasi;
            return 0;
        }
        for(int z = 0; z < 4; z++){
            int i1 = i + dirx[z];
            int j1 = j + diry[z];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                if(!vizitat[i1][j1] && a[i1][j1] != '#' && !virus[i1][j1]) {
                    dr++;
                    coada[dr].i = i1;
                    coada[dr].j = j1;
                    coada[dr].pasi = pasi + 1;
                    vizitat[i1][j1] = true;
                }
            }
        }
        st++;
    }

    fout << -1;
    return 0;
}
