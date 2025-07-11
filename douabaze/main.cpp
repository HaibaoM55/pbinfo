#include <iostream>
#include <string.h>
using namespace std;
char cif[104];
int cif2[104];
int main(){
    cin >> cif;
    int l = strlen(cif);
    int pw = l-1;
    for(int i = 0; i < l; i++){
        if(cif[i]=='1'){
            if(pw % 2 != 0){
                cif2[pw/2]+=2;
            }else{
                cif2[pw/2]++;
            }
        }
        pw--;
    }
    bool inceput = false;
    for(int i = l/2; i >= 0; i--){
        if(cif2[i] != 0){
            inceput = true;
        }
        if(inceput){
            cout << cif2[i];
        }
    }
    return 0;
}
