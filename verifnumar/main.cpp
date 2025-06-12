#include <iostream>
#include <string.h>
using namespace std;
int nr[100];
int zeroult = -1, nrc;
bool amcifrenenule = false;
int main(){
    char s[101];
    cin.get(s , 101);
    int l = strlen(s);
    for(int i = 0; i < l; i++){
        if(s[i] == '0'){
            if(!amcifrenenule){
                nr[i] = 1;
                zeroult = i;
                nrc++;
            }
        }else{
            if(s[i] > '0' && s[i] <= '9'){
                amcifrenenule = 1;
            }else{
                nr[i] = 1;
                nrc++;
            }
        }
    }
    if(!amcifrenenule && zeroult != -1){
        nr[zeroult] = 0;
        nrc--;
    }
    if(nrc == 0){
        cout << "CORECT";
    }else{
        if(!amcifrenenule && zeroult == -1){
            cout << "NaN";
        }else{
            for(int i = 0; s[i]; i ++){
                if(nr[i] == 0){
                    cout << s[i];
                }
            }
            cout << '\n';
            for(int i = 0 ; i < l && s[i]; i++){
                if(nr[i] == 1 && s[i] != ' '){
                    cout << s[i] << ' ';
                }
            }
        }
    }
    return 0;
}
