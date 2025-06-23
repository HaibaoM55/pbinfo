#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("sir_eval.in");
ofstream fout("sir_eval.out");
char deeznutz[50];
char var[50];
bool esteplus=false;
int nr1, nr2;
int main(){
    fin >> deeznutz;
    int l = strlen(deeznutz);
    int i;
    for(i = 0; i < l; i++){
        if(deeznutz[i] == '='){
            var[i] = 0;
            break;
        }
        var[i] = deeznutz[i];
    }
    fout << var << '=';
    i++;
    bool facnr2=false;
    for(i; i < l; i++){
        if('0' <= deeznutz[i] && deeznutz[i] <= '9'){
            if(facnr2){
                nr2 = nr2*10+deeznutz[i]-'0';
            }else{
                nr1 = nr1*10+deeznutz[i]-'0';
            }
        }else{
            if(deeznutz[i] == '+'){
                esteplus=true;
            }else{
                esteplus=false;
            }
            facnr2 = true;
        }
    }
    if(esteplus){
        fout << nr1+nr2;
    }else{
        fout << 1LL*nr1*nr2;
    }
    return 0;
}
