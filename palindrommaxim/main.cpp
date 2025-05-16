#include <iostream>
#include <string.h>
using namespace std;
char x[256];
int n = 0, lmax = 0;
char s[6]=":;., ";
char cuv[256], cmax[256];
int main(){
    cin.get(x, 256);
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        bool estesemn = false;
        for(int j = 0; j <= 4; j++){
            if(x[i] == s[j]){
                estesemn = true;
                break;
            }
        }
        if(estesemn){
            bool estepalindrom = true;
            int z = n;
            for(int j = 1; j < n/2; j++){
                char xj = cuv[j];
                char xz = cuv[z];
                if('A' <= xj && xj <= 'Z'){
                    xj = (xj-'A')+'a';
                }
                if('A' <= xz && xz <= 'Z'){
                    xz = (xz-'A')+'a';
                }
                if(xj != xz){
                    estepalindrom = false;
                    break;
                }
                z--;
            }
            if(estepalindrom && n > lmax){
                lmax = n;
                for(int j = 1; j <= n; j++){
                    cmax[j] = cuv[j];
                }
            }
            n=0;
        }else{
            n++;
            cuv[n] = x[i];
        }
    }
    for(int i = 1; i <= lmax; i++){
        cout << cmax[i];
    }
    return 0;
}
