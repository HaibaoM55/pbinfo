#include <fstream>
#include <string.h>
#include <map>
#define int unsigned long long
using namespace std;
ifstream fin("subsecvente.in");
ofstream fout("subsecvente.out");
int n;
char s[8][50004];
struct b5 {
    bool b[8];
};
map<int, b5> f;
int h[8][50004];
int p[50004];
bool verifica(int len) {
    f.clear();
    int l = strlen(s[1]);
    for(int i = 0; i + len <= l; i++){
        unsigned long long x = h[1][i+len]-h[1][i]*p[len];
        f[x].b[1] = true;
    }
    for(int i = 2; i <= n; i++){
        l = strlen(s[i]);
        for(int j = 0; j+len <= l; j++){
            unsigned long long x = h[i][j + len]-h[i][j]*p[len];
            auto it = f.find(x);
            if(it != f.end()){
                it->second.b[i] = true;
            }
        }
    }
    for(auto it = f.begin(); it != f.end(); it++){
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(!it->second.b[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            return true;
        }
    }
    return false;
}
signed main() {
    fin >> n;
    p[0] = 1;
    for(int i = 1; i <= 3500; i++){
        p[i] = p[i-1]*31;
    }
    for(int i = 1; i <= n; i++){
        fin >> s[i];
        int l = strlen(s[i]);
        h[i][0] = 0;
        for(int j = 0; j < l; j++){
            h[i][j + 1] = h[i][j] * 31 + s[i][j];
        }
    }
    int st = 1;
    int dr = strlen(s[1]);
    int vmax = 0;
    while(st <= dr){
        int mij = (st+dr)/2;
        if(verifica(mij)){
            vmax = mij;
            st = mij + 1;
        }
        else {
            dr = mij - 1;
        }
    }

    fout << vmax;

    return 0;
}
