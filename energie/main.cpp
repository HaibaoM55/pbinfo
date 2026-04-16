#include <fstream>
#include <map>
using namespace std;
ifstream fin("energie.in");
ofstream fout("energie.out");
int q;
int n, r;
int rasp(int x){
    int nrp = 0;
    while(x){
        nrp++;
        if(x % 2 == 1){
            nrp++;
        }
        x = x/2;
    }
    return nrp-1;
}
int f[67][41];
map<int, int> log2;
int main(){
    f[0][0] = 1;
    for(int i = 1; i <= 30; i++){
        f[i][0] = 1;
        f[i][i] = 1;
        for(int j = 1; j < i; j++){
            f[i][j] = f[i-1][j]+f[i-1][j-1];
        }
    }
    int j = 1;
    for(int i = 0; i <= 30; i++){
        log2[j] = i;
        j = j*2;
    }
    fin >> q;
    while(q){
        fin >> n >> r;
        int nr=0;
        for(int l = 0; l < log2[n]; l++){
            for(int b = 0; b <= l; b++){
                if(b+l >= r){
                    nr += f[l][b];
                }
            }
        }
        if(log2[n] >= r){
            nr++;
        }
        fout << nr << '\n';
        q--;
    }
    return 0;
}
