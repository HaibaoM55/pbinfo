#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("gene.in");
ofstream fout("gene.out");
int c;
int n, m, k;
char x[30];
int f[30];
int fx[30];
bool b[505][505];
int sp[505][505];
int z = 0;
struct om{
    int i, j;
    char p[30];
} pm[250003];
int main()
{
    fin >> c;
    fin >> n >> m >> k;
    fin >> x;
    int vmax = 0;
    int l1 = strlen(x);
    for(int i = 0; i <= l1-1; i++){
        fx[x[i]-'a'+1]++;
    }
    if(c == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char p[30];
                int grade = 0;
                fin >> p;
                int l = strlen(p);
                for(int o = 1; o <= 30; o++){
                    f[o] = 0;
                }
                for(int o = 0; o <= l-1; o++){
                    f[p[o]-'a'+1]++;
                }
                for(int o = 1; o <= 26; o++){
                    grade = grade+min(f[o], fx[o]);
                }
                if(grade > vmax){
                    vmax = grade;
                    z = 0;
                }
                if(grade == vmax){
                    z++;
                    pm[z].i = i;
                    pm[z].j = j;
                    strcpy(pm[z].p, p);
                }
            }
        }
        for(int i = 1; i <= z; i++){
            fout << pm[i].i << " " << pm[i].j << " " << pm[i].p << "\n";
        }
    }else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                char p[30];
                int grade = 0;
                fin >> p;
                int l = strlen(p);
                for(int o = 1; o <= 30; o++){
                    f[o] = 0;
                }
                for(int o = 0; o <= l-1; o++){
                    f[p[o]-'a'+1]++;
                }
                for(int o = 1; o <= 26; o++){
                    grade = grade+min(f[o], fx[o]);
                }
                if(grade > k){
                    b[i][j] = true;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sp[i][j] = sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1]+b[i][j];
            }
        }
        int pav = min(n, m);
        int vmax = 0;
        int vmaxi, vmaxj;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int lg = 1; lg <= pav; lg++){
                    int pat = sp[i+lg-1][j+lg-1]-sp[i-1][j+lg-1]-sp[i+lg-1][j-1]+sp[i-1][j-1];
                    if(pat == lg*lg){
                        if(lg > vmax){
                            vmax = lg;
                            vmaxi = i;
                            vmaxj = j;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        fout << vmaxi << " " << vmaxj << " " << vmax;
    }
    return 0;
}
