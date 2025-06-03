#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("email.in");
ofstream fout("email.out");
char x[54];
struct str{
    char x[54];
    int nrap;
}email[204];
int nre=0,l;
bool compara(str x, str y){
    if(x.nrap == y.nrap){
        return strcmp(x.x, y.x) < 0;
    }
    return x.nrap > y.nrap;
}
int main(){
    while(fin.get(x, 54)){
        fin.get();
        l = strlen(x);
        int j;
        for(j = 0; j < l; j++){
            if(x[j]=='@'){
                break;
            }
        }
        j++;
        int oj = j;
        char cuv[54];
        for(j; j < l; j++){
            cuv[j-oj]=x[j];
        }
        cuv[l-oj] = 0;
        bool exista = false;
        for(int i = 1; i <= nre; i++){
            if(strcmp(cuv, email[i].x)==0){
                email[i].nrap++;
                exista = true;
                break;
            }
        }
        if(!exista){
            nre++;
            email[nre].nrap =1;
            strcpy(email[nre].x, cuv);
        }
    }
    fout << nre << '\n';
    sort(email+1, email+nre+1, compara);
    for(int i = 1; i <= nre; i++){
        fout << email[i].x << ' ' << email[i].nrap << '\n';
    }
    return 0;
}
