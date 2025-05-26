#include <iostream>
#include <string.h>
using namespace std;
char x[104];
char c[104];
int z = 0;
int main(){
    cin.get(x, 104);
    int l = strlen(x);
    for(int i = 0; i < l; i++){
        if(x[i] == ' '){
            c[z] = 0;
            if(z > 0){
                bool ok = true;
                for(int j = 0; j < z-1; j++){
                    if(c[j] == '.'){
                        if('1' <= c[j+1] && c[j+1] <= '9'){
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok){
                    cout << c;
                }
            }
            cout << ' ';
            z = 0;
        }else{
            c[z] = x[i];
            z++;
        }
    }
    return 0;
}
