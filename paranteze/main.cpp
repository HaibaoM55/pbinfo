#include <fstream>
using namespace std;
ifstream fin("paranteze.in");
ofstream fout("paranteze.out");
int n;
int v[24];
void bt(int k){
    if(k == n+1){
        bool ok = true;
        int nr = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == 0){
                nr++;
            }else{
                nr--;
            }
            if(nr < 0){
                ok = false;
            }
        }
        if(nr != 0){
            ok = false;
        }
        if(ok){
            for(int i = 1; i <= n; i++){
                if(v[i] == 0){
                    fout << '(';
                }else{
                    fout << ')';
                }
            }
            fout << '\n';
        }
    }else{
        v[k] = 0;
        bt(k+1);
        v[k] = 1;
        bt(k+1);
    }
}
int main(){
    fin >> n;
    bt(1);
    return 0;
}
