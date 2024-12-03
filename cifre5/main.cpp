#include <fstream>
using namespace std;
ifstream fin("cifre5.in");
ofstream fout("cifre5.out");
int n, k, x;
int f[14];
int v[100004];
int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x]++;
    }
    int cif = n/k+1;
    int nk = n%k;
    int nr = 0;
    if(nk > 0){
        for(int i = 1; i <= 9 && nk > 0; i++){
            while(f[i] > 0 && nk > 0){
                f[i]--;
                nk--;
                v[cif] = v[cif]+i;
            }
        }
        cif--;
    }else{
        cif--;
        for(int i = 1; i <= 9; i++){
            if(f[i] > 0){
                f[i]--;
                v[cif] = i;
                break;
            }
        }
        nr = 1;
        if(k == 1){
            cif--;
            nr = 0;
        }
    }
    if(n%k != 0 && f[0] > 10000 && f[1] > 2){
        v[cif] = 2;
        nr++;
        nr++;
        f[1] -= 2;
    }
    for(int j = 1; j <= f[0]; j++){
        nr++;
        if(nr % k == 0){
            cif--;
        }
    }
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= f[i]; j++){
            nr++;
            v[cif] = v[cif]+i;
            if(nr % k == 0){
                cif--;
            }
        }
    }
    v[0] = n/k;
    if(n%k != 0){
        v[0]++;
    }
    for(int i = 1; i <= v[0]; i++){
        v[i+1] = v[i+1]+(v[i]/10);
        v[i] = v[i]%10;
        if(i == v[0] && v[i+1] > 0){
            v[0]++;
        }
    }
    for(int i = v[0]; i >= 1; i--){
        fout << v[i];
    }
    return 0;
}
