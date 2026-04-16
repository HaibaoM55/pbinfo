#include <fstream>
#include <map>
using namespace std;
ifstream fin("fibopower.in");
ofstream fout("fibopower.out");
int n, k, q;
int v[100004];
int f[304];
int x, y;
map<int, bool> estefibo;
int s[100004];
int main(){
    fin >> n >> k >> q;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    f[2] = 1;
    f[1] = 1;
    int nrfib = 2;
    for(int i = 3; f[i-1] <= 1e9; i++){
        f[i] = f[i-1]+f[i-2];
        nrfib++;
    }
    for(int i = 1; i <= nrfib; i++){
        for(int j = 1; j <= nrfib; j++){
            for(int k = 1; k <= nrfib; k++){
                if(f[i] == f[j] || f[j] == f[k] || f[i] == f[k]){
                    continue;
                }
                long long nr = 1LL*f[i]*f[j];
                if(nr <= 1e9/f[k]){
                    nr = nr*f[k];
                    estefibo[nr] = true;
                }
            }
        }
    }
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        if(estefibo[v[i]]){
            s[i]++;
        }
        s[i] = s[i-1]+s[i];
    }
    for(int z= 1; z <= q; z++){
        fin >> x >> y;
        int nr = 0;
        for(int i = x; i <= y; i++){
            int nrf = 0;
            int p1 = i, p2 = y, pp1=-1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(s[mij]-s[i-1] < k){
                    p1 = mij+1;
                }else{
                    pp1 = mij;
                    p2 = mij-1;
                }
            }
            p1 = i, p2 = y;
            int pp2=-1;
            while(p1 <= p2){
                int mij = (p1+p2)/2;
                if(s[mij]-s[i-1] > k){
                    p2 = mij-1;
                    pp2 = mij;
                }else{
                    p1 = mij+1;
                }
            }
            if(pp1 == -1){
                continue;
            }else if(pp2 == -1){
                nr += y-pp1+1;
            }else{
                nr += pp2-pp1;
            }
        }
        fout << nr << '\n';
    }
    return 0;
}
