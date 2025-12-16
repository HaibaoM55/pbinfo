#include <fstream>
using namespace std;
#define MOD 1000000007
ifstream fin("nrdivprod.in");
ofstream fout("nrdivprod.out");
int n, x;
int f[1000004];
int spf[1000004];
int main(){
    for(int i = 2; i <= 1000000; i += 2) spf[i] = 2;
    for(int i = 3; i*i <= 1000000; i += 2){
        if(!spf[i]){
            for(int j = i*i; j <= 1000000; j += i+i){
                if(!spf[j]) spf[j] = i;
            }
        }
    }
    for(int i = 3; i <= 1000000; i += 2){
        if(!spf[i]) spf[i] = i;
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(x % 2 == 0){
            do{
                f[2]++;
                x >>= 1;
            }while(!(x & 1));
        }
        while(x > 1){
            int p = spf[x];
            do{
                f[p]++;
                x /= p;
            }while(x % p == 0);
        }
    }
    long long rasp = (f[2] + 1);
    for(int i = 3; i <= 1000000; i += 2){
        if(f[i]){
            rasp = rasp * (f[i] + 1LL) % MOD;
        }
    }
    fout << rasp;
    return 0;
}
