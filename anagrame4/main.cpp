#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char s[14], og[14];
bool estecons(char x){
    return x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u';
}
int main(){
    cin >> og;
    int l = strlen(og);
    int l1 = 0;
    for(int i = 0; i < l; i++){
        if(!estecons(og[i])){
            s[l1] = og[i];
            l1++;
        }

    }
    sort(s, s+l1);
    do{
        int z = 0;
        for(int i = 0; i < l; i++){
            if(estecons(og[i])){
                cout << og[i];
            }else{
                cout << s[z];
                z++;
            }
        }
        cout << '\n';
    }while(next_permutation(s, s+l1));
    return 0;
}
