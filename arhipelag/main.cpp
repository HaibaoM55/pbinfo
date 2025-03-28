#include <fstream>
using namespace std;
ifstream fin("arhipelag.in");
ofstream fout("arhipelag.out");
int n, m;
bool a[1004][1004], b[1004][1004];
int vi[1004], vj[1004];
int sl[1004], sc[1004];
int dl[1004], dc[1004];
int nrd = 0;
struct insula{
    int a, b;
}vl[1000004], vc[1000004];
int modul(int x){
    if(x < 0){
        return -x;
    }
    return x;
}
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> a[i][j];
        }
    }
    nrd = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] && a[i-1][j]==0){
                int j1 = j;
                while(a[i][j1]){
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
            if(a[i][j] && a[i][j-1] ==0){
                int i1 = i;
                while(a[i1][j]){
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
    for(int j = 1; j <= m; j++){
        int s = 0;
        for(int k = 1; k <= nrd; k++){
            if(j < vc[k].a){
                s += vc[k].a-j;
            }else if(vc[k].b < j){
                s += j-vc[k].b;
            }
        }
        vj[j] = s;
    }
    int s = 0;
    /*int k1 = 0;
    int k2 = 0;
    int k3 = 0;

    for(int i = 2; i <= n; i++){
        int b1 = k1;
        k1 += k2;
        int p = k1;
        k2 = 0;
        while(vl[p].a <= i && i <= vl[p].b){
            k2++;
            p++;
        }
        k3 = n-k1-k2;
        int a1 = k3;
        s = s-b1+a1;
        fout << k1 << ' '<< k2 << ' ' << k3 << endl;
        vi[i] = s;
    }*/
    /*for(int i = 1; i <= n; i++){
        int s = 0;
        for(int k = 1; k <= nrd; k++){
            if(i < vl[k].a){
                s += vl[k].a-i;
            }else if(vl[k].b < i){
                s += i-vl[k].b;
            }
        }
        vi[i] = s;
        fout << s << ' ';
    }*/
    for(int i = 1; i <= nrd; i++){
        dl[vl[i].a]++;
        sl[vl[i].b]++;
        dc[vc[i].a]++;
        sc[vc[i].b]++;
    }
    dl[n+1] = 0;
    for(int i = n; i >= 1; i--){
        dl[i] = dl[i+1]+dl[i];
    }
    sl[0] = 0;
    for(int i = 1; i <= n; i++){
        sl[i] = sl[i-1]+sl[i];
    }
    dc[m+1] =0;
    for(int j = m; j >= 1; j--){
        dc[j] = dc[j+1]+dc[j];
    }
    sc[0] = 0;
    for(int j = 1; j <= m; j++){
        sc[j] = sc[j-1]+sc[j];
    }
    s = 0;
    for(int k = 1; k <= nrd; k++){
        if(1 < vl[k].a){
            s += vl[k].a-1;
        }else if(vl[k].b < 1){
            s += 1-vl[k].b;
        }
    }
    vi[1] = s;
    for(int i = 2; i <= n; i++){
        vi[i] = vi[i-1]+sl[i-1]-dl[i+1];
    }
    s = 0;
    for(int k = 1; k <= nrd; k++){
        if(1 < vc[k].a){
            s += vc[k].a-1;
        }else if(vc[k].b < 1){
            s += 1-vc[k].b;
        }
    }
    vj[1] = s;
    for(int j = 2; j <= m; j++){
        vj[j] = vj[j-1]+sc[j-1]-dc[j+1];
    }
    int dtmin = 2e9, dtmini=0, dtminj=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == false){
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
