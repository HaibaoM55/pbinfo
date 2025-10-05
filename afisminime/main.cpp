#include <fstream>
#include <math.h>
using namespace std;
ifstream fin("afisminime.in");
ofstream fout("afisminime.out");
int n, m, x, y;
int v[100004];
int minm[320];
int main(){
    fin >> n >> m;
    int sq = sqrt(n);
    for(int i = 0; i <= 319; i++){
        minm[i] = 2e9;
    }
    for(int i = 1; i <= n; i++){
        fin >> v[i];
        minm[i/sq] = min(minm[i/sq], v[i]);
    }
    for(int sixseven = 1; sixseven <= m; sixseven++){
        fin >> x >> y;
        int minim = 2e9;
        int i = x;
        while(true){
            minim = min(minim, v[i]);
            i++;
            if(i % sq == 0){
                break;
            }
        }
        i = y;
        while(true){
            minim = min(minim, v[i]);
            i--;
            if(i % sq == 0){
                break;
            }
        }
        int c=y/sq-1;
        for(i = x/sq+1; i <= c; i++){
            minim = min(minm[i], minim);
        }
        fout << minim << '\n';
    }
    return 0;
}
