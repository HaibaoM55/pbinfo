#include <fstream>
using namespace std;
ifstream fin("lincol.in");
ofstream fout("lincol.out");
int n, m, x;
int lin[104], col[104];
int q;
char c;
int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fin >> x;
            lin[i] += x;
            col[j] += x;
        }
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> c >> x;
        if(c == 'L'){
            fout << lin[x];
        }else{
            fout << col[x];
        }
        fout << '\n';
    }
    return 0;
}
