#include <iostream>
#include <string.h>
using namespace std;
char x[256];
char cuv[256];
int l, z = 0;;
int main(){
    cin >> x;
    l = strlen(x);
    bool inceput = false;
    for(int i = 0; i < l; i++){
        if(x[i] == '('){
            inceput = true;
            z = 0;
            continue;
        }
        if(inceput){
            if(x[i] == ')'){
                inceput = false;
                i++;
                int nr = 0;
                while('0' <= x[i] && x[i] <= '9'){
                    nr = nr*10+(x[i]-'0');
                    i++;
                }
                i--;
                cuv[z] = 0;
                for(int j = 1; j <= nr; j++){
                    cout << cuv;
                }
            }else{
                cuv[z] = x[i];
                z++;
            }
        }else{
            cout << x[i];
        }
    }
    return 0;
}
