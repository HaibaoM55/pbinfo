#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char x[256];
int nrc = 0;
struct cuvant{
    char s[260];
    int nrap = 0;
}c[260];
char p[260];
int z = 0;
bool compara(cuvant a, cuvant b){
    return strcmp(a.s, b.s) < 0;
}
int main(){
    cin.get(x, 260);
    int l = strlen(x);
    for(int i = 0; i <= l; i++){
        if(x[i] == ' ' || x[i] == 0){
            if(z > 0){
                p[z] = 0;
                bool exista = false;
                bool palindrom = true;
                int zm = z-1;
                for(int j = 0; j < zm; j++){
                    if(p[j] != p[zm]){
                        palindrom = false;
                        break;
                    }
                    zm--;
                }
                if(palindrom){
                    for(int j =1; j <= nrc; j++){
                        if(strcmp(p, c[j].s) == 0){
                            exista = true;
                            c[j].nrap++;
                            break;
                        }
                    }
                    if(!exista){
                        nrc++;
                        c[nrc].nrap = 1;
                        strcpy(c[nrc].s, p);
                    }
                }
                z = 0;
            }
        }else{
            p[z] = x[i];
            z++;
        }
    }
    if(nrc == 0){
        cout <<"nu exista";
    }else{
        sort(c+1, c+nrc+1, compara);
        for(int i = 1; i <= nrc; i++){
            cout << c[i].s << ' ' << c[i].nrap << '\n';
        }
    }
    return 0;
}
