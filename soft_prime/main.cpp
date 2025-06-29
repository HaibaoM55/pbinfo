#include <fstream>
#include <algorithm>
#include <bitset>
#pragma GCC optimize("O1")
using namespace std;
ifstream fin("soft_prime.in");
ofstream fout("soft_prime.out");
ofstream fout1("dih.out");
int n, x;
bool ciur[1004];
int prm[304];
int nrp = 0, nr=0;
int pvl = 0;
int v[10004];
bitset<40004> f;
bool esteprim(int x){
    for(int i = 1; i <= nrp && x > prm[i]; i++){
        if(x % prm[i] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    for(int i = 2; i <= 1000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j <= 1000/i; j++){
                ciur[j*i] = true;
            }
        }
    }
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(esteprim(x)){
            f[i] = true;
        }else{
            f[i] = false;
        }
    }
    for(int i = 100000; i <= 1000000; i += 100000){
        int p = i-100000;
        nr = 0;
        ifstream fin("soft_prime.in");
        fin >> n;
        for(int j = 1; j <= n; j++){
            fin >> x;
            if(f[j]){
                if(p <= x && x <= i){
                    nr++;
                    v[nr] = x;
                }
            }
        }
        sort(v+1, v+nr+1);
        for(int j = 1; j <= nr; j++){
            fout << v[j] << ' ' ;
        }
    }
    return 0;
}
