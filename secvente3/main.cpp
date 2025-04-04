#include <fstream>
using namespace std;
#pragma GCC optimize("O1")
ifstream fin("secvente.in");
ofstream fout("secvente.out");
int n, x;
bool f[1000004];
int fata[1000004], spate[1000004];
int nr =0;
int main(){
    fin >> n;
    int vmax = 0;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x] = true;
        spate[x] = 0;
        fata[x] = 0;
        if(f[x-1]){
            spate[x] = spate[x-1]+1;
        }
        if(f[x+1]){
            fata[x] = fata[x+1]+1;
        }
        if(spate[x] > 0){
            fata[x-spate[x]] += fata[x]+1;
        }
        if(fata[x] > 0){
            spate[x+fata[x]] += spate[x]+1;
        }
        vmax = max(vmax, spate[x]+fata[x]+1);
        fout << vmax << '\n';
    }
    /*for(int i = 1; i <= 20; i++){
        fout << i << ": " <<spate[i] << ' ' << fata[i] << '\n';
    }*/
    return 0;
}
