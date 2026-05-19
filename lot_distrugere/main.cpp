#include <fstream>
#include <bitset>
#include <algorithm>
using namespace std;
ifstream fin("distrugere.in");
ofstream fout("distrugere.out");
int n;
int v[1000004];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    int nrpmax = 0;
    for(int i = 1; i <= n; i++){
        int nrp = 0;
        for(int j = 1; j <= n; j++){
            if(__gcd(v[i], v[j]) == 1){
                nrp++;
            }
        }
        nrpmax = max(nrpmax, nrp);
    }
    fout << nrpmax;
    return 0;
}
