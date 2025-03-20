#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
ifstream fin("natatie.in");
ofstream fout("natatie.out");
int n, m;
struct rata{
    int v, r;
}a[3004];
int d[3004];
double s[3004][3004];
bool compara_dupa_viteza(rata a, rata b){
    return a.v < b.v;
}
bool compara_normal(rata a, rata b){
    if(a.r < b.r){
        return true;
    }else if(a.r == b.r){
        return a.v < b.v;
    }
    return false;
}
int main()
{
    fin >> n >> m;
    bool acvit = true;
    for(int i = 1; i <= n; i++){
        fin >> a[i].v;
        if(i > 1 && a[i].v != a[i-1].v){
            acvit = false;
        }
    }
    bool acrez = true;
    for(int i = 1; i <= n; i++){
        fin >> a[i].r;
        if(i > 1 && a[i].r != a[i-1].r){
            acrez = false;
        }
    }
    for(int i = 1; i <= m; i++){
        fin >> d[i];
    }
    if(acvit){
        float rasp = d[m]*2.0;
        rasp = rasp/a[1].v;
        fout << fixed << setprecision(9) <<rasp;
    }else if(acrez){
        sort(a+1, a+n+1, compara_dupa_viteza);
        int z = 1;
        double vmax = 0;
        for(int i = n-m+1; i <= n; i++){
            double r = d[z]*2.0;
            r = r/(double)a[i].v;
            vmax= max(vmax, r);
            z++;
        }
        fout << fixed << setprecision(9) <<vmax;
    }else if(n-m == 1){
        sort(a+1, a+n+1, compara_normal);
        float vmin = 2e9;
        for(int i = 1; i <= n; i++){
            int z = 1;
            float vmax = 0;
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                float r = d[z]*2.0;
                r = r/a[j].v;
                vmax = max(vmax, r);
                z++;
            }
            vmin = min(vmin, vmax);
        }
        fout << vmin;
    }else{
        sort(a+1, a+n+1, compara_normal);
        for(int i = 1; i <= n; i++){
            s[0][i] = 2e9;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                double r = d[j]*2;
                r = r / a[i].v;
                s[i][j] = min(max(r, s[i-1][j-1]), s[i-1][j]);
            }
        }
        fout << fixed << setprecision(9) <<s[n][m];
    }
    return 0;
}
