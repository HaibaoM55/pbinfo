#include <fstream>
using namespace std;
ifstream fin("cladire3.in");
ofstream fout("cladire3.out");
int n, m;
int a[204][204];
int b[204][204];
int valmax = 2e9;
struct poz{
    int i, j, val;
    int prev;
}coada[1000004];
poz v[1000004];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
            b[i][j] = 2e9;
        }
    }
    coada[1].i = n;
    coada[1].j = 1;
    coada[1].val = a[n][1];
    coada[1].prev = -1;
    int st = 1, dr = 1;
    int k = -1;
    while(st <= dr){
        if(coada[st].i == 1 && coada[st].j == m){
            if(coada[st].val < valmax){
                valmax = coada[st].val;
                k = st;
            }
            st++;
            continue;
        }
        int i = coada[st].i;
        int j = coada[st].j;
        int val = coada[st].val;
        if(b[i][j] >= val){
            b[i][j] = val;
            if(i > 1){
                if(b[i-1][j] > val+a[i-1][j]){
                    b[i-1][j] = val+a[i-1][j];
                    dr++;
                    coada[dr].i = i-1;
                    coada[dr].j = j;
                    coada[dr].val = val+a[i-1][j];
                    coada[dr].prev = st;
                }
            }
            if(j < m){
                if(b[i][j+1] > val+a[i][j+1]){
                    b[i][j+1] = val+a[i][j+1];
                    dr++;
                    coada[dr].i = i;
                    coada[dr].j = j+1;
                    coada[dr].val = val+a[i][j+1];
                    coada[dr].prev = st;
                }
            }
            st++;
        }else{
            st++;
            continue;
        }
    }
    fout << valmax << '\n';
//    int z = 0;
//    while(k != -1){
//        z++;
//        v[z] = coada[k];
//        k = coada[k].prev;
//    }
//    for(int i = z; i >= 1; i--){
//        fout << v[i].i << ' ' << v[i].j << '\n';
//    }
    return 0;
}
