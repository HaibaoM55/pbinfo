#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream fin("sirpie.in");
ofstream fout("sirpie.out");
int n;
int v[16];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> v[i];
    }
    sort(v+1, v+n+1);
    do{
        bool ok = true;
        for(int i = 1; i < n; i++){
            if(__gcd(v[i], v[i+1]) != 1){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i = 1; i <= n; i++){
                fout << v[i] << ' ';
            }
            fout << '\n';
        }
    }while(next_permutation(v+1, v+n+1));
    return 0;
}
