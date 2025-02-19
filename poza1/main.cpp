#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("poza.in");
ofstream fout("poza.out");
int c, n;
int v[300004];
bool compara(int a, int b){
    if(a > b){
        return true;
    }
    return false;
}
int main()
{
    fin >> c >> n;
    int vmax = 0, vmin = 1000000001;
    for(int i = 1; i <= 3*n; i++){
        fin >> v[i];
        vmax = max(vmax, v[i]);
        vmin = min(vmin, v[i]);
    }
    if(c == 1){
        fout << vmax << ' ' << vmin;
    }else{
        sort(v+1, v+3*n+1, compara);
        for(int j = 3; j >= 1; j--){
            for(int i = n*(j-1)+1; i <= n*j; i++){
                fout << v[i] << ' ';
            }
            fout << '\n';
        }
    }
    return 0;
}
