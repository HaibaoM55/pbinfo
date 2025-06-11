#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,z = 0;
char x[266];
char cuv[14];
bool compara(char a, char b){
    return a > b;
}
int main(){
    cin.get(x, 260);
    cin.get();
    int l = strlen(x);
    for(int i = 0; i <= l; i++){
        if(x[i] == ' ' || x[i] == 0){
            if(z > 0){
                cuv[z] = 0;
                sort(cuv, cuv+z, compara);
                cout << cuv << '\n';
                z = 0;
            }
        }else{
            cuv[z] = x[i];
            z++;
        }
    }
    return 0;
}
