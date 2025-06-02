#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
char x[256];
char c[256];
struct strg{
    char x[256];
    int valoare = 0, i;
}v[256];
bool compara(strg a, strg b){
    if(a.valoare < b.valoare){
        return true;
    }else if(a.valoare == b.valoare){
        return a.i < b.i;
    }
    return false;
}
int main(){
    cin.get(x, 256);
    int l = strlen(x);
    int z = 0, nr = 0;
    for(int i = 0; i <= l; i++){
        if(x[i] == ' ' || x[i] == 0){
            c[z] = 0;
            bool mergef = false;
            int rez = 0;
            for(int j = 0; j < z; j++){
                rez += (int)c[j];
                if('a' <= c[j] && c[j] <= 'z'){
                    mergef = true;
                }
                if('A' <= c[j] && c[j] <= 'Z'){
                    mergef = true;
                }
            }
            if(mergef){
                nr++;
                strcpy(v[nr].x, c);
                v[nr].valoare = rez;
                v[nr].i = i;
            }
            z = 0;
        }else{
            c[z] = x[i];
            z++;
        }
    }
    sort(v+1, v+nr+1, compara);
    int nrv = 0;
    if(nr == 0){
        cout << "NU EXISTA";
    }
    for(int i = 1; i <= nr; i++){
        if(nrv != v[i].valoare){
            if(i > 1){
                cout << '\n';
            }
            cout <<v[i].valoare << ' ';
        }
        cout << v[i].x << ' ';
        nrv = v[i].valoare;
    }
    return 0;
}
