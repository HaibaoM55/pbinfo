/*PART 1:
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
#define LIMIT 1000
struct coords{
    int x, y, z;
    int echipa;
}v[1004];
long long f[1004][1004];
int r[1004];
bool b[1004][1004];
struct conexiune{
    int i, j;
    long long val;
}c[1005];
char x[50];
int vx[1004];
int main(){
    for(int zz1 = 1; zz1 <= LIMIT; zz1++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int z = 1;
        for(int i = 0; i < l; i++){
            if(x[i] == ','){
                z++;
            }else if('0' <= x[i] && x[i] <= '9'){
                if(z == 1){
                    v[zz1].x = v[zz1].x*10+x[i]-'0';
                }else if(z == 2){
                    v[zz1].y = v[zz1].y*10+x[i]-'0';
                }else{
                    v[zz1].z = v[zz1].z*10+x[i]-'0';
                }
            }
        }
    }
    long long vmax = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = 1; j <= LIMIT; j++){
            f[i][j] = 1LL*(v[i].x-v[j].x)*(v[i].x-v[j].x);
            f[i][j]+= 1LL*(v[i].y-v[j].y)*(v[i].y-v[j].y);
            f[i][j]+= 1LL*(v[i].z-v[j].z)*(v[i].z-v[j].z);
            vmax = max(f[i][j], vmax);
        }
    }
    for(int nr = 1; nr <= 1000; nr++){
        long long vmin = vmax+1;
        int vmini=-1, vminj=-1;
        for(int i = 1; i < LIMIT; i++){
            for(int j = i+1; j <= LIMIT; j++){
                if(!b[i][j]){
                    if(f[i][j] < vmin){
                        vmin = f[i][j];
                        vmini = i;
                        vminj = j;
                    }
                }
            }
        }
        b[vmini][vminj] = true;
        c[nr].i = vmini;
        c[nr].j = vminj;
        c[nr].val = vmin;
    }
    int nr1 = 0;
    for(int i = 1; i <= 1000; i++){
        if(r[c[i].i] == 0 && r[c[i].j] == 0){
            nr1++;
            r[c[i].i] = nr1;
            r[c[i].j] = nr1;
        }else if(r[c[i].i] == 0 && r[c[i].j] != 0){
            r[c[i].i] = r[c[i].j];
        }else if(r[c[i].i] != 0 && r[c[i].j] == 0){
            r[c[i].j] = r[c[i].i];
        }else{
            for(int j = 1; j <= 1000; j++){
                if(r[c[j].i] == r[c[i].i]){
                    r[c[j].i] = r[c[i].j];
                    r[c[j].j] = r[c[i].j];
                }else if(r[c[j].j] == r[c[i].i]){
                    r[c[j].i] = r[c[i].j];
                    r[c[j].j] = r[c[i].j];
                }
            }
        }
    }
    for(int i = 1; i <= LIMIT; i++){
        vx[r[i]]++;
    }
    sort(vx+1, vx+1001);
    long long rasp = 1;
    for(int i = 998; i <= 1000; i++){
        rasp = rasp*vx[i];
        fout << vx[i] << ' ';
    }
    fout << rasp;
    return 0;
}
*/
//PART 2:
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
#define LIMIT 1000
struct coords{
    int x, y, z;
    int echipa;
}v[1004];
long long f[1004][1004];
int r[1004];
bool b[1004][1004];
struct conexiune{
    int i, j;
    long long val;
}c[1000004];
char x[50];
int vx[1000004];
bool compara(conexiune a, conexiune b){
    return a.val < b.val;
}
int main(){
    for(int zz1 = 1; zz1 <= LIMIT; zz1++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int z = 1;
        for(int i = 0; i < l; i++){
            if(x[i] == ','){
                z++;
            }else if('0' <= x[i] && x[i] <= '9'){
                if(z == 1){
                    v[zz1].x = v[zz1].x*10+x[i]-'0';
                }else if(z == 2){
                    v[zz1].y = v[zz1].y*10+x[i]-'0';
                }else{
                    v[zz1].z = v[zz1].z*10+x[i]-'0';
                }
            }
        }
    }
    int nr = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = i+1; j <= LIMIT; j++){
            f[i][j] = 1LL*(v[i].x-v[j].x)*(v[i].x-v[j].x);
            f[i][j]+= 1LL*(v[i].y-v[j].y)*(v[i].y-v[j].y);
            f[i][j]+= 1LL*(v[i].z-v[j].z)*(v[i].z-v[j].z);
            nr++;
            c[nr].i = i;
            c[nr].j = j;
            c[nr].val = f[i][j];
        }
    }
    sort(c+1, c+nr+1, compara);
    int nr1 = 0;
    for(int i = 1; i <= nr; i++){
        if(r[c[i].i] == 0 && r[c[i].j] == 0){
            nr1++;
            r[c[i].i] = nr1;
            r[c[i].j] = nr1;
        }else if(r[c[i].i] == 0 && r[c[i].j] != 0){
            r[c[i].i] = r[c[i].j];
        }else if(r[c[i].i] != 0 && r[c[i].j] == 0){
            r[c[i].j] = r[c[i].i];
        }else{
            for(int j = 1; j <= LIMIT; j++){
                if(j == c[i].i){
                    continue;
                }
                if(r[j] == r[c[i].i]){
                    r[j] = r[c[i].j];
                }
            }
            r[c[i].i] = r[c[i].j];
        }
        r[0] = r[1];
        bool ok = true;
        for(int j = 1; j <= LIMIT; j++){
            if(r[j] != r[j-1]){
                ok = false;
                break;
            }
        }
        if(ok){
            fout << v[c[i].i].x << '*' << v[c[i].j].x << '=';
            fout << 1LL*v[c[i].i].x*v[c[i].j].x;
            return 0;
        }
    }
    return 0;
}
