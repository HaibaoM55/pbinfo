#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("fraze.in");
ofstream fout("fraze.out");
char x[266];
int f[30], nrp = 0, nrpp=0;
struct str{
    char x[266];
};
str fici[104];
bool compara(str a, str b){
    return strcmp(a.x, b.x) < 0;
}
int main(){
    while(fin.get(x, 260)){
        fin.get();
        int l = strlen(x);
        for(int i = 0; i < 26; i++){
            f[i] = 0;
        }
        for(int i = 0; i < l; i++){
            if('a' <= x[i] && x[i] <= 'z'){
                f[x[i]-'a']++;
            }else if('A' <= x[i] && x[i] <= 'Z'){
                f[x[i]-'A']++;
            }
        }
        bool pangram=true;
        bool pangram_perfect=true;
        for(int i = 0; i < 26; i++){
            if(f[i]==0){
                pangram=false;
                pangram_perfect=false;
                break;
            }
            if(f[i] > 1){
                pangram_perfect = false;
            }
        }
        if(pangram){
            nrp++;
            strcpy(fici[nrp].x, x);
        }
        if(pangram_perfect){
            nrpp++;
        }
    }
    fout << nrp << ' ' << nrpp << '\n';
    sort(fici+1, fici+nrp+1, compara);
    for(int i = 1; i <= nrp; i++){
        fout << fici[i].x << '\n';
    }
    return 0;
}
