#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("farma.in");
ofstream fout("farma.out");
int c;
int n, a[12][12], m;
int nr[12];
char x[706];
struct medicament{
    char den[35] = "";
    int pret = 0;
    int p = 0;
    int z[35];
}v[103];
int b1[102][102];
int vp[13];
int max_p = 0;
int smin = 2147483645;
void mp(int k, int s){
    if(k == n+1){
        if(s < smin){
            smin = s;
        }
    }else{
        for(int i = 1; i <= nr[k]; i++){
            vp[k] = i;
            bool ok = true;
            for(int j = k-1; j >= 1 && ok; j--){
                if(b1[a[k][vp[k]]][a[j][vp[j]]] == 1){
                    ok = false;
                }
            }
            if(s+v[a[k][i]].pret >= smin){
                ok = false;
            }
            if(ok){
                mp(k+1, s+v[a[k][i]].pret);
            }
        }
    }
}
int main()
{
    fin >> c;
    fin >> n;
    fin.get();
    if(c == 1){
        for(int i = 1; i <= n; i++){
            fin.get(x, 706);
            fin.get();
            int l = strlen(x);
            int p = 1;
            for(int j = 0; j <= l-1; j++){
                if(x[j] == ','){
                    p++;
                }
            }
            fout << p << '\n';
        }
    }else{
        int z = 1;
        for(int i = 1; i <= n; i++){
            fin.get(x, 706);
            fin.get();
            int l = strlen(x);
            bool ok = false;
            int l1 = 0;
            for(int j = 0; j <= l; j++){
                if(ok){
                    if('0' <= x[j] && x[j] <= '9'){
                        v[z].pret = v[z].pret*10+x[j]-'0';
                    }else if(x[j] == ',' || x[j] == 0){
                        v[z].den[l1] = 0;
                        nr[i]++;
                        a[i][nr[i]] = z;
                        z++;
                        l1 = 0;
                    }else{
                        if('a' <= x[j] && x[j] <= 'z'){
                            v[z].den[l1] = x[j];
                            l1++;
                        }
                    }
                }else{
                    if(x[j] == ':'){
                        ok = true;
                    }
                }
            }
        }
        z--;
        fin >> m;
        fin.get();
        for(int i = 1; i <= m; i++){
            fin.get(x, 706);
            fin.get();
            char a[35];
            char b[35];
            bool ok1 = true;
            int l = strlen(x);
            int pz = 0;
            for(int j = 0; j <= l-1; j++){
                if(x[j] == '/'){
                    a[j] = 0;
                    ok1 = false;
                }else{
                    if(ok1){
                        a[j] = x[j];
                    }else{
                        b[pz] = x[j];
                        pz++;
                    }
                }
            }
            b[pz] = 0;
            int poza = 0;
            int pozb = 0;
            for(int j = 1; j <= z; j++){
                if(strcmp(a, v[j].den) == 0){
                    poza = j;
                }
                if(strcmp(b, v[j].den) == 0){
                    pozb = j;
                }
                if(poza != 0 && pozb != 0){
                    break;
                }
            }
            b1[poza][pozb] = 1;
            b1[pozb][poza] = 1;
        }
        mp(1, 0);
        fout << smin;
    }
    return 0;
}
