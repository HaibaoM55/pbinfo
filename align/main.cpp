#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("align.in");
ofstream fout("align.out");
int n;
char t;
char x[104][204];
int main(){
    fin >> n >> t;
    fin.get();
    for(int i = 1; i <= n; i++){
        fin.get(x[i], 204);
        fin.get();
    }
    if(t == 'S'){
        for(int i = 1; i <= n; i++){
            int l = strlen(x[i]);
            bool ok = true;
            for(int j = 0; j < l; j++){
                if(x[i][j] != ' ' || ok == false){
                    ok = false;
                    fout << x[i][j];
                }
            }
            fout << '\n';
        }
    }else{
        int lmax =0;
        for(int i = 1; i <= n; i++){
            int l = strlen(x[i]);
            lmax = max(l, lmax);
        }
        for(int i = 1; i <= n; i++){
            int l = strlen(x[i]);
            for(int j = 1; j <= lmax-l; j++){
                fout << ' ';
            }
            fout << x[i] << '\n';
        }
    }
    return 0;
}
