#include <fstream>
using namespace std;
ifstream fin("mmult.in");
ofstream fout("mmult.out");
int n, x;
int vmax = 0;
int f[1000004];
int nr = 0;
bool exista = true;
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++){
        fin >> x;
        f[x]++;
        vmax = max(x, vmax);
    }
    for(int i = 2; i <= vmax; i++){
        if(f[i] > f[i - 1]) {
            exista = false;
            break;
        }
    }
    if(!exista){
        fout << "-1";
    }else{
        fout << f[1];
    }
    return 0;
}
