#include <fstream>
using namespace std;
ifstream fin("sah1.in");
ofstream fout("sah1.out");
int p;
int n, m, x, m1;
struct tura{
    int l, c;
}v[2004];
bool fl[10004];
bool fc[10004];
int main()
{
    fin >> p;
    fin >> x >> m;
    fin >> n >> m1;
    for(int i =1; i <= m; i++){
        fin >> v[i].l >> v[i].c;
        fl[v[i].l] = true;
        fc[v[i].c] = true;
    }
    if(p == 1){
        int nr = 0;
        bool ok1 = true, ok2=true;
        bool ok3 = true, ok4=true;
        for(int i = 1; i <= n; i++){
            if(v[i].l == n){
                if(v[i].c < m1 && ok1){
                    ok1 = false;
                    nr++;
                }else if(v[i].c > m1 && ok2){
                    ok2 = false;
                    nr++;
                }
            }else if(v[i].c == m1){
                if(v[i].l < n && ok3){
                    ok3 = false;
                    nr++;
                }else if(v[i].l > n && ok4){
                    ok4 = false;
                    nr++;
                }
            }
        }
        fout << nr;
    }else{
        int nr = 0;
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= x; j++){
                if(fl[i] == false && fc[j] == false){
                    nr++;
                }
            }
        }
        fout << nr;
    }
    return 0;
}
