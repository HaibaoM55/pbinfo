#include <fstream>
using namespace std;
ifstream fin("lungime.in");
ofstream fout("lungime.out");
int n, x;
int f[104];
int vmax = 0;
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        if(f[x] == 0){
            f[x] = i;
        }
        vmax = max(vmax, i-f[x]+1);
    }
    fout << vmax;
    return 0;
}
