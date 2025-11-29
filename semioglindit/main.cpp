#include <iostream>
#include <string.h>
using namespace std;
char x[267];
int main(){
    cin.get(x, 267);
    int l = strlen(x);
    int start = 0, fin = 0;
    bool ok = false;
    for(int i = 0; i <= l; i++){
        if('a' <= x[i] && x[i] <= 'z'){
            fin = i;
        }else{
            int lcuv = fin-start+1;
            if(lcuv % 2 == 0){
                ok = true;
                int k = lcuv/2;
                for(int j = 1; j <= lcuv/2; j++){
                    swap(x[start+j-1+k], x[start+j-1]);
                }
            }
            start = i+1;
        }
    }
    if(ok){
        cout << x;
    }else{
        cout << "nu exista";
    }
    return 0;
}
