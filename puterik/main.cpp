#include <fstream>
using namespace std;
ifstream fin("puterik.in");
ofstream fout("puterik.out");
int n, k, x;
int f[35];
int z = 0;
int main(){
    fin >> n >> k;
    for(int i = 1; i <= n; i++){
        fin >> x;
        int p = 0;
        while(x % k == 0){
            x = x/k;
            p++;
        }
        if(x == 1){
            f[p]++;
        }
    }
    int p = 1;
    for(int ici = 0; p <= 1e8; ici++){
        while(f[ici]){
            fout << p << ' ';
            f[ici]--;
        }
        p = p*k;
    }
    return 0;
}
