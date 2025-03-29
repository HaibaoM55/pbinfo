#include <fstream>
using namespace std;
ifstream  fin("arhipelag.in");
ofstream fout("arhipelag.out");
int n, m,x;
char a[1004][1004];
int vi[1004], vj[1004];
int sl[1004], sc[1004];
int dl[1004], dc[1004];
int nrd = 0;
struct insula{
    int a, b;
}vl[1000004], vc[1000004];
int main(){
    fin >> n >> m;
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            a[i][j]=0;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            a[i][j]=x;
        }
    }
    nrd = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j]==1 && a[i-1][j]==0 && a[i][j-1]==0){
                int j1 = j;
                while(a[i][j1]==1){
                    j1++;
                }
                j1--;
                nrd++;
                vc[nrd].a = j;
                vc[nrd].b = j1;
                j = j1;
            }
        }
    }
    nrd = 0;
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(a[i][j]==1 && a[i][j-1] ==0 && a[i-1][j]==0){
                int i1 = i;
                while(a[i1][j]==1){
                    i1++;
                }
                i1--;
                nrd++;
                vl[nrd].a = i;
                vl[nrd].b = i1;
                i = i1;
            }
        }
    }

    for(int i = 1; i <= nrd; i++){
        dl[vl[i].a]++;
        sl[vl[i].b]++;
        dc[vc[i].a]++;
        sc[vc[i].b]++;
    }
    dl[n+1] = 0;
    for(int i = n; i >= 1; i--){
        dl[i] = dl[i+1]+dl[i];///numarul intervalelor care se afla complet incluse in [i...n]
    }
    sl[0] = 0;
    for(int i = 1; i <= n; i++){
        sl[i] = sl[i-1]+sl[i];///numarul intervalelor care se afla complet incluse in [1..i]
    }
    dc[m+1] =0;
    for(int j = m; j >= 1; j--){
        dc[j] = dc[j+1]+dc[j];///numarul intervalelor care se afla complet incluse in [j...m]
    }
    sc[0] = 0;
    for(int j = 1; j <= m; j++){
        sc[j] = sc[j-1]+sc[j];///numarul intervalelor care se afla complet incluse in [1..j]
    }
    int s = 0;
    for(int k = 1; k <= nrd; k++){
        if(1 < vl[k].a){
            s += vl[k].a-1;
        }
    }
    vi[1] = s;
    for(int i = 2; i <= n; i++){
        vi[i] = vi[i-1]+sl[i-1]-dl[i];
    }
    s = 0;
    for(int k = 1; k <= nrd; k++){
        if(1 < vc[k].a){
            s += vc[k].a-1;
        }
    }
    vj[1] = s;
    for(int j = 2; j <= m; j++){
        vj[j] = vj[j-1]+sc[j-1]-dc[j];
    }
    int dtmin = 2e9, dtmini=0, dtminj=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == 0){
                int d = vi[i]+vj[j];
                if(d < dtmin){
                    dtmin = d;
                    dtmini = i;
                    dtminj = j;
                }
            }
        }
    }
    fout << dtmini << ' ' << dtminj;
    return 0;
}
