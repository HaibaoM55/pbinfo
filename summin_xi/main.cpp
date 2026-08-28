#include <fstream>
using namespace std;
ifstream fin("summin_xi.in");
ofstream fout("summin_xi.out");
int n, s = 0;
int a[104][104];
int main(){
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    for(int j = 1; j <= n; j++){
        int vmin = 2e9;
        for(int i = 1; i <= n; i++){
            vmin = min(vmin, a[i][j]);
        }
        s += vmin;
    }
    fout << s;
    return 0;
}
