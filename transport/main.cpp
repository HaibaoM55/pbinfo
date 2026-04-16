#include <fstream>
#include <map>
#include <vector>
using namespace std;
#define MOD 1000000007
#define int long long
ifstream fin("transport.in");
ofstream fout("transport.out");
int t;
int n, c;
struct statie{
    int x, d;
}v[200004];
int put[200004];
map<int, vector<int>> f;
map<int, vector<int>> s;
int invers(int x){
    long long rasp = 1;
    int e = MOD - 2;
    while(e){
        if(e & 1){
          rasp = rasp * x % MOD;
        }
        x = (1LL*x*x)% MOD;
        e >>= 1;
    }
    return rasp;
}
int inv_put[200004];
signed main(){
    fin >> t;
    fin >> n >> c;
    put[0] = 1;
    for(int i = 1; i <= n; i++){
        put[i] = put[i-1]*2LL;
        put[i] = put[i]%MOD;
    }
    for(int i = 0; i <= n; i++){
        inv_put[i] = invers(put[i]);
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i].x >> v[i].d;
        int ec = c*v[i].x-v[i].d;
        //fout << ec << ' ' << ec+2*v[i].d
        f[ec].push_back(i);
        s[ec].push_back(put[i]);
        int l= s[ec].size();
        if(l < 2){
            continue;
        }
        s[ec][l-1] = s[ec][l-2]+s[ec][l-1];
        s[ec][l-1] = s[ec][l-1]%MOD;
    }
    if(t == 1){
        int nr = 0;
        for(int i = 1; i <= n; i++){
            nr += f[c*v[i].x+v[i].d].size();
            nr = nr % MOD;
        }
        fout << nr;
    }else{
        //c*(v[i].x-v[j].x)=v[i].d+v[j].d
        //c*v[i].x-v[i].d=v[j].d+c*v[j].x
        int rasp = 0;
        for(int i = 1; i <= n; i++){
            int vl = c*v[i].x+v[i].d;
            int l =  f[vl].size();
            int p1 = 0, p2 =l-1;
            int p = -1;
            while(p1 <= p2){
                int mij = (p1+p2)/2LL;
                if(f[vl][mij] > i){
                    p = mij;
                    p2 = mij-1;
                }else{
                    p1 = mij+1;
                }
            }
            if(p != -1){
                if(p != 0){
                    rasp += 1LL*(s[vl][l-1]-s[vl][p-1])*inv_put[i+1];
                }else{
                    rasp += 1LL*(s[vl][l-1])*inv_put[i+1];
                }
                rasp = rasp % MOD;
            }
        }
        fout << rasp;
    }
    return 0;
}
