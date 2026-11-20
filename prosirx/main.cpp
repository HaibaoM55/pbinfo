#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;
ifstream fin("prosirx.in");
ofstream fout("prosirx.out");
int nrc = 0, nrl = 0, nrcuv = 0;
char x[204], c[204];
string cuv[204];
bool estevocala(char x){
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}
int main(){
    fin.get(x, 204);
    int l = strlen(x);
    for(int i = 0; i <= l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            if(!estevocala(x[i])){
                nrc++;
            }
            c[nrl] = x[i];
            if(nrl == 0){
                x[i] = 'X';
            }
            nrl++;
        }else{
            if(nrl != 0){
                c[nrl] = 0;
                nrcuv++;
                cuv[nrcuv] = c; 
                nrl = 0;
            }
        }
    }
    fout << nrc << '\n';
    fout << x << '\n';
    sort(cuv+1, cuv+nrcuv+1);
    for(int i = 1; i <= nrcuv; i++){
        fout << cuv[i] << ' ';
    }
    return 0;
}
