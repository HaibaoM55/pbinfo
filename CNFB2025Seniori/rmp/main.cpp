#include <fstream>
using namespace std;
ifstream fin("rmp.in");
ofstream fout("rmp.out");
int n, p;
int v[1000004];
int f[1000004];
int v1[1000004];
int vmax = 0;
void bt(int i, int z, int x[1000004]){
    vmax = max(vmax, z);
    if(i == n+1){
        return;
    }
    bt(i+1, z, x);
    z++;
    x[z] = v[i];
    bool verif = true;
    for(int j = 1; j < z; j++){
        if((x[j]+x[z]) % p == 0){
            verif = false;
        }
    }
    if(verif){
        bt(i+1, z, x);
    }
}
int main(){
    fin >> n >> p;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        f[v[i]%p]++;
    }
    if(n <= 20){
        bt(1, 0, v1);
        fout << vmax;
        return 0;
    }
    int z = 0;
    if(f[0]){
        z = 1;
    }
    if(p % 2 == 0){
        if(f[p/2]){
            z++;
        }
    }
    int opus = p-1;
    for(int i = 1; i < opus; i++){
        if(f[opus] > f[i]){
            z += f[opus];
        }else{
            z += f[i];
        }
        opus--;
    }
    fout << z;
    return 0;
}
