#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
ifstream fin("pluton.in");
ofstream fout("pluton.out");
int n, x;
int v[16];
int nrg = 0;
typedef int arr[4004];
int vmax = 0, vmaxnr=0, vmaxi;
unordered_map<int, arr> f;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int x1 = x;
        int z = 0;
        do{
            z++;
            v[z] = x1%10;
            x1 = x1/10;
        }while(x1 > 0);
        sort(v+1, v+z+1);
        int nr = 0;
        for(int i = 1; i <= z; i++){
            if(v[i] != 0){
                nr = nr*10+v[i];
            }
        }
        for(int i = 1; i <= z; i++){
            if(v[i] == 0){
                nr = nr*10+v[i];
            }
        }
        f[nr][0]++;
        if(f[nr][0] == 1){
            nrg++;
        }
        f[nr][f[nr][0]] = x;
        if(f[nr][0] > vmax){
            vmax = f[nr][0];
            vmaxnr = 0;
            vmaxi = nr;
        }
        if(f[nr][0] == vmax){
            vmaxnr++;
        }
    }
    fout << nrg << '\n';
    fout << vmax << '\n';
    fout << vmaxnr << '\n';
    for(int i = 1; i <= f[vmaxi][0]; i++){
        fout << f[vmaxi][i] << ' ';
    }
    return 0;
}
