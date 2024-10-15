#include <fstream>
#include <string.h>
using namespace std;
ifstream fein("nrsufix.in");
ofstream fout("nrsufix.out");
char p[11], x[11], c[11]="nu exista";
int main()
{
    fein >> p;
    int s = strlen(p);
    while(fein >> x){
        int l = strlen(x);
        int z = 0;
        if(l >= s){
            bool ok = true;
            for(int i = l-s; i < l; i++){
                if(x[i] != p[z]){
                    ok=false;
                    break;
                }
                z++;
            }
            if(ok){
                strcpy(c, x);
            }
        }
    }
    fout << c;
    return 0;
}
