/*PART 1:
#include <fstream>
#include <string.h>
using namespace std;
#define LIMIT 496
ifstream fin("a.in");
ofstream fout("a.out");
struct redtile{
    int x, y;
}v[500];
char x[50];
long long modul(long long r){
    if(r < 0){
        return -r;
    }
    return r;
}
int main(){
    for(int i = 1; i <= LIMIT; i++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int nrz = 0;
        v[i].x = 0;
        v[i].y = 0;
        for(int j = 0; j < l; j++){
            if(x[j] == ','){
                nrz++;
                continue;
            }
            if(nrz == 0){
                v[i].x = v[i].x*10+x[j]-'0';
            }else{
                v[i].y = v[i].y*10+x[j]-'0';
            }
        }
    }
    long long vmax = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = i+1; j <= LIMIT; j++){
            vmax = max(vmax, (modul(v[i].x-v[j].x)+1LL)*(modul(v[i].y-v[j].y)+1LL));
        }
    }
    fout << vmax;
    return 0;
}
*/
//PART 2:
#include <fstream>
#include <string.h>
using namespace std;
#define LIMIT 496
ifstream fin("a.in");
ofstream fout("a.out");
struct redtile{
    int x, y;
}v[500];
char x[50];
long long modul(long long r){
    if(r < 0){
        return -r;
    }
    return r;
}
char a[100004][100004];
long long s[100004][100004];
bool mergen(int is, int js, int ij, int jj){
    long long sum = s[ij][jj]-s[is-1][jj]-s[ij][js-1]+s[is-1][js-1];
    if(sum == 1LL*(ij-is+1)*(jj-js+1)){
        return true;
    }else{
        return false;
    }
}
int main(){
    for(int i = 1; i <= LIMIT; i++){
        fin.get(x, 50);
        fin.get();
        int l = strlen(x);
        int nrz = 0;
        v[i].x = 0;
        v[i].y = 0;
        for(int j = 0; j < l; j++){
            if(x[j] == ','){
                nrz++;
                continue;
            }
            if(nrz == 0){
                v[i].x = v[i].x*10+x[j]-'0';
            }else{
                v[i].y = v[i].y*10+x[j]-'0';
            }
        }
        swap(v[i].x, v[i].y);
        a[v[i].x][v[i].y] = '#';
        if(i > 1){
            if(v[i].x == v[i-1].x){
                int minim = min(v[i-1].y, v[i].y);
                int maxim = max(v[i-1].y, v[i].y);
                for(int j = minim+1; j <= maxim-1; j++){
                    a[v[i].x][j] = 'X';
                }
            }else{
                int minim = min(v[i-1].x, v[i].x);
                int maxim = max(v[i-1].x, v[i].x);
                for(int j = minim+1; j <= maxim-1; j++){
                    a[j][v[i].y] = 'X';
                }
            }
        }
    }
    if(v[1].y == v[LIMIT].y){
        int minim = min(v[1].x, v[LIMIT].x);
        int maxim = max(v[1].x, v[LIMIT].x);
        for(int j = minim+1; j <= maxim-1; j++){
            a[j][v[1].y] = 'X';
        }
    }
    for(int i = 1; i <= 100000; i++){
        for(int j = 1; j <= 100000; j++){
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(a[i][j] == 'X'){
                s[i][j]++;
            }
        }
    }
    long long vmax = 0;
    for(int i = 1; i <= LIMIT; i++){
        for(int j = i+1; j <= LIMIT; j++){
            int minimi=min(v[i].x, v[j].x);
            int maximi=max(v[i].x, v[j].x);
            int minimj=min(v[i].y, v[j].y);
            int maximj=max(v[i].y, v[j].y);
            long long arie = (modul(v[i].x-v[j].x)+1LL)*(modul(v[i].y-v[j].y)+1LL);
            if(arie > vmax){
                if(mergen(minimi,minimj,maximi,maximj)){
                    vmax = arie;
                }
            }
        }
    }
    fout << vmax;
    return 0;
}
