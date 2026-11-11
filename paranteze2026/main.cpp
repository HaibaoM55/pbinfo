#include <iostream>
#include <string.h>
using namespace std;
int l = 0;
char x[256];
int main(){
    cin.get(x, 256);
    l = strlen(x);
    int nrl = 0, nrp = 0;
    int rasp = 0;
    for(int i = 0; i <= l; i++){
        if(x[i] == ' ' || x[i] == 0){
            if(nrl == nrp && nrl != 0){
                rasp++;
            }
            nrl = 0;
            nrp = 0;
        }else{
            if('a' <= x[i] && x[i] <= 'z'){
                nrl++;
            }else if(x[i] == '(' || x[i] == ')' || x[i] == '{' || x[i] == '}' || x[i] == '[' || x[i] == ']'){
                nrp++;
            }
        }
    }
    cout << rasp;
    return 0;
}
