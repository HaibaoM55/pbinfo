#include <iostream>
#include <string.h>
using namespace std;
char c[104];
char x[104], y[104];
int main(){
    cin >> c;
    int l = strlen(c);
    for(int i = 0; i < l-1; i++){
        x[i] = c[i];
    }
    for(int i = l-2; i >= 0; i--){
        bool ok = true;
        int z = 0;
        for(int j = l-i-1; j <= l-1; j++){
            y[z] = c[j];
            z++;
        }
        y[z] = 0;
        if(strcmp(y, x)==0){
            cout << x;
            return 0;
        }
        x[i] = 0;
    }
    cout << "nu exista";
    return 0;
}
