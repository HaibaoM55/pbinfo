#include <fstream>
using namespace std;
ifstream fin("loto.in");
ofstream fout("loto.out");
int p;
int m, k, c;
int cst[50];
int a[50];
bool b[55];
int f[10];
int juc;
bool b1[50];
int vmax = 0;
int fz[50];
int main()
{
    fin >> p;
    fin >> m >> k >> c;
    for(int i = 1; i <= m; i++){
        fin >> cst[i];
        b[cst[i]] = true;
    }
    fin >> juc;
    for(int i = 1; i <= juc; i++){
        if(p == 1){
            for(int j = 1; j <= 49; j++){
                b1[j] = false;
            }
            for(int j =1; j <= k; j++){
                fin >> a[j];
                b1[a[j]] = true;
            }
            bool c1 = true;
            for(int j = 1; j <= k; j++){
                bool ok = false;
                for(int j2 = 1; j2 <= k; j2++){
                    if(cst[j2] == a[j]){
                        ok = true;
                        break;
                    }
                }
                if(ok == false){
                    c1 = false;
                    break;
                }
            }
            if(c1){
                f[1]++;
                continue;
            }
            bool c2 = true;
            for(int j = 1; j <= k; j++){
                if(b[a[j]] == false){
                    c2 = false;
                }
            }
            if(c2){
                f[2]++;
                continue;
            }
            bool c3 = true;
            for(int j = 1; j <= k-1; j++){
                if(b1[cst[j]] == false){
                    c3 = false;
                    break;
                }
            }
            if(c3){
                f[3]++;
                continue;
            }
            int c4 = 2;
            for(int j = 1; j <= k; j++){
                if(b1[cst[j]] == false){
                    c4--;
                    if(c4 == 0){
                        break;
                    }
                }
            }
            if(c4 > 0){
                f[4]++;
                continue;
            }
            int c5 = 2;
            for(int j = 1; j <= k; j++){
                if(b[a[j]] == false){
                    c5--;
                    if(c5 == 0){
                        break;
                    }
                }
            }
            if(c5){
                f[5]++;
                continue;
            }
            int c6 = 3;
            for(int j = 1; j <= k; j++){
                if(b[a[j]] == false){
                    c6--;
                    if(c6 == 0){
                        break;
                    }
                }
            }
            if(c6){
                f[6]++;
                continue;
            }
            f[7]++;
        }else{
            int x;
            for(int j = 1; j <= k; j++){
                fin >> x;
                fz[x]++;
                if(fz[x] > vmax){
                    vmax = fz[x];
                }
            }
        }
    }
    if(p == 1){
        fout << f[c];
    }else{
        for(int i = 1; i <= 49; i++){
            if(fz[i] == vmax){
                fout << i << ' ';
            }
        }
    }
    return 0;
}
