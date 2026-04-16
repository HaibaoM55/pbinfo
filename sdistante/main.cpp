#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("sdistante.in");
ofstream fout("sdistante.out");
#define MOD 1000000007
#define int long long
char x[4000004];
int f[6741];
int dist(int a, int b, int c, int d){
    int j = c;
    int nr = 0;
    for(int i = a; i <= b; i++){
        if(x[i] != x[j]){
            nr++;
        }
        j++;
    }
    return nr;
}
signed main(){
    fin.get(x, 4000004);
    int l = strlen(x);
    int bobbyrapperu = 0;
    long long suma = 0, rasp = 0;
    for(int i = 0; i < l; i++){
        f[x[i]]++;
        f[x[i]] += i;
        rasp += suma+((i+1)*(i+2))/2-f[x[i]];
        rasp = rasp % MOD;
        suma += ((i+1)*(i+2))/2-f[x[i]];
        suma = suma % MOD;
    }
    fout << rasp;
    return 0;
}
