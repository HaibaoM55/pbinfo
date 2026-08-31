#include <fstream>
using namespace std;
ifstream fin("plopi2.in");
ofstream fout("plopi2.out");
int n, nr=0, nrt=0;
int v[104];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    for(int i = 2; i <= n; i++){
        if(v[i] > v[i-1]){
            nr++;
            nrt += v[i]-v[i-1];
            v[i] = v[i-1];
        }
    }
    fout << nr << ' ' << nrt;
    return 0;
}
