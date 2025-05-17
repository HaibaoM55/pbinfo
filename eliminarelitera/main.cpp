#include <iostream>
#include <string.h>
using namespace std;
char x[104], cuv[104];
int n = 0;
int main(){
    cin.get(x, 104);
    int l = strlen(x);
    bool ok = false;
    for(int i = 0; i < l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            n++;
        }else{
            if(n >= 3 && n % 2 == 1){
                ok = true;
                break;
            }
            n = 0;
        }
    }
    if(ok){
        n = 0;
        for(int i = 0; i < l; i++){
            if('a' <= x[i] && x[i] <= 'z'){
                cuv[n]=x[i];
                n++;
            }else{
                cuv[n] = 0;
                if(n >= 3 && n % 2 == 1){
                    for(int i = 0; i < n; i++){
                        if(i == n/2){
                            continue;
                        }
                        cout << cuv[i];
                    }
                }else{
                    cout << cuv;
                }
                cout << ' ';
                n = 0;
            }
        }
        if(n > 0){
            cuv[n] = 0;
            if(n >= 3 && n % 2 == 1){
                for(int i = 0; i < n; i++){
                    if(i == n/2){
                        continue;
                    }
                    cout << cuv[i];
                }
            }else{
                cout << cuv;
            }
            cout << ' ';
            n = 0;
        }
    }else{
        cout << "nu exista";
    }
    return 0;
}
