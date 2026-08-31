#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char s[14];
bool f[30][30];
bool exista = false;
bool estevocala(char x){
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}
int main(){
    cin >> s;
    int l = strlen(s);
    for(int i = 0; i < l-1; i++){
    	f[s[i]-'a'][s[i+1]-'a'] = true;
    	f[s[i+1]-'a'][s[i]-'a'] = true;
    }
    sort(s, s+l);
    do{
        bool ok = true;
        for(int i = 0; i < l-1; i++){
            if(f[s[i]-'a'][s[i+1]-'a']){
                ok = false;
                break;
            }
        }
        if(ok){
            exista = true;
            cout << s << '\n';
        }
    }while(next_permutation(s, s+l));
    if(!exista){
        cout << "imposibil";
    }
    return 0;
}
