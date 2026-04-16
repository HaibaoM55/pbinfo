#include <fstream>
using namespace std;
#define MOD 1000000009
#define int long long
ifstream fin("matrice.in");
ofstream fout("matrice.out");
int n, m, t;
//int rasp(int i, int j, int curi, int curj){
//    if(curj == m+1){
//        curi++;
//        curj = 1;
//    }
//    if(curi == n+1){
//        //verificam a
//        for(int z = 0; z <= j)
//    }
//    long long ans = 0;
//    for(int z = 0; z <= t; z++){
//        a[curi][curj] = z;
//        ans += rasp(i, j, curi, curj+1);
//    }
//}
signed main(){
    fin >> n >> m >> t;
    if(n == 1 || m == 1){
        int vmax=max(n, m);
        int nr = 0;
        int oldr = 0;
        if(n == m){
            fout << t+1;
            return 0;
        }
        for(int a1 = t; a1 >= 0; a1--){
            for(int r = oldr+1; r <= t; r++){
                if(a1+(vmax-1)*r <= t){
                    oldr = r;
                }else{
                    break;
                }
            }
            nr += oldr;
            nr = nr % MOD;
        }
        fout << nr;
    }else{
        int rasp = 0;
        for(int j = 1; j <= t/(m-1); j++){
            int nr  = (t-j*(m-1))/(n-1);
            int val = (j-1)/(n-1);
            int sum = (t+1)*nr%MOD;
            sum = (sum-j*(m-1)%MOD*nr%MOD+MOD)% MOD;
            sum = (sum-(n-1)*nr%MOD*((nr+1)/2)%MOD+MOD)%MOD;
            sum = sum*(val+1)%MOD;
            rasp=(rasp+sum)%MOD;
        }
        fout << rasp;
    }
    return 0;
}
