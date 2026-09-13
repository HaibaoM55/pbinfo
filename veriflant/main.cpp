#include <fstream>
using namespace std;
ifstream fin("veriflant.in");
ofstream fout("veriflant.out");
int n, m, x, y, q, l;
bool b[104][104];
bool viz[104];
int v[204];
int main(){
    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        b[x][y] = true;
        b[y][x] = true;
    }
    fin >> q;
    for(int i = 1; i <= q; i++){
        fin >> l;
        bool ok = true, elm = true;
        for(int j = 1; j <= l; j++){
            fin >> v[j];
            if(viz[v[j]]){
                elm = false;
            }
            viz[v[j]] = true;
            if(j > 1){
                if(!b[v[j]][v[j-1]]){
                    ok = false;
                }
            }
        }
        for(int j = 1; j <= n; j++){
            viz[j] = false;
        }
        if(ok){
            if(elm){
                fout << "ELEMENTAR";
            }else{
                fout << "NEELEMENTAR";
            }
        }else{
            fout << "NU";
        }
        fout << '\n';
    }
    return 0;
}
