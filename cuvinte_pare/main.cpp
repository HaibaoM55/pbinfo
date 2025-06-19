#include <iostream>
#include <string.h>
using namespace std;
char x[104], cuv[104];
int zc = 0;
int z = 0;
char y[104];
int main(){
    cin.get(x, 104);
    int l = strlen(x);
    bool ok = false;
    for(int i = 0; i <= l; i++){
        if(x[i] == ' ' || x[i] == 0){
            if(zc % 2 == 0){
                y[z] = '#';
                z++;
                ok = true;
            }else{
                for(int j = 0; j < zc; j++){
                    y[z] = cuv[j];
                    z++;
                }
            }
            y[z] = x[i];
            z++;
            zc = 0;
        }else{
            cuv[zc] = x[i];
            zc++;
        }
    }
    y[z] = 0;
    if(ok){
        cout << y;
    }else{
        cout << "nu exista";
    }
    return 0;
}
