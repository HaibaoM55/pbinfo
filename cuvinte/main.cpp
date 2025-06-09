#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char x[540];
char s[20];
int nrc = 0;
struct cuv{
    char c[20];
    int nrap = 1;
}a[204];
bool compara(cuv a, cuv b){
    return strcmp(a.c, b.c) < 0;
}
int main(){
    cin.get(x, 500);
    int l = strlen(x);
    int z = 0;
    for(int i = 0; i <= l; i++){
        if(x[i] != ' ' && x[i] != 0){
            s[z] = x[i];
            z++;
        }else{
            if(z > 0){
                s[z] = 0;
                bool exista = false;
                for(int i = 1; i <= nrc; i++){
                    if(strcmp(s, a[i].c) == 0){
                        exista = true;
                        a[i].nrap++;
                        break;
                    }
                }
                if(!exista){
                    nrc++;
                    strcpy(a[nrc].c, s);
                    a[nrc].nrap = 1;
                }
                z = 0;
            }
        }
    }
    sort(a+1, a+nrc+1, compara);
    for(int i = 1; i <= nrc; i++){
        cout << a[i].c << ' ' << a[i].nrap << '\n';
    }
    return 0;
}
