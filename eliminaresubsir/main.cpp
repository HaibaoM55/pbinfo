#include <iostream>
#include <string.h>
using namespace std;
char s[256];
char t[256];
int main(){
    cin.get(s, 256);
    cin.get();
    cin.get(t, 256);
    int l1 = strlen(t);
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        bool ok = false;
        if(i < l-l1+1){
            for(int j = i; j <=i+l1-1; j++){
                if(s[j] != t[j-i]){
                    ok = true;
                    break;
                }
            }
        }else{
            ok = true;
        }
        if(ok){
            cout << s[i];
        }else{
            i += l1-1;
        }
    }
    return 0;
}
