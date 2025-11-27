#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char x[167];
char vocale[8] = "aeiou";
char voc[167];
int nrv;
bool estevocala[167];
int main(){
    cin >> x;
    int l =strlen(x);
    for(int i = 0; i < l; i++){
        if(strchr(vocale, x[i]) != 0){
            nrv++;
            voc[nrv] = x[i];
            estevocala[i] = true;
        }else{
            estevocala[i] = false;
        }
    }
    sort(voc+1, voc+nrv+1);
    for(int i = 0; i < l; i++){
        if(estevocala[i]){
            cout << voc[nrv];
            nrv--;
        }else{
            cout << x[i];
        }
    }
    return 0;
}
