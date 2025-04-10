#include <fstream>
#include <algorithm>
using namespace std;
#pragma GCC optimize("O3")
ifstream fin("ecuatie3.in");
ofstream fout("ecuatie3.out");
int n;
long long t;
long long x[12];
long long v[2000004];
int z =0;
int nrmoduri=0;
void kp(int k, long long t){
    if(k == n){
        x[n] = t;
        nrmoduri++;
    }else{
        for(int i = 1; v[i] <= t; i++){
            if(t % v[i] == 0){
                x[k] = v[i];
                kp(k+1, t/v[i]);
            }
        }
    }
}
int main(){
    fin >> n >> t;
    for(long long i = 1; i*i <= t; i++){
        if(t % i == 0){
            z++;
            v[z] = i;
            if(i*i < t){
                z++;
                v[z] = t/i;
            }
        }
    }
    sort(v+1, v+z+1);
    v[z+1] = t+1;
    kp(1, t);
    fout << nrmoduri;
    return 0;
}
