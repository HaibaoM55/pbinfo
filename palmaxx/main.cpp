#include <iostream>
#include <string.h>
using namespace std;
char x[104], cuv[104];
int vmax = 0;
char cuvmax[104];
int main(){
    cin >> x;
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        for(int j = i; j < l; j++){
            cuv[j-i] = x[j];
            bool estepalindrom = true;
            int z = j-i;
            for(int k = 0; k <= j-i; k++){
                if(cuv[k] != cuv[z]){
                    estepalindrom = false;
                    break;
                }
                z--;
            }
            cuv[j-i+1] = 0;
            if(estepalindrom){
                if(j-i+1 > vmax){
                    vmax = j-i+1;
                    strcpy(cuvmax, cuv);
                }else if(j-i+1 == vmax){
                    if(strcmp(cuvmax, cuv) > 0){
                        strcpy(cuvmax, cuv);
                    }
                }
            }
        }
    }
    cout << cuvmax;
    return 0;
}
