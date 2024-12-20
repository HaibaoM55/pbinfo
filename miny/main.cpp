#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("miny.in");
ofstream fout("miny.out");
int n;
int x[50005];
bool ciur[10004];
int prm[10004];
int e[10004];
int nrp = 0;
long long z;
int main()
{
    fin >> n;
    for(int i = 2; i <= 10000; i++){
        if(ciur[i] == false){
            nrp++;
            prm[nrp] = i;
            for(int j = i; j*i <= 10000; j++){
                ciur[j*i] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        fin >> x[i];
        if(i > 1){
            z = z * x[i];
            z = z % 100;
        }else{
            z = x[i];
            z = z % 100;
        }
        for(int j = 1; j <= nrp && prm[j] <= x[i]; j++){
            while(x[i] % prm[j] == 0){
                x[i] = x[i]/prm[j];
                e[j]++;
            }
        }
    }
    fout << z/10 << '\n';
    int nr = 0;
    int g = -1;
    for(int i = 1; i <= nrp; i++){
        if(e[i] > 0){
            if(g == -1){
                g = e[i];
            }else{
                g = __gcd(g, e[i]);
            }
            nr++;
        }
    }
    fout << nr << '\n';
    for(int i = 1; i <= nrp; i++){
        if(e[i] > 0){
            fout << prm[i] << ' ' << e[i]/g << '\n';
        }
    }
    return 0;
}
