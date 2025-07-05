#include <string.h>
#include <iostream>
using namespace std;
void ReverseWords(char s[]){
    int l = strlen(s);
    int z = l-1;
    for(int i = 0; i <= z; i++){
        char aux = s[i];
        s[i] = s[z];
        s[z] = aux;
        z--;
    }
    z = 0;
    int lgm = 0;
    for(int i = 0; i <= l; i++){
        if('a' <= s[i] && s[i] <= 'z'){
            z++;
        }else{
            if(z > 0){
                int z1 = i-1;
                int z2 = i-z;
                while(z1 >= z2){
                    char aux = s[z1];
                    s[z1] = s[z2];
                    s[z2] = aux;
                    z2++;
                    z1--;
                }
                z = 0;
            }
        }
    }
    cout << s;
}
/*
int main(){
    char x[] = "goon sleep eat repeat";
    ReverseWords(x);
}
*/
