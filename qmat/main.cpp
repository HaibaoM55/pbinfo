#include <fstream>
using namespace std;
ifstream fin("qmat.in");
ofstream fout("qmat.out");
struct mat{
    int l, c;
    short v[11];
}s1[10002], s2[10002];
int n;
int q;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> s1[i].l >> s1[i].c;
        for(int k = 1; k <= s1[i].l; k++){
            int x = 0;
            int a;
            for(int j = 1; j <= s1[i].c; j++){
                fin >> a;
                x = x*2+a;
            }
            s1[i].v[k] = x;
        }
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> s2[i].l >> s2[i].c;
        for(int k = 1; k <= s2[i].l; k++){
            int x = 0;
            int a;
            for(int j = 1; j <= s2[i].c; j++){
                fin >> a;
                x = x*2+a;
            }
            s2[i].v[k] = x;
        }
    }
    int nr = 0;
    for(int i = 1; i <= q; i++){
        for(int j = 1; j <= n; j++){
            if(s2[i].l == s1[j].l && s2[i].c == s1[j].c){
                bool ok = true;
                for(int k = 1; k <= s2[i].l; k++){
                    if(s2[i].v[k] != s1[j].v[k]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    nr++;
                }
            }
        }
    }
    fout << nr;
    return 0;
}
