#include <fstream>
#include <bitset>
using namespace std;
ofstream fout("colectie.out");
ifstream fin("colectie.in");
int n, x;
bitset<18000004> f;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(f[x*2]){
            f[x*2+1] = true;
        }else{
            f[x*2] = true;
        }
    }
    int nr = 0;
    for(int i = 1; i <= n; i++){
        if(f[i*2] && !f[i*2+1]){
            nr++;
        }
    }
    fout << nr;
    return 0;
}
