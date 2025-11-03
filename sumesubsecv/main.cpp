#include <fstream>
#include <cmath>
using namespace std;
#define MOD 1000000007
ifstream fin("sumesubsecv.in");
ofstream fout("sumesubsecv.out");
int n;
int v[100004];
int f[100004];
int main(){
    fin >> n;
    long long s = 0;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        long long s1 = v[i];
        int j;
        for(j = i+1; j <= n; j++){
            if(abs(v[j]-v[j-1]) != 1){
                break;
            }
        }
        if(j > i+1){
            int nr = j-i;
            int i1 = 0;
            for(int j1 = i; j1 <= j-1; j1++){
                i1++;
                s +=  1LL*v[j1]*i1*(nr-i1+1);
                s = s % MOD;
            }
            i=j-1;
        }else{
            s += v[i];
            s = s % MOD;
        }
    }
    s = s % MOD;
    fout << s;
    return 0;
}
