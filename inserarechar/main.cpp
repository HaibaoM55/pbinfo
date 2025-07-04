#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("inserarechar.in");
ofstream fout("inserarechar.out");
char x[260];
char cuv[260], c[260];
char vfinal[520];
int l,z,lf=0;
int main(){
    fin >> cuv;
    fin.get();
    fin.getline(x, 260);
    bool ok = false;
    l = strlen(x);
    for(int i = 0; i <= l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            c[z] = x[i];
            z++;
        }else{
            if(z > 0){
                c[z] = 0;
                z = 0;
                if(strcmp(c, cuv)==0){
                    ok=true;
                    vfinal[lf] = '?';
                    lf++;
                }
            }
        }
        vfinal[lf] = x[i];
        lf++;
    }
    if(ok){
        fout << vfinal;
    }else{
        fout << "NU APARE";
    }
    return 0;
}
