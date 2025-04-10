#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("furnici1.in");
ofstream fout("furnici1.out");
int l, n;
int fmax =0;
int main(){
    fin >> l >> n;
    for(int i = 1; i <= n; i++){
        int x;
        char dir;
        fin >> x >> dir;
        if(dir == 'S'){
            fmax = max(fmax, x);
        }else{
            fmax = max(fmax, l-x);
        }
    }
    fout << fmax;
    return 0;
}
