#include <fstream>
using namespace std;
ifstream fin("sir6.in");
ofstream fout("sir6.out");
int p, n;
int f, fmax=0;
int v[100004];
int main()
{
    fin >> p >> n;
    f = 1;
    fin >> v[1];
    for(int i = 2; i <= n; i++){
        fin >> v[i];
        if(v[i] == v[i-1]){
            f++;
        }else{
            if(p == 2){
                fout <<  v[i-1] << ' ' << f << ' ';
            }
            f = 1;
        }
        if(p == 1){
            fmax = max(fmax, f);
        }
    }
    if(p == 1){
        fout << fmax;
    }else{
        fout << v[n] << ' ' << f;
    }
    return 0;
}
