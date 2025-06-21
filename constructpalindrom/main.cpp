#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("constructpalindrom.in");
ofstream fout("constructpalindrom.out");
int t;
char x[100004], y[100004], z[100004];
bool estepalindrom(char fici[100004]){
    int l = strlen(fici);
    int z = l-1;
    for(int i = 0; i <= z; i++){
        if(fici[i] != fici[z]){
            return false;
        }
        z--;
    }
    return true;
}
int main(){
    fin >> t;
    for(int kl = 1; kl <= t; kl++){
        fin >> x;
        int l = strlen(x);
        int z1 = l-1;
        int j=0;
        for(j = 0; j <= z1; j++){
            if(x[j] != x[z1]){
                break;
            }
            z1--;
        }
        int p = 0;
        for(int i = 0; i < l; i++){
            if(i == z1){
                continue;
            }
            y[p] = x[i];
            p++;
        }
        y[p] = 0;

        p = 0;
        for(int i = 0; i < l; i++){
            if(i == j){
                continue;
            }
            z[p] = x[i];
            p++;
        }
        if(estepalindrom(x) || estepalindrom(y) || estepalindrom(z)){
            fout << "YES\n";
        }else{
            fout<<"NO\n";
        }
    }
    return 0;
}
