#include <fstream>
#include <algorithm>
using namespace std;
#define MOD 1000003
ifstream fin("zaruri.in");
ofstream fout("zaruri.out");
int q;
struct query{
    int n, st, dr, rasp=0, i;
}a[100004];
int dp[100004];
int sp[100004];
bool compara(query x, query y){
    return x.n < y.n;
}
bool comparadupai(query x, query y){
    return x.i < y.i;
}
int suma(int k, int vmax){
    if(k > vmax){
        return sp[vmax];
    }else{
        return sp[k];
    }
}
int main(){
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> a[i].n >> a[i].st >> a[i].dr;
        a[i].i = i;
    }
    sort(a+1, a+q+1, compara);
    int nmax = a[q].n;
    dp[0] = 1;
    int jq = 1;
    for(int i = 1; i <= nmax; i++){
        int aux[18004] = {};
        for(int s = 0; s <= 6*(i-1); s++){
            for(int zar = 1; zar <= 6; zar++){
                aux[s+zar] += dp[s];
                aux[s+zar] %= MOD;
            }
        }
        sp[0] = 0;
        for(int s = 0; s <= 6 * i; s++){
            dp[s] = aux[s];
            if(s >= 1){
                sp[s] = sp[s-1]+aux[s];
                sp[s] = sp[s]%MOD;
            }
        }
        while(a[jq].n == i){
            long long rasp = (1LL*suma(a[jq].dr, 6*i)-1LL*suma(a[jq].st-1, 6*i)+MOD);
            a[jq].rasp = rasp%MOD;
            jq++;
        }
    }
    sort(a+1, a+q+1, comparadupai);
    for(int i = 1; i <= q; i++){
        fout << a[i].rasp << '\n';
    }
	return 0;
}
